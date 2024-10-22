#pragma once
#include <iostream>
#include <string>

using namespace std;


class Validation {
public:
    static bool checkname(string name) {
        if (name.size() < 5 || name.size() > 40) {
            cout << "Invalid Name!\nName length must be between 5 and 40\n";
            return false;
        }
        for (int i = 0; i < name.size(); i++) {
            if (!((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || name[i] == ' ')) {
                cout << "Invalid Name!\nName must contain only alphabetic characters or spaces\n";
                return false;
            }
        }
        return true;
    }

    static bool checkpassword(string password) {
        if (password.size() < 8 || password.size() > 20) {
            cout << "Invald password!\npassword length must be between 8 and 20\n";
            return false;
        }
        for (int i = 0; i < password.size(); i++) {
            if (password[i] == ' ') {
                cout << "Invald password!\npassword must not contain spaces\n";
                return false;
            }
        }
        return true;
    }

    static bool checkbalance(double balance) {
        if (balance < 1500) {
            cout << "Invalid balance!\nbalance must be at least 1500\n";
            return false;
        }
        return true;
    }

    static bool checksalary(double salary) {
        if (salary < 5000) {
            cout << "Invalid salary!\nsalary must be at least 5000\n";
            return false;
        }
        return true;
    }

};