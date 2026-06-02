#include <iostream>
#include <vector>
using namespace std;

class FoodItem
{
public:
    virtual double getPrice() = 0;
    virtual void displayItem() = 0;

    virtual ~FoodItem() {}
};

class Pizza : public FoodItem
{
private:
    double price;

public:
    Pizza(double p)
    {
        this->price = p;
    }

    double getPrice() override
    {
        return price;
    }

    void displayItem() override
    {
        cout << "Pizza price is : " << price << endl;
    }
};

class Burger : public FoodItem
{
private:
    double price;

public:
    Burger(double p)
    {
        this->price = p;
    }

    double getPrice() override
    {
        return price;
    }

    void displayItem() override
    {
        cout << "Burger price is : " << price << endl;
    }
};

class Pasta : public FoodItem
{
private:
    double price;

public:
    Pasta(double p)
    {
        this->price = p;
    }

    double getPrice() override
    {
        return price;
    }

    void displayItem() override
    {
        cout << "Pasta price is : " << price << endl;
    }
};

int main()
{
    // FoodItem *pizza = new Pizza(10.99);
    // FoodItem *burger = new Burger(5.99);
    // FoodItem *pasta = new Pasta(8.99);

    // pizza->displayItem();
    // burger->displayItem();
    // pasta->displayItem();

    // delete pizza;
    // delete burger;
    // delete pasta;

    vector<FoodItem *> order;

    order.push_back(new Pizza(250));
    order.push_back(new Burger(120));
    order.push_back(new Pasta(180));

    double totalBill = 0;

    cout << "Order Details:\n";

    for (FoodItem *item : order)
    {
        item->displayItem();
        totalBill += item->getPrice();
    }

    cout << "\nTotal Bill = Rs." << totalBill << endl;

    // Free memory
    for (FoodItem *item : order)
    {
        delete item;
    }

    return 0;
}