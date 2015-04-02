
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

	// Create the input fields
	pEditFieldTitle_ = new Osp::Ui::Controls::EditField();
	pEditFieldTitle_->Construct(Osp::Graphics::Rectangle(130, 2, 350, 60), EDIT_FIELD_STYLE_NORMAL, INPUT_STYLE_OVERLAY, EDIT_FIELD_TITLE_STYLE_NONE);
	pEditFieldTitle_->SetOverlayKeypadCommandButton(COMMAND_BUTTON_POSITION_LEFT, "Ok", ID_KEYPAD_BUTTON_OK);
	pEditFieldTitle_->SetOverlayKeypadCommandButton(COMMAND_BUTTON_POSITION_RIGHT, "Cancel", ID_KEYPAD_BUTTON_CANCEL);
	pEditFieldTitle_->AddActionEventListener(*this);
	pScrollPanel_->AddControl(*pEditFieldTitle_);

	pLabelTitle_ = new Osp::Ui::Controls::Label();
	pLabelTitle_->Construct(Osp::Graphics::Rectangle(2, 2, 128, 60), "Title");
	pScrollPanel_->AddControl(*pLabelTitle_);



	pEditFieldAuthor_ = new Osp::Ui::Controls::EditField();
	pEditFieldAuthor_->Construct(Osp::Graphics::Rectangle(130, 72, 350, 60), EDIT_FIELD_STYLE_NORMAL, INPUT_STYLE_OVERLAY, EDIT_FIELD_TITLE_STYLE_NONE);
	pEditFieldAuthor_->SetOverlayKeypadCommandButton(COMMAND_BUTTON_POSITION_LEFT, "Ok", ID_KEYPAD_BUTTON_OK);
	pEditFieldAuthor_->SetOverlayKeypadCommandButton(COMMAND_BUTTON_POSITION_RIGHT, "Cancel", ID_KEYPAD_BUTTON_CANCEL);
	pEditFieldAuthor_->AddActionEventListener(*this);
	pScrollPanel_->AddControl(*pEditFieldAuthor_);

	pLabelAuthor_ = new Osp::Ui::Controls::Label();
	pLabelAuthor_->Construct(Osp::Graphics::Rectangle(2, 72, 128, 60), "Author");
	pScrollPanel_->AddControl(*pLabelAuthor_);



	pEditFieldID_ = new Osp::Ui::Controls::EditField();
	pEditFieldID_->Construct(Osp::Graphics::Rectangle(130, 142, 350, 60), EDIT_FIELD_STYLE_NORMAL, INPUT_STYLE_OVERLAY, EDIT_FIELD_TITLE_STYLE_NONE);
	pEditFieldID_->SetOverlayKeypadCommandButton(COMMAND_BUTTON_POSITION_LEFT, "Ok", ID_KEYPAD_BUTTON_OK);
	pEditFieldID_->SetOverlayKeypadCommandButton(COMMAND_BUTTON_POSITION_RIGHT, "Cancel", ID_KEYPAD_BUTTON_CANCEL);
	pEditFieldID_->AddActionEventListener(*this);
	pScrollPanel_->AddControl(*pEditFieldID_);

	pLabelID_ = new Osp::Ui::Controls::Label();
	pLabelID_->Construct(Osp::Graphics::Rectangle(2, 142, 128, 60), "ID");
	pScrollPanel_->AddControl(*pLabelID_);



	pEditFieldLongitude_ = new Osp::Ui::Controls::EditField();
	pEditFieldLongitude_->Construct(Osp::Graphics::Rectangle(130, 212, 350, 60), EDIT_FIELD_STYLE_NUMBER, INPUT_STYLE_OVERLAY, EDIT_FIELD_TITLE_STYLE_NONE);
	pEditFieldLongitude_->SetOverlayKeypadCommandButton(COMMAND_BUTTON_POSITION_LEFT, "Ok", ID_KEYPAD_BUTTON_OK);
	pEditFieldLongitude_->SetOverlayKeypadCommandButton(COMMAND_BUTTON_POSITION_RIGHT, "Cancel", ID_KEYPAD_BUTTON_CANCEL);
	pEditFieldLongitude_->AddActionEventListener(*this);
	pScrollPanel_->AddControl(*pEditFieldLongitude_);

	pLabelLongitude_ = new Osp::Ui::Controls::Label();
	pLabelLongitude_->Construct(Osp::Graphics::Rectangle(2, 212, 128, 60), "Lon");
	pScrollPanel_->AddControl(*pLabelLongitude_);


	pEditFieldLatitude_ = new Osp::Ui::Controls::EditField();
	pEditFieldLatitude_->Construct(Osp::Graphics::Rectangle(130, 282, 350, 60), EDIT_FIELD_STYLE_NUMBER, INPUT_STYLE_OVERLAY, EDIT_FIELD_TITLE_STYLE_NONE);
	pEditFieldLatitude_->SetOverlayKeypadCommandButton(COMMAND_BUTTON_POSITION_LEFT, "Ok", ID_KEYPAD_BUTTON_OK);
	pEditFieldLatitude_->SetOverlayKeypadCommandButton(COMMAND_BUTTON_POSITION_RIGHT, "Cancel", ID_KEYPAD_BUTTON_CANCEL);
	pEditFieldLatitude_->AddActionEventListener(*this);
	pScrollPanel_->AddControl(*pEditFieldLatitude_);

	pLabelLatitude_ = new Osp::Ui::Controls::Label();
	pLabelLatitude_->Construct(Osp::Graphics::Rectangle(2, 282, 128, 60), "Lat");
	pScrollPanel_->AddControl(*pLabelLatitude_);


