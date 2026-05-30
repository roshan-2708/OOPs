#include <iostream>
using namespace std;

class bankAccount
{

private:
    string accountHolderName;
    double balance;

public:
    // default constructor
    bankAccount()
    {
        accountHolderName = "Unknown";
        balance = 0.0;
    }
    // parameterized constructor
    bankAccount(string name, double balance)
    {
        accountHolderName = name;
        this->balance = balance;
    }

    // getter for accountHolderName
    string getAccountHolderName()
    {
        return accountHolderName;
    }

    // getter for balance
    double getBalance()
    {
        return balance;
    }

    // setter for accountHolderName
    void setAccountHolderName(string name)
    {
        accountHolderName = name;
    }

    // setter for balance
    void setbalance(double balance)
    {
        this->balance = balance;
    }

    // deposit function
    void deposite(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposited : " << amount << endl;
        }
        else
        {
            cout << "invalid amount" << endl;
        }
    }

    // withdraw function
    void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "withdrawn : " << amount << endl;
        }
        else
        {
            cout << "Invalid amount or insufficient balance" << endl;
        }
    }
};

int main()
{

    bankAccount account1("John Doe", 1000.0);

    cout << "Account Holder Name : " << account1.getAccountHolderName() << endl;
    cout << "Initial balance : " << account1.getBalance() << endl;

    account1.deposite(500.0);
    cout << "Balance after deposit : " << account1.getBalance() << endl;

    account1.withdraw(200.0);
    cout << "Balance after withdrawal : " << account1.getBalance() << endl;

    return 0;
}