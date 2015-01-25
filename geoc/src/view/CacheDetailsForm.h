
#ifndef _CACHEDETAIL_H_
#define _CACHEDETAIL_H_

//custom includes
#include "../model/Entry.h"

//global includes
#include <FBase.h>
#include <FUi.h>



class CacheDetailsForm :
	public Osp::Ui::Controls::Form
{

// Construction
public:
	CacheDetailsForm(void);
	virtual ~CacheDetailsForm(void);
	virtual bool Initialize();

	virtual void Update(geo::Entry* entry);

	virtual result OnInitializing(void);
	virtual result OnTerminating(void);


protected:


public:
	geo::Entry* entry_;

};

#endif
