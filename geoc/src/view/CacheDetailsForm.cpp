
#include "CacheDetailsForm.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;


CacheDetailsForm::CacheDetailsForm(void)
{
}

CacheDetailsForm::~CacheDetailsForm(void)
{
}

bool CacheDetailsForm::Initialize()
{
	Form::Construct(L"IDF_CACHEDETAIL");

	return true;
}

void CacheDetailsForm::Update(geo::Entry* entry)
{
	pEntry_ = entry;

	//TODO update input fields...
	//updates are directly written to the entry, no invokation of any controller required!
}

result CacheDetailsForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	GetFooter()->AddActionEventListener(*this);

	pScrollPanel_ = static_cast<ScrollPanel *>(GetControl(L"IDC_SCROLLPANEL"));

	return r;
}

result CacheDetailsForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

void CacheDetailsForm::OnActionPerformed(const Osp::Ui::Control& source, int actionId)
{
	switch(actionId)
	{
		case ID_FOOTER_BUTTON_SAVE:
		{
			AppLog("Save Button is clicked! \n");


			//TODO apply changes to the entry
			pEntry_->SetName("Unknown");

		}
		break;
		default:
		break;
	}
}


