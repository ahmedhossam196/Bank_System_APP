#pragma once
#include <iostream>
#include <stdlib.h>
#include <chrono>
#include <thread>
#include <windows.h>
#include "AdminManager.h"
#include "EmployeeManager.h"
#include "ClientManager.h"
#include "FileManager.h"  // Make sure to include necessary headers for dependencies
using namespace std;

class Screens {
private:
    static void bankName() {
        cout << "El Mazra3a";
    }


    static void welcome() {
        cout << "Welcome To ";
        bankName();
        Sleep(3000);  // Pause for a few seconds
        system("cls");  // Clear the screen
    }

    static void loginOptions() {
        cout << "1- Admin" << endl;
        cout << "2- Employee" << endl;
        cout << "3- Client\n" << endl;
        cout << "Login as: ";
    }

    static int loginAs() {
        loginOptions();
        int choice;
        cin >> choice;
        if (choice >= 1 && choice <= 3) {
            system("cls");
            return choice;  // Return valid choice
        }
        else {
            system("cls");
            return loginAs();  // Repeat until valid input
        }
    }

    static void invalid(int c) {
        system("cls");
        cout << "Incorrect id or password." << endl;
        loginScreen(c);  // Prompt login again for the specific type
    }

    static void logout() {
        system("cls");
        loginScreen(loginAs());  // Start login process again
    }

    static void loginScreen(int c) {
        int id;
        string pass;
        cout << "Enter id: ";
        cin >> id;
        cout << "Enter password: ";
        cin >> pass;
        switch (c) {
        case 1:  // Admin
            if (AdminManager::login(id, pass) != NULL) {
                while (AdminManager::AdminOptions(AdminManager::login(id, pass)) != false);
                logout();
            }
            else {
                invalid(1);
            }
            break;
        case 2:  // Employee
            if (EmployeeManager::login(id, pass) != NULL) {
                while (EmployeeManager::employeeOptions(EmployeeManager::login(id, pass)) != false);
                logout();
            }
            else {
                invalid(2);
            }
            break;
        case 3:  // Client
            if (ClientManager::login(id, pass) != NULL) {
                while (ClientManager::clientOptions(ClientManager::login(id, pass)) != false);
                logout();
            }
            else {
                invalid(3);
            }
            break;
        default:
            system("cls");
            loginOptions();  // Repeat login options if invalid choice
        }
    }

public:
    static void runApp() {
        FileManager::getAllData();  // Load data from file
        welcome();  // Show welcome message
        loginScreen(loginAs());  // Start the login process
    }
};
