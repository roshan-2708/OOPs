#include <iostream>
using namespace std;

class SmartDevice
{
protected:
    string deviceName;
    bool isOn;

public:
    // initializer
    SmartDevice(string name) : deviceName(name), isOn(false) {}

    virtual ~SmartDevice() {}

    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual void deviceStatus() const = 0;
};

class smartLight : public SmartDevice
{
private:
    int brightness;

public:
    smartLight(string name) : SmartDevice(name), brightness(50) {}

    void turnOn() override
    {
        isOn = true;
        cout << deviceName << "is now shining bright!" << endl;
    }

    void turnOff() override
    {
        isOn = false;
        cout << deviceName << "is now turn off" << endl;
    }

    void setBrightness(int level)
    {
        if (!isOn)
        {
            cout << "Can't set brightness" << deviceName << endl;
            return;
        }
        brightness = level;
        cout << deviceName << "brightness set to " << brightness << endl;
    }

    void deviceStatus() const override
    {
        cout << "[Light] " << deviceName << " -> Status: "
             << (isOn ? "ON" : "OFF") << " | Brightness: "
             << (isOn ? brightness : 0) << "%\n";
    }
};

class smartAc : public SmartDevice
{
private:
    int temperature;

public:
    smartAc(string name) : SmartDevice(name), temperature(16) {};

    void turnOn() override
    {
        isOn = true;
        cout << deviceName << "is now cooling" << endl;
    }

    void turnOff() override
    {
        isOn = false;
        cout << deviceName << "is now off" << endl;
    }

    void setTemperature(int temp)
    {
        if (!isOn)
        {
            cout << "Can't set temperature" << deviceName << endl;
            return;
        }
        temperature = temp;
        cout << deviceName << "Tempratrue set to " << temperature << endl;
    }

    void deviceStatus() const override
    {
        cout << "[Light] " << deviceName << " -> Status: "
             << (isOn ? "ON" : "OFF") << " | Tempreature: "
             << (isOn ? temperature : 0) << "%\n";
    }
};

int main()
{

    SmartDevice *bedroomAc = new smartAc("BedRoom Ac");

    bedroomAc->turnOn();
    smartAc *actualAc = dynamic_cast<smartAc *>(bedroomAc);

    if (actualAc)
    {
        actualAc->setTemperature(22);
    }
    bedroomAc->deviceStatus();

    delete bedroomAc;

    SmartDevice *livingRoomLight = new smartLight("Living room light");

    livingRoomLight->turnOn();

    smartLight *actualLight = dynamic_cast<smartLight *>(livingRoomLight);

    if (actualLight)
    {
        actualLight->setBrightness(80);
    }

    livingRoomLight->deviceStatus();

    delete livingRoomLight;
    return 0;
}