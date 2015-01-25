
#ifndef _CACHES_H_
#define _CACHES_H_


//custom includes
#include "../controller/EntryController.h"

#include "CacheDetailsForm.h"

//global includes
#include <FApp.h>
#include <FBase.h>
#include <FUi.h>



class CachesForm :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::IActionEventListener
{

// Construction
public:
	CachesForm(void);
	virtual ~CachesForm(void);

	virtual bool Initialize(CacheDetailsForm* pCacheDetails, geo::EntryController* pEntryController);

	virtual result OnInitializing(void);

	virtual result OnTerminating(void);

	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);

// Implementation
protected:
	static const int ID_FOOTER_BUTTON_ADD = 201;


// Generated call-back functions
public:
	CacheDetailsForm* pCacheDetails_;

	geo::EntryController* pEntryController_;


};

#endif
