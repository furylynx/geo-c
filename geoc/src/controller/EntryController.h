/*
 * EntryController.h
 *
 *  Created on: 24.01.2015
 *      Author: furylynx
 */

#ifndef ENTRYCONTROLLER_H_
#define ENTRYCONTROLLER_H_

//custom includes
#include "../model/Entry.h"
#include "IOControllerLOC.h"


//global includes
#include <FBase.h>
#include <FIo.h>
#include <FLocations.h>

#include <vector>
#include <cmath>


namespace geo
{

class EntryController
{
public:
	EntryController();
	virtual ~EntryController();

	virtual void Construct();

	virtual void AddEntry(Entry* entry);
	virtual void AddEntry(Osp::Base::String title, Osp::Base::String author, float longitude, float latitude);

	virtual void RemoveEntry(Entry* entry);
	virtual void RemoveEntryAt(std::size_t index);

	virtual std::vector<geo::Entry*> GetEntries() const;

	virtual std::vector<geo::Entry*> GetActiveEntries() const;

	virtual geo::Entry* GetClosestActiveEntry(const Osp::Locations::QualifiedCoordinates* coordinates) const;

	virtual geo::Entry* At(std::size_t index) const;

	virtual bool ImportEntries(Osp::Base::String path);

	virtual std::size_t Size() const;

	virtual void AddObserver(geo::IObserver<geo::Entry>* observer);

protected:

private:
	std::vector<geo::Entry*> entries_;
	std::vector<geo::IObserver<geo::Entry>*> observers_;
	IOControllerLOC ioCtrl_;

};

}//namespace geo

#endif /* ENTRYCONTROLLER_H_ */
