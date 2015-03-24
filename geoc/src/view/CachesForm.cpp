
#include "CachesForm.h"

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;


CachesForm::CachesForm(void)
{
}

CachesForm::~CachesForm(void)
{
}

bool CachesForm::Initialize(CacheDetailsForm* pCacheDetails, geo::EntryController* pEntryController)
{
	pCacheDetails_ = pCacheDetails;
	pEntryController_ = pEntryController;

	Form::Construct(L"IDF_CACHES");

	return true;
}

result CachesForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	GetFooter()->AddActionEventListener(*this);

	pListView_ = static_cast<ListView *>(GetControl(L"IDC_LISTVIEW"));

	pListView_->SetItemProvider(*this);
	pListView_->AddListViewItemEventListener(*this);

	pListView_->UpdateList();

	return r;
}

result CachesForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	// TODO: Add your termination code here

	return r;
}

void CachesForm::OnActionPerformed(const Osp::Ui::Control& source, int actionId)
{
	AppLog("Action performed! \n");

	switch(actionId)
	{
		case ID_FOOTER_BUTTON_ADD:
		{
			AppLog("ADD Button is clicked! \n");

			//create a new entry
			geo::Entry* entry = new geo::Entry();
			entry->Construct();

			pEntryController_->AddEntry(entry);

			pListView_->UpdateList();

			//update the details form
			pCacheDetails_->Update(entry);

			//show details form
			Osp::App::Application::GetInstance()->GetAppFrame()->GetFrame()->SetCurrentForm(*pCacheDetails_);
			pCacheDetails_->Draw();
			pCacheDetails_->Show();
		}
		break;
		default:
		break;
	}
}

void CachesForm::OnListViewItemStateChanged(Osp::Ui::Controls::ListView &listView, int index, int elementId, Osp::Ui::Controls::ListItemStatus status)
{
	if (static_cast<std::size_t>(index) < pEntryController_->Size())
	{
		//update the details form
		pCacheDetails_->Update(pEntryController_->At(index));

		//show details form
		Osp::App::Application::GetInstance()->GetAppFrame()->GetFrame()->SetCurrentForm(*pCacheDetails_);
		pCacheDetails_->Draw();
		pCacheDetails_->Show();
	}

}

void CachesForm::OnListViewItemSwept(Osp::Ui::Controls::ListView &listView, int index, Osp::Ui::Controls::SweepDirection direction)
{
	//allow removal here? -> new item that allow removal of the entry
}

void CachesForm::OnListViewContextItemStateChanged(Osp::Ui::Controls::ListView &listView, int index, int elementId, Osp::Ui::Controls::ListContextItemStatus state)
{
    switch (elementId)
    {
    case ID_CONTEXT_ITEM_DELETE:
        //TODO remove item...
        break;
    default:
    	//TODO handle item state change?!
    	break;
    }
}

int CachesForm::GetItemCount(void)
{
    return pEntryController_->Size();
}

Osp::Ui::Controls::ListItemBase* CachesForm::CreateItem(int index, int itemWidth)
{
    ListAnnexStyle style = LIST_ANNEX_STYLE_NORMAL;
    CustomItem* pItem = new CustomItem();
    pItem->Construct(Osp::Graphics::Dimension(itemWidth,100), style);

    //get the entry
    geo::Entry* entry = pEntryController_->At(index);

    pItem->AddElement(Osp::Graphics::Rectangle(80, 25, 200, 50), 900+index, entry->ToString(), true);

//    switch (index % 3)
//    {
//    case 0:
//        pItem->AddElement(Rectangle(80, 25, 200, 50), ID_FORMAT_STRING, L"HOME", true);
//        break;
//    case 1:
//        pItem->AddElement(Rectangle(80, 25, 200, 50), ID_FORMAT_STRING, L"Msg", true);
//        break;
//    case 2:
//        pItem->AddElement(Rectangle(80, 25, 200, 50), ID_FORMAT_STRING, L"Alarm", true);
//        break;
//    default:
//        break;
//    }
    //pItem->AddElement(Rectangle(290, 20, 60, 60), ID_FORMAT_CUSTOM, *(static_cast<ICustomElement *>(__pCustomListElement)));

    //TODO context item...
    ListContextItem* pItemContext = new ListContextItem();
    pItemContext->Construct();
    pItemContext->AddElement(101, "Löschen");
    //pItemContext->AddElement(101, "Test2");
    pItem->SetContextItem(pItemContext);


    return pItem;
}

bool CachesForm::DeleteItem(int index, Osp::Ui::Controls::ListItemBase* pItem, int itemWidth)
{
    delete pItem;
    pItem = null;
    return true;
}

void CachesForm::OnUpdate(geo::Entry* item)
{
	pListView_->UpdateList();

	//AppLog("Update Caches.");
}