//	pEditFieldID_ = static_cast<EditField *>(pScrollPanel_->GetControl(L"IDC_EDITFIELD_ID"));
//	pEditFieldLongitude_ = static_cast<EditField *>(pScrollPanel_->GetControl(L"IDC_EDITFIELD_LON"));
//	pEditFieldLatitude_ = static_cast<EditField *>(pScrollPanel_->GetControl(L"IDC_EDITFIELD_LAT"));

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


			//apply changes to the entry
			pEntry_->SetTitle(pEditFieldTitle_->GetText());
			pEntry_->SetAuthor(pEditFieldAuthor_->GetText());
			pEntry_->SetNameId(pEditFieldID_->GetText());

			float fLon;
			Float::Parse(pEditFieldLongitude_->GetText(), fLon);
			pEntry_->SetLongitude(fLon);

			float fLat;
			Float::Parse(pEditFieldLatitude_->GetText(), fLat);
			pEntry_->SetLatitude(fLat);

			//TODO other fields (description, hints, comments, etc)

			pEntry_->NotifyObservers(pEntry_);

			//request back
			for (std::size_t i = 0; i < formBackListeners_.size(); i++)
			{
				//TODO request back

				formBackListeners_.at(i)->OnFormBackRequested(*this);
				//formBackListeners_.at(i).OnFormBackRequested(*this);
			}



		}
		break;
		case ID_KEYPAD_BUTTON_OK:
		case ID_KEYPAD_BUTTON_CANCEL:
		{
			pEditFieldTitle_->HideKeypad();
            pEditFieldAuthor_->HideKeypad();
			pEditFieldID_->HideKeypad();
			pEditFieldLongitude_->HideKeypad();
			pEditFieldLatitude_->HideKeypad();
		}
		break;
		default:
		break;
	}
}


void CacheDetailsForm::SetFormBackEventListener(Osp::Ui::Controls::IFormBackEventListener* pFormBackEventListener)
{
	AppLog("Set form back listener!");
	Form::SetFormBackEventListener(pFormBackEventListener);

	formBackListeners_.push_back(pFormBackEventListener);
}


