
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
	public Osp::Ui::IActionEventListener,
    public Osp::Ui::Controls::IListViewItemEventListener,
    public Osp::Ui::Controls::IListViewItemProvider,
    public geo::IObserver<geo::Entry>
{

// Construction
public:
	CachesForm(void);
	virtual ~CachesForm(void);

	virtual bool Initialize(CacheDetailsForm* pCacheDetails, geo::EntryController* pEntryController);

	virtual result OnInitializing(void);

	virtual result OnTerminating(void);

	//Action listener
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);

    //IListViewItemEventListener
    virtual void OnListViewContextItemStateChanged(Osp::Ui::Controls::ListView &listView, int index, int elementId, Osp::Ui::Controls::ListContextItemStatus state);
    virtual void OnListViewItemStateChanged(Osp::Ui::Controls::ListView &listView, int index, int elementId, Osp::Ui::Controls::ListItemStatus status);
    virtual void OnListViewItemSwept(Osp::Ui::Controls::ListView &listView, int index, Osp::Ui::Controls::SweepDirection direction);

    // IListViewItemProvider
    virtual Osp::Ui::Controls::ListItemBase* CreateItem(int index, int itemWidth);
    virtual bool DeleteItem(int index, Osp::Ui::Controls::ListItemBase* pItem, int itemWidth);
    virtual int GetItemCount();

    //IObserver
    virtual void OnUpdate(geo::Entry* item);

    //custom methods
    //...

// Implementation
private:
	static const int ID_FOOTER_BUTTON_ADD = 201;

	Osp::Ui::Controls::ListView *pListView_;

// Generated call-back functions
public:
	CacheDetailsForm* pCacheDetails_;

	geo::EntryController* pEntryController_;


};

#endif
