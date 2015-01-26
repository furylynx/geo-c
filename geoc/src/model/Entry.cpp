/*
 * Entry.cpp
 *
 *  Created on: 24.01.2015
 *      Author: John
 */

#include "Entry.h"

namespace geo {

Entry::Entry()
{

}

Entry::~Entry()
{

}

void Entry::Construct()
{
	Construct("Unnamed", 0.0f, 0.0f);
	custom_ = true;
}

void Entry::Construct(Osp::Base::String title, float longitude, float latitude)
{
	title_ = title;
	longitude_ = longitude;
	latitude_ = latitude;
}

Osp::Base::String Entry::Title() const
{
	return title_;
}

void Entry::SetName(Osp::Base::String title)
{
	title_ = title;
}

float Entry::Longitude() const
{
	return longitude_;
}

float Entry::Latitude() const
{
	return latitude_;
}

bool Entry::IsCustom() const
{
	return custom_;
}

bool Entry::IsActive() const
{
	return active_;
}


void Entry::Export(Osp::Base::String filename) const
{
	//TODO export to gpx file
	//other formats?
}


}
