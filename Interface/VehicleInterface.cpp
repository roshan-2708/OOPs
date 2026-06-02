#include <iostream>
using namespace std;

class VehicleInterface
{
public:
    virtual void start() = 0;
    virtual void stop() = 0;

    virtual ~VehicleInterface() {}
};

class car : public VehicleInterface
{
public:
    void start() override
    {
        cout << "Car is starting." << endl;
    }
    void stop() override
    {
        cout << "Car is stopping." << endl;
    }
};

class bike : public VehicleInterface
{
public:
    void start() override
    {
        cout << "Bike is starting." << endl;
    }
    void stop() override
    {
        cout << "Bike is stopping." << endl;
    }
};

int main()
{
    VehicleInterface *myCar = new car();
    VehicleInterface *myBike = new bike();

    myCar->start();
    myCar->stop();

    myBike->start();
    myBike->stop();

    delete myCar;
    delete myBike;

    myCar->start();

    return 0;
}