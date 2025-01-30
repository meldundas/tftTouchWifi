#include <gui/settings_screen/SettingsView.hpp>

SettingsView::SettingsView()
{

}

void SettingsView::setupScreen()
{
    SettingsViewBase::setupScreen();
}

void SettingsView::tearDownScreen()
{
    SettingsViewBase::tearDownScreen();
}

void SettingsView::setWifiInfo(uint8_t* ipWifi)
{

	Unicode::UnicodeChar uniBuffer[20];
	Unicode::fromUTF8(ipWifi, uniBuffer, 20);

	Unicode::snprintf(ipAddressBuffer,IPADDRESS_SIZE, "%s", uniBuffer);
	ipAddress.invalidate();
}
