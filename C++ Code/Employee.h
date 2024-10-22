#pragma once
#include <vector>
#include <iterator>
#include "Client.h"

class Employee : public Person {
private:
    double salary;
public:
    
    //default const
    
    Employee() : Person() {
        salary = 0;
    }
    
    //paramet const
    
    Employee(int id, string name, string password, double salary)
        : Person(id, name, password) {
        if (Validation::checksalary(salary)) {
            this->salary = salary;
        }
       
    }

    //setters

    void setSalary(double salary) {
        if (Validation::checksalary(salary)) {
            this->salary = salary;
        }
       
    }

  //Getters

    double getSalary() {
        return salary;
    }
    
    //display info

    void displayInfo() {
        cout << "Employee Information\n";
        Person::Displayinfo();
        cout << "Salary: " << salary << endl;
    }

    //Methods

    void addClient(Client& client) {
        allClients.push_back(client);
        cout << "Client added successfully." << endl;
    }


    Client* searchClient(int id) {
        for (clientIt = allClients.begin(); clientIt != allClients.end(); clientIt++) {
            if (clientIt->getId() == id) {
                return clientIt._Ptr;
            }
        }
        return nullptr;
    }

    void listClient() {
        if (allClients.empty()) {
            cout << "No clients available." << endl;
            return;
        }
        for (clientIt = allClients.begin(); clientIt != allClients.end(); clientIt++) {
            clientIt->displayInfo();
            cout << "===============================" << endl;
        }
    }

    void editClient(int id, string name, string password, double balance) {
        if (searchClient(id) == NULL) {
            cout << "Client Not found!\n";
        }
        else {
            searchClient(id)->setName(name);
            searchClient(id)->setPassword(password);
            searchClient(id)->setBalance(balance);
        }
    }
};
static vector<Employee> allEmployees;
static vector<Employee> ::iterator employeeIt;