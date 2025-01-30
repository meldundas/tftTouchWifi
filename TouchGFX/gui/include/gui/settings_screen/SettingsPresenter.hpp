#ifndef SETTINGSPRESENTER_HPP
#define SETTINGSPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

#include "main.h"


using namespace touchgfx;

class SettingsView;

class SettingsPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    SettingsPresenter(SettingsView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~SettingsPresenter() {}

    void changeWifi(uint8_t opt);

    void newWifiInfo(uint8_t* ipWifi);

    void changeWifi(char selection);

private:
    SettingsPresenter();

    SettingsView& view;
};

#endif // SETTINGSPRESENTER_HPP
