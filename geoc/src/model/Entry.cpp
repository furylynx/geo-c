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

Osp::Base::String Entry::title() const
{
	return title_;
}

float Entry::longitude() const
{
	return longitude_;
}

float Entry::latitude() const
{
	return latitude_;
}

}
