#include "MainForm.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

MainForm::MainForm(void)
{

}

MainForm::~MainForm(void)
{

}

bool
MainForm::Initialize(PreferencesForm* pPreferencesForm, OverviewForm* pOverviewForm, CachesForm* pCachesForm, geo::EntryController* pEntryController)
{
	pPreferencesForm_ = pPreferencesForm;
	pOverviewForm_ = pOverviewForm;
	pCachesForm_ = pCachesForm;

	pEntryController_ = pEntryController;

	locationCounter_ = 0;

	// Construct an XML form
	Construct(L"IDF_MAINFORM");

	return true;
}

result
MainForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	AddTouchEventListener(*this);

	// Get a button via resource ID
//	pButtonOk_ = static_cast<Button *>(GetControl(L"IDC_BUTTON_OK"));
//	if (pButtonOk_ != null)
//	{
//		pButtonOk_->SetActionId(ID_BUTTON_OK);
//		pButtonOk_->AddActionEventListener(*this);
//	}

	pLabelLatitude_ = static_cast<Label *>(GetControl(L"IDC_LABEL_LATITUDE"));
	pLabelLatitudeTitle_ = static_cast<Label *>(GetControl(L"IDC_LABEL_LATITUDE_TITLE"));
	pLabelLongitude_ = static_cast<Label *>(GetControl(L"IDC_LABEL_LONGITUDE"));
	pLabelLongitudeTitle_ = static_cast<Label *>(GetControl(L"IDC_LABEL_LONGITUDE_TITLE"));
	pLabelLocationState_ = static_cast<Label *>(GetControl(L"IDC_LABEL_LOCATION_STATE"));
	pLabelLocationStateTitle_ = static_cast<Label *>(GetControl(L"IDC_LABEL_LOCATION_STATE_TITLE"));

	pLabelDistance_ = static_cast<Label *>(GetControl(L"IDC_LABEL_DISTANCE"));
	pLabelDistanceTitle_ = static_cast<Label *>(GetControl(L"IDC_LABEL_DISTANCE_TITLE"));


	AddSoftkeyActionListener(SOFTKEY_0, *this);
	AddSoftkeyActionListener(SOFTKEY_1, *this);



	//TODO initialize menu

	return r;
}

result
MainForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

void MainForm::OnActionPerformed(const Osp::Ui::Control& source, int actionId)
{
	switch(actionId)
	{
		case SOFTKEY_0:
		{
			AppLog("OVERVIEW Button is clicked! \n");

			Osp::App::Application::GetInstance()->GetAppFrame()->GetFrame()->SetCurrentForm(*pOverviewForm_);
			pOverviewForm_->Draw();
			pOverviewForm_->Show();
		}
		break;
		case SOFTKEY_1:
		{
			AppLog("CACHES Button is clicked! \n");

			Osp::App::Application::GetInstance()->GetAppFrame()->GetFrame()->SetCurrentForm(*pCachesForm_);
			pCachesForm_->Draw();
			pCachesForm_->Show();
		}
		break;
		default:
		break;
	}
}



void MainForm::OnTouchDoublePressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here

}

void MainForm::OnTouchFocusIn(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here

}

void MainForm::OnTouchFocusOut(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here

}

void MainForm::OnTouchLongPressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here

}

void MainForm::OnTouchMoved(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here

}

void MainForm::OnTouchPressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here

}

void MainForm::OnTouchReleased(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo)
{
	// TODO: Add your implementation codes here

}

