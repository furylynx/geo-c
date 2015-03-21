
#ifndef _CACHEDETAIL_H_
#define _CACHEDETAIL_H_

//custom includes
#include "../model/Entry.h"

//global includes
#include <FBase.h>
#include <FUi.h>



class CacheDetailsForm :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::IActionEventListener
{

// Construction
public:
	CacheDetailsForm(void);
	virtual ~CacheDetailsForm(void);
	virtual bool Initialize();

	virtual void Update(geo::Entry* entry);

	virtual result OnInitializing(void);

	virtual result OnTerminating(void);

	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);


protected:


private:
	static const int ID_FOOTER_BUTTON_SAVE = 201;
//	static const int ID_FOOTER_BUTTON_SAVE = 201;
//	static const int ID_FOOTER_BUTTON_SAVE = 201;
//	static const int ID_FOOTER_BUTTON_SAVE = 201;
//	static const int ID_FOOTER_BUTTON_SAVE = 201;


	geo::Entry* pEntry_;

	Osp::Ui::Controls::ScrollPanel* pScrollPanel_;

	Osp::Ui::Controls::EditField* pEditFieldTitle_;
	Osp::Ui::Controls::EditField* pEditFieldAuthor_;
	Osp::Ui::Controls::EditField* pEditFieldID_;
	Osp::Ui::Controls::EditField* pEditFieldLongitude_;
	Osp::Ui::Controls::EditField* pEditFieldLatitude_;

};

#endif
