/*
 * SensorController.h
 *
 *  Created on: 24.01.2015
 *      Author: furylynx
 */

#ifndef SENSORCONTROLLER_H_
#define SENSORCONTROLLER_H_

//custom includes
//...


//global includes
#include <FUix.h>
#include <FBase.h>

#include <sstream>



class SensorController :
	public Osp::Uix::ISensorEventListener
{
public:
	SensorController();
	virtual ~SensorController();

	virtual void Construct();

	virtual void OnDataReceived(Osp::Uix::SensorType sensor_type, Osp::Uix::SensorData& sensor_data, result r);

	virtual float CalculateAngle(float f1, float f2) const;


protected:
	virtual bool RegisterSensor(Osp::Uix::SensorType sensor_type);

private:
	Osp::Uix::SensorManager sensor_manager_;

};

#endif /* SENSORCONTROLLER_H_ */
