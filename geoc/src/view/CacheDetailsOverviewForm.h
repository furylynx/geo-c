
#ifndef _CACHEDETAILSOVERVIEWFORM_H_
#define _CACHEDETAILSOVERVIEWFORM_H_

//custom includes
#include "CacheDetailsForm.h"
#include "../model/Entry.h"

//global includes
#include <FApp.h>
#include <FBase.h>
#include <FUi.h>



class CacheDetailsOverviewForm :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::IActionEventListener
{

// Construction
public:
	CacheDetailsOverviewForm(void);
	virtual ~CacheDetailsOverviewForm(void);
	bool Initialize(CacheDetailsForm* pCacheDetails);
	result OnInitializing(void);
	result OnTerminating(void);

	//action listener
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);

	//custom methods
	virtual void Update(geo::Entry* entry);

private:
	static const int ID_FOOTER_BUTTON_EDIT = 201;

	Osp::Ui::Controls::TextBox* pTextBox_;

	CacheDetailsForm* pCacheDetails_;

	geo::Entry* pEntry_;

};

#endif
