#ifndef _MAINFORM_H_
#define _MAINFORM_H_

//custom includes
#include "PreferencesForm.h"
#include "OverviewForm.h"
#include "CachesForm.h"

#include "../model/ISensorUpdateListener.h"
#include "../controller/EntryController.h"

//global includes
#include <FApp.h>
#include <FBase.h>
#include <FUi.h>

#include <sstream>
#include <cmath>


class MainForm :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::IActionEventListener,
 	public Osp::Ui::ITouchEventListener,
 	public geo::ISensorUpdateListener
{

// Construction
public:
	MainForm(void);
	virtual ~MainForm(void);
	bool Initialize(PreferencesForm* pPreferencesForm, OverviewForm* pOverviewForm, CachesForm* pCachesForm, geo::EntryController* pEntryController);

// Implementation
private:
	static const int ID_BUTTON_OK = 101;
	Osp::Ui::Controls::Button *pButtonOk_;

	Osp::Ui::Controls::Label *pLabelLatitude_;
	Osp::Ui::Controls::Label *pLabelLatitudeTitle_;
	Osp::Ui::Controls::Label *pLabelLongitude_;
	Osp::Ui::Controls::Label *pLabelLongitudeTitle_;
	Osp::Ui::Controls::Label *pLabelLocationState_;
	Osp::Ui::Controls::Label *pLabelLocationStateTitle_;

	Osp::Ui::Controls::Label *pLabelDistance_;
	Osp::Ui::Controls::Label *pLabelDistanceTitle_;


	//forms
	PreferencesForm* pPreferencesForm_;
	OverviewForm* pOverviewForm_;
	CachesForm* pCachesForm_;

	//entry controller
	geo::EntryController* pEntryController_;

	int locationCounter_;


public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);

	virtual void OnTouchDoublePressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchFocusIn(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchFocusOut(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchLongPressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchMoved(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchPressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchReleased(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);

	//sensor updates
	virtual void OnLocationUpdate(Osp::Locations::Location& location, const Osp::Locations::Location* lastKnownLocation);
	virtual void OnLocatorStateChanged(Osp::Locations::LocProviderState newState);
	virtual void OnTiltUpdate(float azimuth, float pitch, float roll);
	virtual void OnMagneticUpdate(float degreesToNorth, float x, float y, float z);
	virtual void OnGPSUpdate(float longitude, float latitude);

};

#endif	//_MAINFORM_H_
