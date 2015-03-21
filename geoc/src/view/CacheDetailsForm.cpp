
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

	if (pEditFieldTitle_ != NULL)
	{
		pEditFieldTitle_->SetText(entry->Title());
	}
	else
	{
		AppLog("edit field null!");
	}

	if (pEditFieldAuthor_ != NULL)
	{
		pEditFieldAuthor_->SetText(entry->Author());
	}

	if (pEditFieldID_ != NULL)
	{
		pEditFieldID_->SetText(entry->NameId());
	}

	if (pEditFieldLatitude_ != NULL)
	{
		pEditFieldLatitude_->SetText(Osp::Base::Float::ToString(entry->Latitude()));
	}

	if (pEditFieldLongitude_ != NULL)
	{
		pEditFieldLongitude_->SetText(Osp::Base::Float::ToString(entry->Longitude()));
	}
}

result CacheDetailsForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	GetFooter()->AddActionEventListener(*this);

	pScrollPanel_ = static_cast<ScrollPanel *>(GetControl(L"IDC_SCROLLPANEL"));


	AppLog("on_init editfieldtitle");
	pEditFieldTitle_ = static_cast<EditField *>(GetControl(L"IDC_EDITFIELD_TITLE"));
	pEditFieldAuthor_ = static_cast<EditField *>(GetControl(L"IDC_EDITFIELD_AUTHOR"));
	pEditFieldID_ = static_cast<EditField *>(GetControl(L"IDC_EDITFIELD_ID"));
	pEditFieldLongitude_ = static_cast<EditField *>(GetControl(L"IDC_EDITFIELD_LON"));
	pEditFieldLatitude_ = static_cast<EditField *>(GetControl(L"IDC_EDITFIELD_LAT"));

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
			pEntry_->SetTitle(pEditFieldTitle_->GetText());
			pEntry_->SetAuthor(pEditFieldAuthor_->GetText());
			pEntry_->SetNameId(pEditFieldID_->GetText());

			float fLon;
			Float::Parse(pEditFieldLongitude_->GetText(), fLon);
			pEntry_->SetLongitude(fLon);

			float fLat;
			Float::Parse(pEditFieldLatitude_->GetText(), fLat);
			pEntry_->SetLatitude(fLat);

		}
		break;
		default:
		break;
	}
}


