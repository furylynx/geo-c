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
	virtual void SetTitle(Osp::Base::String title);

	virtual float Longitude() const;
	virtual void SetLongitude(float longitude);

	virtual float Latitude() const;
	virtual void SetLatitude(float latitude);

	virtual bool IsCustom() const;
	virtual void SetCustom(bool custom);

	virtual bool IsActive() const;
	virtual void SetActive(bool active);

	virtual Osp::Base::String NameId() const;
	virtual void SetNameId(Osp::Base::String nameId);

	virtual Osp::Base::String Author() const;
	virtual void SetAuthor(Osp::Base::String author);

	virtual Osp::Base::String Description() const;
	virtual void SetDescription(Osp::Base::String description);

	virtual Osp::Base::String Hint() const;
	virtual void SetHint(Osp::Base::String hint);

	virtual Osp::Base::String Type() const;
	virtual Osp::Base::String SetType(Osp::Base::String type);

	virtual Osp::Base::String Url() const;
	virtual void SetUrl(Osp::Base::String url);


private:
	Osp::Base::String nameId_;
	Osp::Base::String title_;
	Osp::Base::String author_;
	Osp::Base::String description_;
	Osp::Base::String hint_;
	Osp::Base::String type_;
	Osp::Base::String url_;

	float longitude_;
	float latitude_;

	bool custom_;

	bool active_;

};

}

#endif /* ENTRY_H_ */
