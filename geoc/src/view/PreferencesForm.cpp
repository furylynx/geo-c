
#include "PreferencesForm.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;


PreferencesForm::PreferencesForm(void)
{
}

PreferencesForm::~PreferencesForm(void)
{
}

bool PreferencesForm::Initialize()
{
	Form::Construct(L"IDF_PREFERENCES");

	return true;
}

result PreferencesForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	return r;
}

result PreferencesForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}




