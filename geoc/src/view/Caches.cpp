
#include "Caches.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;


Caches::Caches(void)
{
}

Caches::~Caches(void)
{
}

bool
Caches::Initialize()
{
	Form::Construct(L"IDF_CACHES");

	return true;
}

result
Caches::OnInitializing(void)
{
	result r = E_SUCCESS;

	SetFormBackEventListener(this);

	return r;
}

result
Caches::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}


void Caches::OnFormBackRequested(Osp::Ui::Controls::Form& source)
{
	//TODO navigate to last mask
}


