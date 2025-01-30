#include <gui/settings_screen/SettingsView.hpp>
#include <gui/settings_screen/SettingsPresenter.hpp>



SettingsPresenter::SettingsPresenter(SettingsView& v)
    : view(v)
{

}

void SettingsPresenter::activate()
{

}

void SettingsPresenter::deactivate()
{

}

void SettingsPresenter::newWifiInfo(uint8_t* ipWifi)
{
	view.setWifiInfo(ipWifi);
}

void SettingsPresenter::changeWifi(char selection)
{
	model->connectAP(selection);
}
