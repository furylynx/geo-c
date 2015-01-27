/*
 * SensorController.h
 *
 *  Created on: 24.01.2015
 *      Author: furylynx
 */

#ifndef SENSORCONTROLLER_H_
#define SENSORCONTROLLER_H_

//custom includes
#include "../model/ISensorUpdateListener.h"

//TODO remove
#include "LocationListener.h"

//global includes
#include <FUix.h>
#include <FBase.h>
#include <FLocations.h>


#include <sstream>
#include <cmath>
#include <list>

namespace geo
{

class SensorController :
	public Osp::Uix::ISensorEventListener,
	public Osp::Locations::ILocationListener
{
public:
	SensorController();
	virtual ~SensorController();

	virtual void Construct();


	virtual float CalculateAngle(float f1, float f2) const;

	virtual void Pause();

	virtual void Resume();

	virtual float Distance(float longitude1, float latitude1, float longitude2, float latitude2) const;

	virtual float ToRad(float angleInDegree) const;

	virtual void RegisterSensorUpdateListener(ISensorUpdateListener* listener);



	//callbacks

	virtual void OnDataReceived(Osp::Uix::SensorType sensor_type, Osp::Uix::SensorData& sensor_data, result r);

	virtual void OnLocationUpdated(Osp::Locations::Location& location);

	virtual void OnProviderStateChanged(Osp::Locations::LocProviderState  newState);




protected:
	virtual bool RegisterSensor(Osp::Uix::SensorType sensor_type);

	virtual bool RegisterLocationProvider();

private:
	Osp::Uix::SensorManager sensorManager_;
	Osp::Locations::LocationProvider locationProvider_;

	bool paused_;

	std::list<geo::ISensorUpdateListener*> sensorUpdateListeners_;

	//TODO remove
	LocationListener ll_;
};

}//namespace geo

#endif /* SENSORCONTROLLER_H_ */
