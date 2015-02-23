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

#include <vector>


namespace geo
{

class EntryController
{
public:
	EntryController();
	virtual ~EntryController();

	virtual void Construct();

	virtual void AddEntry(Entry* entry);
	virtual void AddEntry(Osp::Base::String title, float longitude, float latitude);

	virtual std::vector<geo::Entry*> GetEntries() const;

	virtual std::vector<geo::Entry*> GetActiveEntries() const;

	virtual geo::Entry* At(std::size_t index) const;

	virtual bool ImportEntries(Osp::Base::String path);

	virtual std::size_t Size() const;

protected:

private:
	std::vector<geo::Entry*> entries_;
	IOControllerLOC ioCtrl_;

};

}//namespace geo

#endif /* ENTRYCONTROLLER_H_ */
