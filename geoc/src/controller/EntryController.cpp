/*
 * EntryController.cpp
 *
 *  Created on: 24.01.2015
 *      Author: furylynx
 */

#include "EntryController.h"

namespace geo
{

EntryController::EntryController()
{

}

EntryController::~EntryController()
{

}

void EntryController::AddEntry(Osp::Base::String title, float longitude, float latitude)
{
	Entry e;
	e.Construct(title, longitude, latitude);
	entries_.push_back(e);
}

std::vector<geo::Entry> EntryController::GetEntries() const
{
	return entries_;
}

}
