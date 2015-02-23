/**
 * Name        : geoc
 * Version     : 
 * Vendor      : furylynx
 * Description : geo'c - geo caching app for WVGA bada devices.
 */

#include "GeoC.h"

using namespace Osp::App;
using namespace Osp::Base;
using namespace Osp::System;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

GeoC::GeoC()
{
}

GeoC::~GeoC()
{
	delete pMainForm_;
	delete pPreferencesForm_;
	delete pOverviewForm_;
	delete pCachesForm_;
	delete pCacheDetailsForm_;

	delete pSensorController_;
}

Application* GeoC::CreateInstance(void)
{
	// Create the instance through the constructor.
	return new GeoC();
}

bool GeoC::OnAppInitializing(AppRegistry& appRegistry)
{
	// TODO:
	// Initialize UI resources and application specific data.
	// The application's permanent data and context can be obtained from the appRegistry.
	//
	// If this method is successful, return true; otherwise, return false.
	// If this method returns false, the application will be terminated.

	// Uncomment the following statement to listen to the screen on/off events.
	//PowerManager::SetScreenEventListener(*this);

	//initialize the sensor controller
	pSensorController_ = new geo::SensorController();
	pSensorController_->Construct();

	//initialize the entry controller
	pEntryController_ = new geo::EntryController();
	pEntryController_->Construct();

	//TODO path?!
	//pEntryController_->ImportEntries("Others/geo'c/");

	// Initialize all forms
	pCacheDetailsForm_ = new CacheDetailsForm();
	pCacheDetailsForm_->Initialize();
	pCacheDetailsForm_->SetFormBackEventListener(this);

	pCachesForm_ = new CachesForm();
	pCachesForm_->Initialize(pCacheDetailsForm_, pEntryController_);
	pCachesForm_->SetFormBackEventListener(this);

	pPreferencesForm_ = new PreferencesForm();
	pPreferencesForm_->Initialize();//TODO pass options controller, so that options are directly written to the controller, pass sensor controller in order to pause sensor work
	pPreferencesForm_->SetFormBackEventListener(this);

	pOverviewForm_ = new OverviewForm();
	pOverviewForm_->Initialize();
	pOverviewForm_->SetFormBackEventListener(this);
	pSensorController_->RegisterSensorUpdateListener(pOverviewForm_);

	pMainForm_ = new MainForm();
	pMainForm_->Initialize(pPreferencesForm_, pOverviewForm_, pCachesForm_);
	pSensorController_->RegisterSensorUpdateListener(pMainForm_);



	// Add the form to the frame
	pFrame_ = GetAppFrame()->GetFrame();
	pFrame_->AddControl(*pMainForm_);
	pFrame_->AddControl(*pPreferencesForm_);
	pFrame_->AddControl(*pOverviewForm_);
	pFrame_->AddControl(*pCachesForm_);
	pFrame_->AddControl(*pCacheDetailsForm_);


//	if (!Osp::Io::File::IsFileExist("/Home/geoc/"))
//	{
//		result createDirResult = Osp::Io::Directory::Create("/Home/geoc/", false);
//
//		if (!IsFailed(createDirResult))
//		{
//			AppLog("Created the dir /Home/geoc/ ...");
//		}
//		else
//		{
//			AppLog("Failed to create /Home/geoc/ ...");
//		}
//	}

	//check for geo'c directory
//	if (!Osp::Io::File::IsFileExist("/Storagecard/Media/Others/geo'c/"))
//	{
//
//		result createDirResult = Osp::Io::Directory::Create("/Storagecard/Media/Others/geo'c/", false);
//
//		if (!IsFailed(createDirResult))
//		{
//			AppLog("Created the dir /Media/Others/geo'c/ ...");
//		}
//		else
//		{
//			AppLog("Failed to create /Media/Others/geo'c/ ...");
//		}
//	}
//	else
//	{
		AppLog("Parsing data from /Media/Others");
		pEntryController_->ImportEntries("/Storagecard/Media");
//	}


	// Set the current form
	pFrame_->SetCurrentForm(*pMainForm_);

	// Draw and Show the form
	pMainForm_->Draw();
	pMainForm_->Show();

	return true;
}

bool GeoC::OnAppTerminating(AppRegistry& appRegistry, bool forcedTermination)
{
	// TODO:
	// Deallocate resources allocated by this application for termination.
	// The application's permanent data and context can be saved via appRegistry.
	return true;
}

void GeoC::OnForeground(void)
{
	// TODO:
	// Start or resume drawing when the application is moved to the foreground.

	//resume the sensors
	//pSensorController_->Resume();
}

void GeoC::OnBackground(void)
{
	// TODO:
	// Stop drawing when the application is moved to the background.

	//pause the sensors
	//pSensorController_->Pause();
}

void GeoC::OnLowMemory(void)
{
	// TODO:
	// Free unused resources or close the application.

	//terminate app
	//Osp::App::Application::Terminate();
}

void GeoC::OnBatteryLevelChanged(BatteryLevel batteryLevel)
{
	// TODO:
	// Handle any changes in battery level here.
	// Stop using multimedia features(camera, mp3 etc.) if the battery level is CRITICAL.
}

void GeoC::OnScreenOn (void)
{
	// TODO:
	// Get the released resources or resume the operations that were paused or stopped in OnScreenOff().
}

void GeoC::OnScreenOff (void)
{
	// TODO:
	//  Unless there is a strong reason to do otherwise, release resources (such as 3D, media, and sensors) to allow the device to enter the sleep mode to save the battery.
	// Invoking a lengthy asynchronous method within this listener method can be risky, because it is not guaranteed to invoke a callback before the device enters the sleep mode.
	// Similarly, do not perform lengthy operations in this listener method. Any operation must be a quick one.
}

void GeoC::OnFormBackRequested(Osp::Ui::Controls::Form& source)
{
	//TODO hide current form?
	AppLog("GeoC: BACK Button is clicked! \n");

	if (&source == pOverviewForm_ || &source == pPreferencesForm_ || &source == pCachesForm_ )
	{
		pFrame_->SetCurrentForm(*pMainForm_);

		// Draw and Show the form
		pMainForm_->Draw();
		pMainForm_->Show();
	}
	else if (&source == pCacheDetailsForm_)
	{
		pFrame_->SetCurrentForm(*pCachesForm_);

		// Draw and Show the form
		pCachesForm_->Draw();
		pCachesForm_->Show();
	}
}
