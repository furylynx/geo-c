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

float Entry::Longitude() const
{
	return longitude_;
}

float Entry::Latitude() const
{
	return latitude_;
}

void Entry::Export(Osp::Base::String filename) const
{
	//TODO export to gpx file
	//other formats?
}

}
