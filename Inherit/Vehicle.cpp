#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
protected:
    string color;
    int speed;

public:
    Vehicle(string c, int s) : color(c), speed(s) {}

    void move()
    {
        cout << "The vehicle is moving at " << speed << " km/h." << endl;
    }

    void setColor(string c)
    {
        color = c;
    }

    string getColor()
    {
        return color;
    }
};

class Bicycle : public Vehicle
{
private:
    bool hasBasket;

public:
    Bicycle(string c, int s, bool basket) : Vehicle(c, s), hasBasket(basket) {}

    void ringBell()
    {
        cout << "Ring My Bell" << endl;
    }
};

class Truck : public Vehicle
{
private:
    int cargoCapacity;

public:
    Truck(string c, int s, int capacity) : Vehicle(c, s), cargoCapacity(capacity) {}

    void loadCargo()
    {
        cout << "Cargo Capacity : " << cargoCapacity << endl;
    }
};

int main()
{
    Truck *truck = new Truck("yellow", 10, 10);

    cout << truck->getColor() << endl;
    truck->loadCargo();
    truck->move();

    Bicycle *bicycle = new Bicycle("black", 10, false);
    cout << bicycle->getColor() << endl;
    bicycle->ringBell();
    bicycle->move();
}