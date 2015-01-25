
#ifndef _PREFERENCES_H_
#define _PREFERENCES_H_

#include <FBase.h>
#include <FUi.h>



class PreferencesForm :
	public Osp::Ui::Controls::Form
{

// Construction
public:
	PreferencesForm(void);
	virtual ~PreferencesForm(void);
	virtual bool Initialize();
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);


// Implementation
protected:

// Generated call-back functions
public:

};

#endif
