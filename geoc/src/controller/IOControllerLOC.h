/*
 * IOControllerLOC.h
 *
 *  Created on: 27.01.2015
 *      Author: John
 */

#ifndef IOCONTROLLERLOC_H_
#define IOCONTROLLERLOC_H_

//custom includes
#include "../model/Entry.h"

//global includes
#include <FBase.h>
#include <FXml.h>

#include <sstream>
#include <cstdlib>

namespace geo
{

class IOControllerLOC
{
public:
	IOControllerLOC();
	virtual ~IOControllerLOC();

	virtual void Construct();

	virtual result ParseLOC(Osp::Base::String path, geo::Entry* outEntry);
	virtual result WriteToLOC(Osp::Base::String path, geo::Entry* entry);

};

}//namespace geo

#endif /* IOCONTROLLERLOC_H_ */
