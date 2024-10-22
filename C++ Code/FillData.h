#pragma once
#include "Validation.h"


class FillData
{
public:
	static string enterName() {
		string name;
		cout << "Please Enter your Name: ";
		getline(cin, name);
		while (!Validation::checkname(name)) {
			cout << "Please Enter Valid Name\n";
			getline(cin, name);
		}
		return name;
	}

	static string enterPassword() {
		string password;
		cout << "\nPlease Enter your Password: ";
		getline(cin, password);
		while (!Validation::checkpassword(password)) {
			cout << "Please Enter Valid Password\n";
			getline(cin, password);
		}
		return password;
	}

	static double enterBalance() {
		double balance;
		cout << "\nPlease Enter Client's Balance: ";
		cin>>balance;
		while (!Validation::checkbalance(balance)) {
			cout << "Please Enter Valid Balane\n";
			cin>>balance;
		}
		return balance;
	}

	static double enterSalary() {
		double salary;
		cout << "\nPlease Enter Employee's Salary: ";
		cin >> salary;
		while (!Validation::checksalary(salary)) {
			cout << "Please Enter Valid Salary\n";
			cin >> salary;
		}
		return salary;
	}
};

