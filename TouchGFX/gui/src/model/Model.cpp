#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

extern "C" {
#include <stdint.h>
#include "main.h"


extern bool buttonPressed;
extern void leds(char opt);
extern float thermTemp;
extern bool connected;
extern uint8_t localIP[20];
extern void joinAP(char selection);
}

bool Model::getButtonValue()
{
#ifndef SIMULATOR
	return buttonPressed;
#else
// Implementation for simulator
	return false;
#endif //SIMULATOR
}


void Model::toggleLed(char selection)
{
#ifndef SIMULATOR
	leds(selection);
#endif
}

void Model::connectAP(char selection)
{
#ifndef SIMULATOR
	joinAP(selection);
#endif
}

float Model::getTemp()
{
#ifndef SIMULATOR
	return thermTemp;
#else
// Implementation for simulator
	return 22.5;
#endif //SIMULATOR
}

bool Model::getWifiStatus()
{
#ifndef SIMULATOR
	return connected;
#else
// Implementation for simulator
	return false;
#endif //SIMULATOR
}


uint8_t* Model::getWifiInfo()
{
#ifndef SIMULATOR
	return localIP;
#else
// Implementation for simulator
	return false;
#endif //SIMULATOR
}



Model::Model() : modelListener(0)
{

}

void Model::tick()
{
	if(modelListener != 0)
	{
		modelListener->newButtonValue(getButtonValue());
		modelListener->newTemp(getTemp());
		modelListener->newWifiStatus(getWifiStatus());
		modelListener->newWifiInfo(getWifiInfo());
	}
}
