#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

class Transport {
public:
    virtual std::string getDescription() const = 0;
    virtual ~Transport() {}
};

class Car : public Transport {
public:
    std::string getDescription() const override {
        return "You received a car. Lamborghini Urus. Engine capacity - 4 l, power - 650 hp, gearbox - automatic, all-wheel drive.";
    }
};

class Truck : public Transport {
public:
    std::string getDescription() const override {
        return "You received a truck.  Ideal for heavy construction and transport tasks. Equipped with a 400 hp engine and a ZF16 gearbox";
    }
};

class Shop {
public:
    virtual Transport* provideTransport() = 0;
    virtual ~Shop() {}
};

class CarShop : public Shop {
public:
    Transport* provideTransport() override {
        return new Car();
    }
};

class TruckShop : public Shop {
public:
    Transport* provideTransport() override {
        return new Truck();
    }
};

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));
    std::vector<Shop*> shops = { new CarShop(), new TruckShop() };

    int randomIndex = std::rand() % shops.size();
    Shop* selectedShop = shops[randomIndex];

    Transport* transport = selectedShop->provideTransport();
    std::cout << transport->getDescription() << std::endl;
    delete transport;
    delete selectedShop;
    return 0;
}