void MainForm::OnLocationUpdate(Osp::Locations::Location& location, const Osp::Locations::Location* lastKnownLocation)
{
	AppLog("MainForm: Location update! \n");

	if (location.GetQualifiedCoordinates() != NULL)
	{

		if (pLabelLatitude_ != NULL)
		{
			std::stringstream sstrLat;
			sstrLat << location.GetQualifiedCoordinates()->GetLatitude();

			pLabelLatitude_->SetText(sstrLat.str().c_str());
			pLabelLatitude_->Draw();
			pLabelLatitude_->Show();
		}

		if (pLabelLongitude_ != NULL)
		{
			std::stringstream sstrLon;
			sstrLon << location.GetQualifiedCoordinates()->GetLongitude();

			pLabelLongitude_->SetText(sstrLon.str().c_str());
			pLabelLongitude_->Draw();
			pLabelLongitude_->Show();
		}

		if (pLabelDistance_ != NULL)
		{
			geo::Entry* closestEntry = pEntryController_->GetClosestActiveEntry(location.GetQualifiedCoordinates());
			Osp::Locations::QualifiedCoordinates entryCoordinates = Osp::Locations::QualifiedCoordinates();
			entryCoordinates.Set(closestEntry->Latitude(), closestEntry->Longitude(), NAN, 0, 0);

			float d = entryCoordinates.Distance(*(location.GetQualifiedCoordinates()));

			std::stringstream sstrDist;
			sstrDist << d << " m";

			pLabelDistance_->SetText(sstrDist.str().c_str());
			pLabelDistance_->Draw();
			pLabelDistance_->Show();
		}
	}
	else if (lastKnownLocation != NULL && lastKnownLocation->GetQualifiedCoordinates() != NULL)
	{
		if (pLabelLatitude_ != NULL)
		{
			std::stringstream sstrLat;
			sstrLat << lastKnownLocation->GetQualifiedCoordinates()->GetLatitude();

			pLabelLatitude_->SetText(sstrLat.str().c_str());
			pLabelLatitude_->Draw();
			pLabelLatitude_->Show();
		}

		if (pLabelLongitude_ != NULL)
		{
			std::stringstream sstrLong;
			sstrLong << lastKnownLocation->GetQualifiedCoordinates()->GetLongitude();

			pLabelLongitude_->SetText(sstrLong.str().c_str());
			pLabelLongitude_->Draw();
			pLabelLongitude_->Show();
		}

		if (pLabelDistance_ != NULL)
		{
			geo::Entry* closestEntry = pEntryController_->GetClosestActiveEntry(lastKnownLocation->GetQualifiedCoordinates());
			Osp::Locations::QualifiedCoordinates entryCoordinates = Osp::Locations::QualifiedCoordinates();
			entryCoordinates.Set(closestEntry->Latitude(), closestEntry->Longitude(), NAN, 0, 0);

			float d = entryCoordinates.Distance(*(lastKnownLocation->GetQualifiedCoordinates()));

			std::stringstream sstrDist;
			sstrDist << d << " m";

			pLabelDistance_->SetText(sstrDist.str().c_str());
			pLabelDistance_->Draw();
			pLabelDistance_->Show();
		}
	}
	else
	{
		if (pLabelLatitude_ != NULL && pLabelLongitude_ != NULL)
		{
			std::stringstream sstr;
			for (int i = 0; i < locationCounter_; i++)
			{
				sstr << ".";
			}

			pLabelLatitude_->SetText(sstr.str().c_str());
			pLabelLatitude_->Draw();
			pLabelLatitude_->Show();

			pLabelLongitude_->SetText(sstr.str().c_str());
			pLabelLongitude_->Draw();
			pLabelLongitude_->Show();
		}

		locationCounter_++;

		if (locationCounter_ > 3)
		{
			locationCounter_ = 0;
		}
	}

}

void MainForm::OnLocatorStateChanged(Osp::Locations::LocProviderState newState)
{
	AppLog("MainForm: Locator state changed! \n");

	if (pLabelLocationState_ != NULL)
	{
		if (newState == Osp::Locations::LOC_PROVIDER_AVAILABLE)
		{
			pLabelLocationState_->SetText("Available");
		}
		else if (newState == Osp::Locations::LOC_PROVIDER_TEMPORARILY_UNAVAILABLE)
		{
			pLabelLocationState_->SetText("Temp. Unavailable");
		}
		else if (newState == Osp::Locations::LOC_PROVIDER_OUT_OF_SERVICE)
		{
			pLabelLocationState_->SetText("Out of service");
		}

		pLabelLocationState_->Draw();
		pLabelLocationState_->Show();
	}
}

void MainForm::OnTiltUpdate(float azimuth, float pitch, float roll)
{

}

void MainForm::OnMagneticUpdate(float degreesToNorth, float x, float y, float z)
{

}

void MainForm::OnGPSUpdate(float longitude, float latitude)
{
//	if (pLabelLongitude_ != NULL)
//	{
//		std::stringstream sstrLong;
//		sstrLong << longitude << std::endl;
//
//		pLabelLongitude_->SetText(sstrLong.str().c_str());
//
//		//pLabelLongitude_->RequestRedraw(true);
//
//		pLabelLongitude_->Draw();
//		pLabelLongitude_->Show();
//	}
//
//	if (pLabelLatitude_ != NULL)
//	{
//		std::stringstream sstrLat;
//		sstrLat << latitude << std::endl;
//
//		pLabelLatitude_->SetText(sstrLat.str().c_str());
//
//		//pLabelLatitude_->RequestRedraw(true);
//
//		pLabelLongitude_->Draw();
//		pLabelLongitude_->Show();
//	}
}
