
#include "CachesForm.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;


CachesForm::CachesForm(void)
{
}

CachesForm::~CachesForm(void)
{
}

bool CachesForm::Initialize(CacheDetailsForm* pCacheDetails, geo::EntryController* pEntryController)
{
	pCacheDetails_ = pCacheDetails;
	pEntryController_ = pEntryController;

	Form::Construct(L"IDF_CACHES");

	return true;
}

result CachesForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	GetFooter()->AddActionEventListener(*this);


	return r;
}

result CachesForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

void CachesForm::OnActionPerformed(const Osp::Ui::Control& source, int actionId)
{
	AppLog("Action performed! \n");

	switch(actionId)
	{
		case ID_FOOTER_BUTTON_ADD:
		{
			AppLog("ADD Button is clicked! \n");

			//create a new entry
			geo::Entry* entry = new geo::Entry();
			entry->Construct();

			pEntryController_->AddEntry(entry);

			//update the details form
			pCacheDetails_->Update(entry);

			//show details form
			Osp::App::Application::GetInstance()->GetAppFrame()->GetFrame()->SetCurrentForm(*pCacheDetails_);
			pCacheDetails_->Draw();
			pCacheDetails_->Show();
		}
		break;
		default:
		break;
	}
}



