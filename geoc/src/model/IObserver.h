/*
 * IObserver.h
 *
 *  Created on: 23.02.2015
 *      Author: furylynx
 */

#ifndef IOBSERVER_H_
#define IOBSERVER_H_

namespace geo
{

	template <typename T>
	class IObserver
	{
	public:
		virtual ~IObserver(){}

		virtual void OnUpdate(T* item) = 0;
	};

} // namespace geo

#endif /* IOBSERVER_H_ */
