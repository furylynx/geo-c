/*
 * Observer.h
 *
 *  Created on: 23.02.2015
 *      Author: furylynx
 */

#ifndef OBSERVER_H_
#define OBSERVER_H_

//custom includes
#include "IObservable.h"


//global includes
//...

namespace geo
{


	template <typename T>
	class Observable : geo::IObservable<T>
	{
		public:
			Observable();
			virtual ~Observer();

			virtual void AddObserver(geo::IObserver<T> observer*);
			virtual void RemoveObserver(geo::IObserver<T> observer*);
			virtual void NotifyObservers() const;


		private:
			std::vector<geo::IObserver<T> > observers_;
	};

} // namespace geo





//----------------------- IMPLEMENTATION -----------------------------//


namespace geo
{

void Observable<typename T>::AddObserver(geo::IObserver<T> observer*)
{
	//TODO implement
}

void Observable<typename T>::RemoveObserver(geo::IObserver<T> observer*)
{
	//TODO implement
}

void Observable::NotifyObservers() const
{
	//TODO implement
}

} // namespace geo



#endif /* OBSERVER_H_ */
