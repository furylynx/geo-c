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


//global includes
#include <FBase.h>

#include <vector>


namespace geo
{

class EntryController
{
public:
	EntryController();
	virtual ~EntryController();

	virtual void AddEntry(Osp::Base::String title, float longitude, float latitude);

	virtual std::vector<geo::Entry> GetEntries() const;

protected:

private:
	std::vector<geo::Entry> entries_;

};

}

#endif /* ENTRYCONTROLLER_H_ */
