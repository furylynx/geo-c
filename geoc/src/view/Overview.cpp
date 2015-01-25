
#include "Overview.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;


Overview::Overview(void)
{
}

Overview::~Overview(void)
{
}

bool
Overview::Initialize()
{
	Form::Construct(L"IDF_OVERVIEW");

	return true;
}

result
Overview::OnInitializing(void)
{
	result r = E_SUCCESS;

	SetFormBackEventListener(this);

	return r;
}

result Overview::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}


void Overview::OnFormBackRequested(Osp::Ui::Controls::Form& source)
{
	//TODO navigate to last mask
}

