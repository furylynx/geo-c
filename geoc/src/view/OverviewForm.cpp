
#include "OverviewForm.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;


OverviewForm::OverviewForm(void)
{
}

OverviewForm::~OverviewForm(void)
{
}

bool
OverviewForm::Initialize()
{
	Form::Construct(L"IDF_OVERVIEW");

	return true;
}

result
OverviewForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	return r;
}

result OverviewForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}


