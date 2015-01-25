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
MainForm::Initialize(PreferencesForm* pPreferencesForm, OverviewForm* pOverviewForm, CachesForm* pCachesForm)
{
	pPreferencesForm_ = pPreferencesForm;
	pOverviewForm_ = pOverviewForm;
	pCachesForm_ = pCachesForm;

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
	pLabelLongitude_ = static_cast<Label *>(GetControl(L"IDC_LABEL_LONGITUDE"));
	pLabelDistance_ = static_cast<Label *>(GetControl(L"IDC_LABEL_DISTANCE"));

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

void MainForm::OnLocationUpdate(Osp::Locations::Location& location)
{
	//TODO
}

void MainForm::OnLocatorStateChanged(Osp::Locations::LocProviderState newState)
{
	//TODO
}

void MainForm::OnTiltUpdate(float azimuth, float pitch, float roll)
{
	//TODO
}

void MainForm::OnMagneticUpdate(float degreesToNorth, float x, float y, float z)
{
	//TODO
}
