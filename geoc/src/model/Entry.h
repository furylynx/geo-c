/*
 * Entry.h
 *
 *  Created on: 24.01.2015
 *      Author: John
 */

#ifndef ENTRY_H_
#define ENTRY_H_

//custom includes
//...

//global includes
#include <FBase.h>


namespace geo
{

class Entry
{
public:
	Entry();
	virtual ~Entry();

	virtual void Construct();
	virtual void Construct(Osp::Base::String title, float longitude, float latitude);

	virtual Osp::Base::String Title() const;
	virtual void SetName(Osp::Base::String title);

	virtual float Longitude() const;
	virtual float Latitude() const;

	virtual bool IsCustom() const;

	virtual void Export(Osp::Base::String filename) const;

private:
	Osp::Base::String title_;
	float longitude_;
	float latitude_;

	bool custom_;

};

}

#endif /* ENTRY_H_ */
