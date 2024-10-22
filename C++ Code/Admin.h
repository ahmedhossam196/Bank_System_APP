#pragma once
#include "Employee.h"
using namespace std;

class Admin : public Employee {
protected:
public:
    //default constructor 
    Admin() : Employee()
    {}
   
    //parameterized constructor
    
    Admin(int id, string name, string password, double salary)
        : Employee(id, name, password, salary)
    {}
    
    //Methods
    //Add Employee 

    void addEmployee(Employee& employee) {
       allEmployees.push_back(employee);
        cout << "Employee added successfully." << endl;
    }

    //Search for Employee
    Employee* searchEmployee(int id) {
        for (employeeIt = allEmployees.begin(); employeeIt != allEmployees.end();employeeIt++) {
            if (employeeIt->getId() == id) {
                return employeeIt._Ptr;
            }
        }
        return nullptr;
    }

    //List Employees
    void listEmployee() {
        if (allEmployees.empty()) {
            cout << "No emplyees available." << endl;
            return;
        }
        for (employeeIt = allEmployees.begin(); employeeIt != allEmployees.end(); employeeIt++) {
            employeeIt->displayInfo();
            cout << "=====================" << endl;
        }
    }

    //Edit Employees Data
    void editEmployee(int id, string name, string password, double salary) {
        if (searchEmployee(id) == NULL) {
            cout << "Employee Not avalible!\n";
      }
        else {
            searchEmployee(id)->setName(name);
            searchEmployee(id)->setPassword(password);
            searchEmployee(id)->setSalary(salary);
        }
    }
};
static vector<Admin> allAdmins;
static vector<Admin> ::iterator adminIt;