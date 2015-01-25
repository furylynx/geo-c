
#ifndef _CACHES_H_
#define _CACHES_H_

#include <FBase.h>
#include <FUi.h>



class CachesForm :
	public Osp::Ui::Controls::Form
{

// Construction
public:
	CachesForm(void);
	virtual ~CachesForm(void);

	virtual bool Initialize();

	virtual result OnInitializing(void);

	virtual result OnTerminating(void);

// Implementation
protected:

// Generated call-back functions
public:

};

#endif
