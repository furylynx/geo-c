
#include "Cachedetail.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;


Cachedetail::Cachedetail(void)
{
}

Cachedetail::~Cachedetail(void)
{
}

bool Cachedetail::Initialize()
{
	Form::Construct(L"IDF_CACHEDETAIL");

	return true;
}

void Cachedetail::Update(geo::Entry& entry)
{
	entry_ = entry;

	//TODO update input fields...
}

result Cachedetail::OnInitializing(void)
{
	result r = E_SUCCESS;

	SetFormBackEventListener(this);

	return r;
}

result Cachedetail::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}


void Cachedetail::OnFormBackRequested(Osp::Ui::Controls::Form& source)
{
	//TODO navigate to last mask
}

