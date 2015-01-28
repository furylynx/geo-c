/*
 * SensorController.cpp
 *
 *  Created on: 24.01.2015
 *      Author: furylynx
 */

#include "SensorController.h"

namespace geo
{

SensorController::SensorController()
{

}

SensorController::~SensorController()
{

}

void SensorController::Construct()
{
	//construct the sensor manager
	sensorManager_.Construct();

	bool result = RegisterSensor(Osp::Uix::SENSOR_TYPE_TILT);
	result &= RegisterSensor(Osp::Uix::SENSOR_TYPE_MAGNETIC);
	result &= RegisterSensor(Osp::Uix::SENSOR_TYPE_GPS);


	locationProvider_.Construct(Osp::Locations::LOC_METHOD_GPS);

	if (locationProvider_.IsLocationMethodSupported(Osp::Locations::LOC_METHOD_GPS))
	{
		std::stringstream sstrapploglocationmanager;
		sstrapploglocationmanager << "LocState: " << locationProvider_.GetState();
		AppLog(sstrapploglocationmanager.str().c_str());

//		for (std::list<geo::ISensorUpdateListener*>::iterator it = sensorUpdateListeners_.begin(); it != sensorUpdateListeners_.end(); it++)
//		{
//			(*it)->OnLocatorStateChanged(locationProvider_.GetState());
//		}

		//TODO this causes a app crash - I dont know why !!
		locationProvider_.RequestLocationUpdates(*this, 4, false);
	}


}

void SensorController::OnDataReceived(Osp::Uix::SensorType sensor_type, Osp::Uix::SensorData& sensor_data, result r)
{

	if (sensor_type == Osp::Uix::SENSOR_TYPE_TILT)
	{
		float pitch=0.0f, azimuth=0.0f, roll=0.0f;

		sensor_data.GetValue((Osp::Uix::SensorDataKey)Osp::Uix::TILT_DATA_KEY_PITCH, pitch);

		sensor_data.GetValue((Osp::Uix::SensorDataKey)Osp::Uix::TILT_DATA_KEY_AZIMUTH, azimuth);
		sensor_data.GetValue((Osp::Uix::SensorDataKey)Osp::Uix::TILT_DATA_KEY_ROLL, roll);

		std::stringstream sstr;
		sstr << "OnDataReceived-TILT: " << pitch << " " << azimuth << " " << roll << std::endl;

		AppLog(sstr.str().c_str());

		for (std::list<geo::ISensorUpdateListener*>::iterator it = sensorUpdateListeners_.begin(); it != sensorUpdateListeners_.end(); it++)
		{
			(*it)->OnTiltUpdate(azimuth, pitch, roll);
		}
	}
	else if (sensor_type == Osp::Uix::SENSOR_TYPE_MAGNETIC)
	{
		float x=0.0f, y=0.0f, z=0.0f;

		sensor_data.GetValue((Osp::Uix::SensorDataKey)Osp::Uix::MAGNETIC_DATA_KEY_X, x);
		sensor_data.GetValue((Osp::Uix::SensorDataKey)Osp::Uix::MAGNETIC_DATA_KEY_Y, y);
		sensor_data.GetValue((Osp::Uix::SensorDataKey)Osp::Uix::MAGNETIC_DATA_KEY_Z, z);

		// Calculate the length of our vector determined by the three axis
		float mag_field = Osp::Base::Utility::Math::Sqrt((Osp::Base::Utility::Math::Pow(x,2)+ Osp::Base::Utility::Math::Pow(y,2)+ Osp::Base::Utility::Math::Pow(z,2)));

		std::stringstream sstr;
		sstr << "OnDataReceived-MAG: " << mag_field << std::endl;

		AppLog(sstr.str().c_str());

		float degreesToNorth = 0.0f;

		//TODO calculate the degree to north direction!

		AppLog(""+sensorUpdateListeners_.size());
		int count = 0;
		for (std::list<geo::ISensorUpdateListener*>::iterator it = sensorUpdateListeners_.begin(); it != sensorUpdateListeners_.end(); it++)
		{
			count++;
			AppLog(""+count);
			(*it)->OnMagneticUpdate(degreesToNorth, x, y, z);
		}
	}
	else if (sensor_type == Osp::Uix::SENSOR_TYPE_GPS)
	{
		float longitude,latitude;

		sensor_data.GetValue((Osp::Uix::SensorDataKey)Osp::Uix::GPS_DATA_KEY_LONGITUDE, longitude);
		sensor_data.GetValue((Osp::Uix::SensorDataKey)Osp::Uix::GPS_DATA_KEY_LATITUDE, latitude);

		std::stringstream sstr;
		sstr << "OnDataReceived-GPS: " << latitude << " " << longitude << std::endl;

		AppLog(sstr.str().c_str());

		for (std::list<geo::ISensorUpdateListener*>::iterator it = sensorUpdateListeners_.begin(); it != sensorUpdateListeners_.end(); it++)
		{
			(*it)->OnGPSUpdate(longitude, latitude);
		}
	}

}

void SensorController::OnLocationUpdated(Osp::Locations::Location& location)
{
	for (std::list<geo::ISensorUpdateListener*>::iterator it = sensorUpdateListeners_.begin(); it != sensorUpdateListeners_.end(); it++)
	{
		(*it)->OnLocationUpdate(location);
	}
}

void SensorController::OnProviderStateChanged(Osp::Locations::LocProviderState  newState)
{
	for (std::list<geo::ISensorUpdateListener*>::iterator it = sensorUpdateListeners_.begin(); it != sensorUpdateListeners_.end(); it++)
	{
		(*it)->OnLocatorStateChanged(newState);
	}
}

float SensorController::CalculateAngle(float f1, float f2) const
{
	float angle = 0;

	// angle in degree
	if (f1==0 && f2==0)
	{
		angle = 0;
	}
	else
	{
		angle = Osp::Base::Utility::Math::Abs(Osp::Base::Utility::Math::Asin(f1 / Osp::Base::Utility::Math::Sqrt((Osp::Base::Utility::Math::Pow(f1,2) + Osp::Base::Utility::Math::Pow(f2,2)))) * 180/Osp::Base::Utility::Math::GetPi());
	}

	return angle;
}

bool SensorController::RegisterSensor(Osp::Uix::SensorType sensor_type)
{
	//register the this class as a listener for the sensor data


	// Check that the proximity sensor is available
	if (sensorManager_.IsAvailable(sensor_type))
	{
		//register the tilt sensor
		long min_interval = 0, max_interval = 0;
		sensorManager_.GetMinInterval(sensor_type, min_interval);
		sensorManager_.GetMaxInterval(sensor_type, max_interval);

		unsigned long r = sensorManager_.AddSensorListener(*this, sensor_type, min_interval, true);

		if (!IsFailed(r))
		{
			return true;
		}
	}

	std::stringstream sstr;
	sstr << sensor_type <<  " sensor is not available!" << std::endl;

	AppLogException(sstr.str().c_str());
	return false;
}

bool SensorController::RegisterLocationProvider()
{
	//register the this class as a listener for the location data

//	unsigned long r = locationProvider_.RequestLocationUpdates(*this, 20, false);
//
//	if (!IsFailed(r))
//	{
//		return true;
//	}
//
//	std::stringstream sstr;
//	sstr << "Location provider is not available!" << std::endl;
//
//	AppLog(sstr.str().c_str());
	return false;
}

void SensorController::Pause()
{
	if (!paused_)
	{
		locationProvider_.CancelLocationUpdates();

		//TODO pause other sensors

		paused_ = true;
	}
}

void SensorController::Resume()
{
	if (paused_)
	{
		RegisterLocationProvider();

		//TODO resume other sensors

		paused_ = false;
	}
}

float SensorController::Distance(float longitude1, float latitude1, float longitude2, float latitude2) const
{
	//earth radius in m
	const float R = 6371000.8;

	float phi1 = ToRad(latitude1);
	float phi2 = ToRad(latitude2);
	float deltaPhi = ToRad(latitude2 - latitude1);
	float deltaLambda = ToRad(longitude2 - longitude1);

	float a = Osp::Base::Utility::Math::Sin(deltaPhi/2) * Osp::Base::Utility::Math::Sin(deltaPhi/2) + Osp::Base::Utility::Math::Cos(phi1) * Osp::Base::Utility::Math::Cos(phi2) * Osp::Base::Utility::Math::Sin(deltaLambda/2) * Osp::Base::Utility::Math::Sin(deltaLambda/2);
	float c = 2 * std::atan2(Osp::Base::Utility::Math::Sqrt(a), Osp::Base::Utility::Math::Sqrt(1-a));

	float d = R * c;

	return d;
}

float SensorController::ToRad(float angleInDegree) const
{
	const float PI = 3.14159265;

	return angleInDegree * PI/180;
}

void SensorController::RegisterSensorUpdateListener(ISensorUpdateListener* listener)
{
	sensorUpdateListeners_.push_back(listener);

//	listener->OnLocatorStateChanged(locationProvider_.GetState());
}

}//namespace geo
