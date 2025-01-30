#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

Screen1Presenter::Screen1Presenter(Screen1View& v)
    : view(v)
{

}

void Screen1Presenter::activate()
{

}

void Screen1Presenter::deactivate()
{

}

void Screen1Presenter::newButtonValue(bool button)
{
	view.setButtonState(button);
}

void Screen1Presenter::swButton(char selection)
{
	model->toggleLed(selection);
}

void Screen1Presenter::newTemp(float Temp)
{
	view.setTemp(Temp);
}


void Screen1Presenter::newWifiStatus(bool status)
{
	view.setStatus(status);
}
