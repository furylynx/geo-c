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

	virtual void Construct(Osp::Base::String title, float longitude, float latitude);

	virtual Osp::Base::String title() const;

	virtual float longitude() const;
	virtual float latitude() const;

private:
	Osp::Base::String title_;
	float longitude_;
	float latitude_;

};

}

#endif /* ENTRY_H_ */
