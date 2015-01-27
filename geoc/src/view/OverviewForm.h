
#ifndef _OVERVIEW_H_
#define _OVERVIEW_H_

//custom includes
#include "../model/ISensorUpdateListener.h"

//global includes
#include <FBase.h>
#include <FUi.h>




class OverviewForm :
	public Osp::Ui::Controls::Form,
 	public geo::ISensorUpdateListener
{

// Construction
public:
	OverviewForm(void);
	virtual ~OverviewForm(void);
	virtual bool Initialize();
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	virtual void OnLocationUpdate(Osp::Locations::Location& location);
	virtual void OnLocatorStateChanged(Osp::Locations::LocProviderState newState);
	virtual void OnTiltUpdate(float azimuth, float pitch, float roll);
	virtual void OnMagneticUpdate(float degreesToNorth, float x, float y, float z);
	virtual void OnGPSUpdate(float longitude, float latitude);


// Implementation
protected:

// Generated call-back functions
public:

};

#endif
