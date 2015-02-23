/*
 * IObservable.h
 *
 *  Created on: 23.02.2015
 *      Author: furylynx
 */

#ifndef IOBSERVABLE_H_
#define IOBSERVABLE_H_

//custom includes
#include "IObserver.h"

//global includes
//...

namespace geo
{
	template <typename T>
	class IObservable
	{
	public:
		virtual ~IObservable(){}

		virtual void AddObserver(geo::IObserver<T> observer*) = 0;
		virtual void RemoveObserver(geo::IObserver<T> observer*) = 0;
		virtual void NotifyObservers() const = 0;
	};

}// namespace geo

#endif /* IOBSERVABLE_H_ */
