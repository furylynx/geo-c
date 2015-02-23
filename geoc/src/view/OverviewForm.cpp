
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

void OverviewForm::OnLocationUpdate(Osp::Locations::Location& location, const Osp::Locations::Location* lastKnownLocation)
{
	//TODO
}

void OverviewForm::OnLocatorStateChanged(Osp::Locations::LocProviderState newState)
{
	//TODO
}

void OverviewForm::OnTiltUpdate(float azimuth, float pitch, float roll)
{
	//TODO
}

void OverviewForm::OnMagneticUpdate(float degreesToNorth, float x, float y, float z)
{
	//TODO
}

void OverviewForm::OnGPSUpdate(float longitude, float latitude)
{

}


