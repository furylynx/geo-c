
#include "CacheDetailsOverviewForm.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;


CacheDetailsOverviewForm::CacheDetailsOverviewForm(void)
{
}

CacheDetailsOverviewForm::~CacheDetailsOverviewForm(void)
{
}

bool
CacheDetailsOverviewForm::Initialize(CacheDetailsForm* pCacheDetails)
{
	pCacheDetails_ = pCacheDetails;

	Form::Construct(L"IDF_CACHEDETAILOVERVIEW");

	return true;
}

result
CacheDetailsOverviewForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	GetFooter()->AddActionEventListener(*this);

	pTextBox_ = static_cast<TextBox *>(GetControl(L"IDC_TEXTBOX"));

	return r;
}

result
CacheDetailsOverviewForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

void CacheDetailsOverviewForm::OnActionPerformed(const Osp::Ui::Control& source, int actionId)
{
	switch(actionId)
	{
		case ID_FOOTER_BUTTON_EDIT:
		{
			AppLog("Edit Button is clicked! \n");

			if (pEntry_ != NULL)
			{
	    		//update the details form
	    		pCacheDetails_->Update(pEntry_);

	    		//show details form
	    		Osp::App::Application::GetInstance()->GetAppFrame()->GetFrame()->SetCurrentForm(*pCacheDetails_);
	    		pCacheDetails_->Draw();
	    		pCacheDetails_->Show();
			}


		}
		break;
		default:
		break;
	}
}

void CacheDetailsOverviewForm::Update(geo::Entry* entry)
{
	pEntry_ = entry;

	if (pTextBox_ != NULL)
	{
		pTextBox_->SetText(entry->ToDetailedString());
	}
	else
	{
		AppLog("text box null!");
	}
}



