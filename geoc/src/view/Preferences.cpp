
#include "Preferences.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;


Preferences::Preferences(void)
{
}

Preferences::~Preferences(void)
{
}

bool Preferences::Initialize()
{
	Form::Construct(L"IDF_PREFERENCES");

	return true;
}

result Preferences::OnInitializing(void)
{
	result r = E_SUCCESS;

	SetFormBackEventListener(this);

	return r;
}

result Preferences::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}


void Preferences::OnFormBackRequested(Osp::Ui::Controls::Form& source)
{
	//TODO navigate to last mask
}


