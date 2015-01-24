#ifndef _MAINFORM_H_
#define _MAINFORM_H_

//custom includes
//...

//global includes
#include <FBase.h>
#include <FUi.h>

class MainForm :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::IActionEventListener,
 	public Osp::Ui::ITouchEventListener
{

// Construction
public:
	MainForm(void);
	virtual ~MainForm(void);
	bool Initialize(void);

// Implementation
protected:
	static const int ID_BUTTON_OK = 101;
	Osp::Ui::Controls::Button *pButtonOk_;




public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);

	virtual void OnTouchDoublePressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchFocusIn(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchFocusOut(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchLongPressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchMoved(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchPressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
	virtual void OnTouchReleased(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
};

#endif	//_MAINFORM_H_
