
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

bool CachesForm::Initialize(CacheDetailsForm* pCacheDetails, CacheDetailsOverviewForm* pCacheDetailsOverview, geo::EntryController* pEntryController)
{
	pCacheDetails_ = pCacheDetails;
	pCacheDetailsOverview_ = pCacheDetailsOverview;
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
	//item from list is clicked

	if (static_cast<std::size_t>(index) < pEntryController_->Size())
	{
		//update the details form
		pCacheDetailsOverview_->Update(pEntryController_->At(index));

		//show details form
		Osp::App::Application::GetInstance()->GetAppFrame()->GetFrame()->SetCurrentForm(*pCacheDetailsOverview_);
		pCacheDetailsOverview_->Draw();
		pCacheDetailsOverview_->Show();
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
    {
        if (static_cast<std::size_t>(index) < pEntryController_->Size())
        {
        	pEntryController_->RemoveEntryAt(index);
        }
    }
        break;
    case ID_CONTEXT_ITEM_EDIT:
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
    pItem->Construct(Osp::Graphics::Dimension(itemWidth,55), style);

    //get the entry
    geo::Entry* entry = pEntryController_->At(index);

    pItem->AddElement(Osp::Graphics::Rectangle(2, 2, 400, 60), 900+index*2, entry->ToString(), true);
    //pItem->AddElement(Osp::Graphics::Rectangle(12, 55, 390, 50), 900+index*2+1, entry->Author(), true);
    //TODO add button for active flag

    //context item
    ListContextItem* pItemContext = new ListContextItem();
    pItemContext->Construct();
    pItemContext->AddElement(ID_CONTEXT_ITEM_DELETE, "Delete");
    pItemContext->AddElement(ID_CONTEXT_ITEM_EDIT, "Edit");
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



