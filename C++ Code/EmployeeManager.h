#pragma once
#include "Employee.h"
#include "FillData.h"
#include "Client.h"
#include "ClientManager.h"
#include "FileManager.h"
#include <vector>
#include <iterator>
using namespace std;

class EmployeeManager {
private:
    // Static method to print employee menu options
    static void printEmployeeMenu() {
        cout << "Employee Menu:\n";
        cout << "1. Display Employee Information\n";
        cout << "2. Update Employee Password\n";
        cout << "3. Add New Client\n";
        cout << "4. List All Clients\n";
        cout << "5. Search for a Client\n";
        cout << "6. Edit Client Information\n";
        cout << "7. Logout\n";
    }
  
public:

    // Static method to add a new client via an employee
    static void newClient(Employee* employee) {
        if (employee == nullptr) {
            cout << "Invalid Employee." << endl;
            return;
        }

        int id=FilesHelper::getLast("ClientLastId")+1;
        string name = FillData::enterName();
        string password = FillData::enterPassword();
        double balance = FillData::enterBalance();
        Client new_client(id, name, password, balance);
        employee->addClient(new_client);
        FileManager::UpdateClients();
        cout << "Client successfully added.\n";
    }

    // Static method to list all clients
    static void listAllClients(Employee* employee) {
        if (employee == nullptr) {
            cout << "Invalid Employee." << endl;
            return;
        }

        cout << "\nListing all clients:\n";
        employee->listClient();
    }

    // Static method to search for a client
    static void searchForClient(Employee* employee) {
        if (employee == nullptr) {
            cout << "Invalid Employee." << endl;
            return;
        }

        int id;
        cout << "\nEnter Client ID to search: ";
        cin >> id;

        if (employee->searchClient(id) == NULL) {

        cout << "Client not found!\n";
       }
        else {
            employee->searchClient(id)->displayInfo();
        }
    }

    // Static method to edit client information
    static void editClientInfo(Employee* employee) {
        if (employee == nullptr) {
            cout << "Invalid Employee." << endl;
            return;
        }

        int id;
        cout << "\nEnter Client ID to edit: ";
        cin >> id;

        if (employee->searchClient(id) == NULL) {

            cout << "Client not found!\n";
        }
        else {

            string name = FillData::enterName();
            string password = FillData::enterPassword();
            double balance = FillData::enterBalance();

            employee->editClient(id, name, password, balance);
            cout << "Client information updated successfully.\n";
        }
    }

    // Static method to simulate employee login
    static Employee* login(int id, const string& password) {
        for (auto& employee : allEmployees) {
            if (employee.getId() == id && employee.getPassword() == password) {
                cout << "Login successful.\n";
                return &employee;
            }
        }

        cout << "Login failed! Invalid ID or Password.\n";
        return nullptr;
    }

    // Static method to display employee-specific options
    static bool employeeOptions(Employee* employee) {
        if (employee == nullptr) {
            cout << "Invalid Employee." << endl;
            return false;
        }

        int option;
        do {
            printEmployeeMenu();
            cout << "Enter option: ";
            cin >> option;

            switch (option) {
            case 1:
               system("cls");
               employee->displayInfo();
                break;
            case 2:
                ClientManager::updatePassword(employee);
                FileManager::UpdateEmployees();
                break;
            case 3:
                newClient(employee);
                break;
            case 4:
                listAllClients(employee);
                break;
            case 5:
                searchForClient(employee);
                break;
            case 6:
                editClientInfo(employee);
                break;
            case 7:
                cout << "Logging out...\n";
                return false;
            default:
                cout << "Invalid option!" << endl;
            }
        } while (option != 7);

        return true;
    }
};
