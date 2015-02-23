/*
 * EntryController.cpp
 *
 *  Created on: 24.01.2015
 *      Author: furylynx
 */

#include "EntryController.h"

using namespace Osp::Io;

namespace geo
{

EntryController::EntryController()
{

}

EntryController::~EntryController()
{
	for (std::size_t i = 0; i < entries_.size(); i++)
	{
		delete entries_.at(i);
		entries_.at(i) = NULL;
	}
}

void EntryController::Construct()
{
	ioCtrl_.Construct();
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

geo::Entry* EntryController::At(std::size_t index) const
{
	return entries_.at(index);
}

bool EntryController::ImportEntries(Osp::Base::String path)
{
	Directory* pDir = new Directory();
	result r = pDir->Construct(path);

	if (IsFailed(r))
	{
		AppLog("Failed to import entries: directory is not accessible.");
		return false;
	}

	DirEnumerator* pDirEnum = pDir->ReadN();

	while(pDirEnum->MoveNext() == E_SUCCESS)
	{
		DirEntry dirEntry = pDirEnum->GetCurrentDirEntry();

		if (dirEntry.GetName().EndsWith(".loc"))
		{
			AppLog("File %S",dirEntry.GetName().GetPointer());

			Entry* newEntry = new Entry();
			newEntry->Construct();

			Osp::Base::String filePath = path;
			filePath.Append(dirEntry.GetName());

			result parseResult = ioCtrl_.ParseLOC(filePath, newEntry);

			if (!IsFailed(parseResult))
			{
				AddEntry(newEntry);
			}
			else
			{
				delete newEntry;
			}
		}
		else if (dirEntry.GetName().EndsWith(".gpx"))
		{

			AppLog("File %S",dirEntry.GetName().GetPointer());

			Entry* newEntry = new Entry();
			newEntry->Construct();

			Osp::Base::String filePath = path;
			filePath.Append(dirEntry.GetName());

			result parseResult = ioCtrl_.ParseGPX(filePath, newEntry);

			if (!IsFailed(parseResult))
			{
				AddEntry(newEntry);
			}
			else
			{
				delete newEntry;
			}
		}


	}


	return true;
}

std::size_t EntryController::Size() const
{
	return entries_.size();
}

}
