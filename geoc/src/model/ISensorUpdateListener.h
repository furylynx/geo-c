/*
 * ISensorUpdateListener.h
 *
 *  Created on: 25.01.2015
 *      Author: furylynx
 */

#ifndef ISENSORUPDATELISTENER_H_
#define ISENSORUPDATELISTENER_H_

//custom includes
//...


//global includes
#include <FLocations.h>

namespace geo
{

class ISensorUpdateListener
{
public:
	virtual ~ISensorUpdateListener(){}

	virtual void OnLocationUpdate(Osp::Locations::Location& location) = 0;
	virtual void OnLocatorStateChanged(Osp::Locations::LocProviderState newState) = 0;

	virtual void OnGPSUpdate(float longitude, float latitude) = 0;
	virtual void OnTiltUpdate(float azimuth, float pitch, float roll) = 0;
	virtual void OnMagneticUpdate(float degreesToNorth, float x, float y, float z) = 0;


};


}//namespace geo

#endif /* ISENSORUPDATELISTENER_H_ */
