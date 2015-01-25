
#ifndef _CACHEDETAIL_H_
#define _CACHEDETAIL_H_

//custom includes
#include "../model/Entry.h"

//global includes
#include <FBase.h>
#include <FUi.h>



class Cachedetail :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::Controls::IFormBackEventListener
{

// Construction
public:
	Cachedetail(void);
	virtual ~Cachedetail(void);
	virtual bool Initialize();

	virtual void Update(geo::Entry& entry);

	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	virtual void OnFormBackRequested(Osp::Ui::Controls::Form& source);


// Implementation
protected:

// Generated call-back functions
public:
	geo::Entry entry_;

};

#endif
