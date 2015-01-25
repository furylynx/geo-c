
#ifndef _CACHES_H_
#define _CACHES_H_

#include <FBase.h>
#include <FUi.h>



class Caches :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::Controls::IFormBackEventListener
{

// Construction
public:
	Caches(void);
	virtual ~Caches(void);

	virtual bool Initialize();

	virtual result OnInitializing(void);

	virtual result OnTerminating(void);

	virtual void OnFormBackRequested(Osp::Ui::Controls::Form& source);

// Implementation
protected:

// Generated call-back functions
public:

};

#endif
