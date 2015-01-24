/*
 * CompassController.h
 *
 *  Created on: 24.01.2015
 *      Author: furylynx
 */

#ifndef COMPASSCONTROLLER_H_
#define COMPASSCONTROLLER_H_

//custom includes
//...

//global includes



class CompassController
{
	public:
		CompassController();
		virtual ~CompassController();

		virtual void Construct();

		virtual float CalculateCompassDegree(float magX, float magY, float magZ, float azimuth, float pitch, float roll);
};

#endif /* COMPASSCONTROLLER_H_ */
