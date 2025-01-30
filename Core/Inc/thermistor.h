/*
 * thermistor.h
 *
 *  Created on: Sep 7, 2023
 *      Author: meldu
 */

#ifndef INC_THERMISTOR_H_
#define INC_THERMISTOR_H_

float  convertAnalogToTemperature(unsigned int analogReadValue);
float  approximateTemperatureFloat(unsigned int analogReadValue);
int approximateTemperatureInt(unsigned int analogReadValue);

#endif /* INC_THERMISTOR_H_ */
