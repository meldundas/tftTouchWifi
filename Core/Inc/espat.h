/*
 * espat.h
 *
 *  Created on: Jan 31, 2025
 *      Author: meldu
 */

#ifndef INC_ESPAT_H_
#define INC_ESPAT_H_

#include <stdio.h>
#include "main.h"
#include "atc.h"
#include "secrets.h"


//const ATC_EventTypeDef events[] = { { "+IPD", cbCallReady } };



int WiFiConnect();
int sendToThingspeak();
int getNTP();
int sendToMQTT();

#endif /* INC_ESPAT_H_ */
