#pragma once
#include <vector>
#include "EmployeeManager.h"
#include "FileManager.h"

class AdminManager {
public:
    // a. Static method to print admin menu options
    static void printAdminMenu() {
        system("cls"); // Clear the screen
        cout << "(1) Display Admin Info" << endl;
        cout << "(2) Update Password" << endl;
        cout << "(3) Add new client" << endl;
        cout << "(4) Search for client" << endl;
        cout << "(5) List all clients" << endl;
        cout << "(6) Edit client info" << endl;
        cout << "(7) Logout" << endl;
    }

    // b. Static method to simulate admin login
    static Admin* login(int id, string password) {
        for (auto& admin : allAdmins) {
            if (admin.getId() == id && admin.getPassword() == password) {
                cout << "Login successful.\n";
                return &admin;
            }
        }
        cout << "Login failed! Invalid ID or Password.\n";
        return nullptr;
    }

    // c. Static method to display admin-specific options for handling clients
    static bool AdminOptions(Admin* admin) {

        int option;
        do {
            printAdminMenu();
            cout << "Enter option: ";
            cin >> option;

            switch (option) {
            case 1:
                system("cls");
                admin->displayInfo(); // Display client information
                break;
            case 2:
                admin->setPassword(FillData::enterPassword()); // Update password
                FileManager::UpdateAdmins();
                break;
            case 3:
                EmployeeManager::newClient(admin); // Add new client
                break;
            case 4:
                EmployeeManager::searchForClient(admin); // Search for client
                break;
            case 5:
                EmployeeManager::listAllClients(admin); // List all clients
                break;
            case 6:
                EmployeeManager::editClientInfo(admin); // Edit client info
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
