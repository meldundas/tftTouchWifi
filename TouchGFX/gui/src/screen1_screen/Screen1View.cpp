#include <gui/screen1_screen/Screen1View.hpp>

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
}

void Screen1View::tearDownScreen()
{
    Screen1ViewBase::tearDownScreen();
}


void Screen1View::setButtonState(bool bstate)
{
//		ledOn.setVisible(bstate);
//		ledOff.setVisible(!bstate);
//
//		ledOn.invalidate();
//		ledOff.invalidate();
}


void Screen1View::setTemp(float Temp)
{
	Unicode::snprintfFloat(temperatureBuffer,TEMPERATURE_SIZE, "%0.0f", Temp);
	temperature.invalidate();
}

void Screen1View::setStatus(bool status)
{
	wifi0.setVisible(!status);
	wifi1.setVisible(status);

	wifi0.invalidate();
	wifi1.invalidate();
}
