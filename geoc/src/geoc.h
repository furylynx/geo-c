#ifndef _GEOC_H_
#define _GEOC_H_

//custom includes
#include "controller/SensorController.h"
#include "controller/EntryController.h"


#include "view/MainForm.h"
#include "view/OverviewForm.h"
#include "view/PreferencesForm.h"
#include "view/CachesForm.h"
#include "view/CacheDetailsForm.h"

//global includes
#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FUi.h>
#include <FIo.h>

/**
 * [geoc] application must inherit from Application class
 * which provides basic features necessary to define an application.
 */
class GeoC :
	public Osp::App::Application,
	public Osp::System::IScreenEventListener,
	public Osp::Ui::Controls::IFormBackEventListener
{
public:

	/**
	 * [geoc] application must have a factory method that creates an instance of itself.
	 */
	static Osp::App::Application* CreateInstance(void);


public:
	GeoC();
	~GeoC();


public:


	// Called when the application is initializing.
	virtual bool OnAppInitializing(Osp::App::AppRegistry& appRegistry);

	// Called when the application is terminating.
	virtual bool OnAppTerminating(Osp::App::AppRegistry& appRegistry, bool forcedTermination = false);


	// Called when the application's frame moves to the top of the screen.
	virtual void OnForeground(void);


	// Called when this application's frame is moved from top of the screen to the background.
	virtual void OnBackground(void);

	// Called when the system memory is not sufficient to run the application any further.
	virtual void OnLowMemory(void);

	// Called when the battery level changes.
	virtual void OnBatteryLevelChanged(Osp::System::BatteryLevel batteryLevel);

	// Called when the screen turns on.
	virtual void OnScreenOn (void);

	// Called when the screen turns off.
	virtual void OnScreenOff (void);

	// Called when a form's back button is pressed
	virtual void OnFormBackRequested(Osp::Ui::Controls::Form& source);


private:
	geo::SensorController* pSensorController_;
	geo::EntryController* pEntryController_;

	Osp::Ui::Controls::Frame* pFrame_;

	MainForm* pMainForm_;
	PreferencesForm* pPreferencesForm_;
	OverviewForm* pOverviewForm_;
	CachesForm* pCachesForm_;
	CacheDetailsForm* pCacheDetailsForm_;
	CacheDetailsOverviewForm* pCacheDetailsOverviewForm_;

};

#endif
