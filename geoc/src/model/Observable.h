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
#include <FBase.h>
#include <vector>

namespace geo
{


	template <typename T>
	class Observable : geo::IObservable<T>
	{
		public:
			Observable();
			virtual ~Observable();

			virtual void AddObserver(geo::IObserver<T>* observer);
			virtual void RemoveObserver(geo::IObserver<T>* observer);
			virtual void NotifyObservers(T* item) const;


		private:
			std::vector<geo::IObserver<T>* > observers_;
			Osp::Base::Runtime::Mutex* pMutex_;
	};

} // namespace geo





//----------------------- IMPLEMENTATION -----------------------------//


namespace geo
{

template<typename T>
Observable<T>::Observable()
{
	pMutex_ = new Osp::Base::Runtime::Mutex();
	pMutex_->Create();
}

template<typename T>
Observable<T>::~Observable()
{
	delete pMutex_;
}

template<typename T>
void Observable<T>::AddObserver(geo::IObserver<T>* observer)
{
	pMutex_->Acquire();

	observers_.push_back(observer);

	pMutex_->Release();
}

template<typename T>
void Observable<T>::RemoveObserver(geo::IObserver<T>* observer)
{
	pMutex_->Acquire();

	for (std::size_t i = 0; i < observers_.size(); i++)
	{
		if (observer == observers_.at(i))
		{
			observers_.erase(observers_.begin() + i);
			break;
		}
	}

	pMutex_->Release();
}

template<typename T>
void Observable<T>::NotifyObservers(T* item) const
{
	pMutex_->Acquire();

	for (std::size_t i = 0; i < observers_.size(); i++)
	{
		observers_.at(i)->OnUpdate(item);
	}

	pMutex_->Release();
}

} // namespace geo



#endif /* OBSERVER_H_ */
