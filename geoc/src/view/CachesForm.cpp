
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

bool
CachesForm::Initialize()
{
	Form::Construct(L"IDF_CACHES");

	return true;
}

result
CachesForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	return r;
}

result
CachesForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}




