/*
 * LocationListener.cpp
 *
 *  Created on: 27.01.2015
 *      Author: John
 */

#include "LocationListener.h"

LocationListener::LocationListener() {
	// TODO Auto-generated constructor stub

}

LocationListener::~LocationListener() {
	// TODO Auto-generated destructor stub
}


void  LocationListener::OnLocationUpdated (Osp::Locations::Location &location)
{
	AppLog("OnLocationUpdated");
}

void  LocationListener::OnProviderStateChanged (Osp::Locations::LocProviderState newState)
{
	AppLog("OnProviderStateChanged");
}
