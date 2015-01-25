
#ifndef _PREFERENCES_H_
#define _PREFERENCES_H_

#include <FBase.h>
#include <FUi.h>



class Preferences :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::Controls::IFormBackEventListener
{

// Construction
public:
	Preferences(void);
	virtual ~Preferences(void);
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
