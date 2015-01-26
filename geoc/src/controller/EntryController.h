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

	virtual void Construct();

	virtual void AddEntry(Entry* entry);
	virtual void AddEntry(Osp::Base::String title, float longitude, float latitude);

	virtual std::vector<geo::Entry*> GetEntries() const;

	virtual std::vector<geo::Entry*> GetActiveEntries() const;

	virtual void ImportEntries(Osp::Base::String path);

	virtual unsigned int Size() const;

protected:

private:
	std::vector<geo::Entry*> entries_;

};

}//namespace geo

#endif /* ENTRYCONTROLLER_H_ */
