
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
	entry_ = entry;

	//TODO update input fields...
	//updates are directly written to the entry, no invokation of any controller required!
}

result CacheDetailsForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	return r;
}

result CacheDetailsForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}


