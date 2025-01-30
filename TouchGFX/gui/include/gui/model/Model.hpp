#ifndef MODEL_HPP
#define MODEL_HPP

#include "main.h"


class ModelListener;

class Model
{
public:
    Model();

    void bind(ModelListener* listener)
    {
        modelListener = listener;
    }

    void tick();
    bool getButtonValue();

    void toggleLed(char selection);

    float getTemp();

    bool getWifiStatus();

    uint8_t* getWifiInfo();

    void connectAP(char selection);
protected:
    ModelListener* modelListener;
};

#endif // MODEL_HPP
