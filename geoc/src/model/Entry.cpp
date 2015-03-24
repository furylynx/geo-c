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

void Entry::SetTitle(Osp::Base::String title)
{
	title_ = title;
}

float Entry::Longitude() const
{
	return longitude_;
}

void Entry::SetLongitude(float longitude)
{
	longitude_ = longitude;
}

float Entry::Latitude() const
{
	return latitude_;
}

void Entry::SetLatitude(float latitude)
{
	latitude_ = latitude;
}

bool Entry::IsCustom() const
{
	return custom_;
}

void Entry::SetCustom(bool custom)
{
	custom_ = custom;
}

bool Entry::IsActive() const
{
	return active_;
}

void Entry::SetActive(bool active)
{
	active_ = active;
}

Osp::Base::String Entry::NameId() const
{
	return nameId_;
}

void Entry::SetNameId(Osp::Base::String nameId)
{
	nameId_ = nameId;
}

Osp::Base::String Entry::Author() const
{
	return author_;
}

void Entry::SetAuthor(Osp::Base::String author)
{
	author_ = author;
}

Osp::Base::String Entry::Description() const
{
	return description_;
}

void Entry::SetDescription(Osp::Base::String description)
{
	description_ = description;
}

Osp::Base::String Entry::Hint() const
{
	return hint_;
}

void Entry::SetHint(Osp::Base::String hint)
{
	hint_ = hint;
}

Osp::Base::String Entry::Type() const
{
	return type_;
}

void Entry::SetType(Osp::Base::String type)
{
	type_ = type;
}

Osp::Base::String Entry::Url() const
{
	return url_;
}

void Entry::SetUrl(Osp::Base::String url)
{
	url_ = url;
}

Osp::Base::String Entry::ToString() const
{
	Osp::Base::String resultString = title_;

	if (author_.GetLength() > 0)
	{
		resultString.Append(" [");
		resultString.Append(author_);
		resultString.Append("]");
	}

	return resultString;
}


}
