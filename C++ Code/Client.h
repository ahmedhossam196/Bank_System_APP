#pragma once
#include "Person.h"
class Client :
    public Person
{
    double balance;
public:
    //default constructor
    Client() :balance(0) {}
    //parameterized constructor
    Client(int id, string name, string password, double balance)
        :Person(id, name, password)
    {
        if (Validation::checkbalance(balance)) {
            this->balance = balance;
        }
    }
    //Setters
    void setBalance(double balance) {
        if (Validation::checkbalance(balance)) {
            this->balance = balance;
        }
    }
    
    //Getters
    double CheckBalance() {
        system("pause");
        return balance;

    }
    //functions 
    void Deposit(double amount) {
        this->balance += amount;
        cout << "\nsuccessful Transaction\n";
    }
    void Withdraw(double amount) {
        if (amount > this->balance) {
            cout << "unsufficient balance";
        }
        else { this->balance -= amount;
        cout << "\nsuccessful Transaction\n";
        }
    }
    void TransferTo(double amount, Client& x) {
        if (amount > this->balance) {
            cout << "unsufficient balance";
        }
        else { this->balance -= amount;
        x.balance += amount;
        cout << "\nsuccessful Transaction\n";
        }
    }
    void displayInfo() {
        cout << "Client Information\n";
        Person::Displayinfo();
        cout << "Balance:" << CheckBalance() << endl;
    }
};
static vector<Client> allClients;
static vector<Client> ::iterator clientIt;
