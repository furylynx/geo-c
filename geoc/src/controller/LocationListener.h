/*
 * LocationListener.h
 *
 *  Created on: 27.01.2015
 *      Author: John
 */

#ifndef LOCATIONLISTENER_H_
#define LOCATIONLISTENER_H_


#include <FLocations.h>

class LocationListener :
	public Osp::Locations::ILocationListener
{
public:
	LocationListener();
	virtual ~LocationListener();

	virtual void  OnLocationUpdated (Osp::Locations::Location &location);
	virtual void  OnProviderStateChanged (Osp::Locations::LocProviderState newState);

};

#endif /* LOCATIONLISTENER_H_ */
