
#ifndef _CACHEDETAIL_H_
#define _CACHEDETAIL_H_

//custom includes
#include "../model/Entry.h"

//global includes
#include <FBase.h>
#include <FUi.h>
#include <FUiControls.h>

#include <vector>



class CacheDetailsForm :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::IActionEventListener
{

// Construction
public:
	CacheDetailsForm(void);
	virtual ~CacheDetailsForm(void);
	virtual bool Initialize();

	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	//action listener
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);

	//Form back
	virtual void SetFormBackEventListener(Osp::Ui::Controls::IFormBackEventListener* pFormBackEventListener);

	//custom methods
	virtual void Update(geo::Entry* entry);

private:
	static const int ID_FOOTER_BUTTON_SAVE = 201;
	static const int ID_KEYPAD_BUTTON_OK = 301;
	static const int ID_KEYPAD_BUTTON_CANCEL = 302;


	geo::Entry* pEntry_;

	Osp::Ui::Controls::ScrollPanel* pScrollPanel_;

	Osp::Ui::Controls::EditField* pEditFieldTitle_;
	Osp::Ui::Controls::EditField* pEditFieldAuthor_;
	Osp::Ui::Controls::EditField* pEditFieldID_;
	Osp::Ui::Controls::EditField* pEditFieldLongitude_;
	Osp::Ui::Controls::EditField* pEditFieldLatitude_;

	Osp::Ui::Controls::Label* pLabelTitle_;
	Osp::Ui::Controls::Label* pLabelAuthor_;
	Osp::Ui::Controls::Label* pLabelID_;
	Osp::Ui::Controls::Label* pLabelLongitude_;
	Osp::Ui::Controls::Label* pLabelLatitude_;

	std::vector<Osp::Ui::Controls::IFormBackEventListener*> formBackListeners_;

};

#endif
