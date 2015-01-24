/*
 * SensorController.cpp
 *
 *  Created on: 24.01.2015
 *      Author: furylynx
 */

#include "SensorController.h"

SensorController::SensorController()
{

}

SensorController::~SensorController()
{

}

void SensorController::Construct()
{
	//construct the sensor manager
	sensor_manager_.Construct();

	bool result = RegisterSensor(Osp::Uix::SENSOR_TYPE_TILT);
	result &= RegisterSensor(Osp::Uix::SENSOR_TYPE_MAGNETIC);
	//result &= RegisterSensor(Osp::Uix::SENSOR_TYPE_GPS);
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
		sstr << "OnDataReceived: " << pitch << " " << azimuth << " " << roll << std::endl;

		AppLog(sstr.str().c_str());


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
		sstr << "OnDataReceived[mag_field]: " << mag_field << std::endl;

		AppLog(sstr.str().c_str());

	}

	//TODO notify forms

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
	if (sensor_manager_.IsAvailable(sensor_type))
	{
		//register the tilt sensor
		long min_interval = 0, max_interval = 0;
		sensor_manager_.GetMinInterval(sensor_type, min_interval);
		sensor_manager_.GetMaxInterval(sensor_type, max_interval);

		unsigned long r = sensor_manager_.AddSensorListener(*this, sensor_type, min_interval, true);

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
