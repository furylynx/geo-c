
#ifndef _OVERVIEW_H_
#define _OVERVIEW_H_

//custom includes
//...

//global includes
#include <FBase.h>
#include <FUi.h>



class Overview :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::Controls::IFormBackEventListener
{

// Construction
public:
	Overview(void);
	virtual ~Overview(void);
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
