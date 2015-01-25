
#ifndef _OVERVIEW_H_
#define _OVERVIEW_H_

//custom includes
//...

//global includes
#include <FBase.h>
#include <FUi.h>



class OverviewForm :
	public Osp::Ui::Controls::Form
{

// Construction
public:
	OverviewForm(void);
	virtual ~OverviewForm(void);
	virtual bool Initialize();
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);


// Implementation
protected:

// Generated call-back functions
public:

};

#endif
