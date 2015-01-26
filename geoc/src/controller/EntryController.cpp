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

void EntryController::Construct()
{

}

void EntryController::AddEntry(Osp::Base::String title, float longitude, float latitude)
{
	Entry* e = new Entry();
	e->Construct(title, longitude, latitude);

	entries_.push_back(e);
}

void EntryController::AddEntry(Entry* entry)
{
	entries_.push_back(entry);
}

std::vector<geo::Entry*> EntryController::GetEntries() const
{
	return entries_;
}

std::vector<geo::Entry*> EntryController::GetActiveEntries() const
{
	std::vector<geo::Entry*> result;

	for (std::size_t i = 0; i < entries_.size(); i++)
	{
		if (entries_.at(i)->IsActive())
		{
			result.push_back(entries_.at(i));
		}
	}

	return result;
}

void EntryController::ImportEntries(Osp::Base::String path)
{
	//TODO read folder and parse entries
}

unsigned int EntryController::Size() const
{
	return entries_.size();
}

}
