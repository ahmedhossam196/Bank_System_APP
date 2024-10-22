#pragma once
#include <iostream>
#include "Validation.h"
using namespace std;

class Person
{
protected:
	string name, password;
	int id;
	void Displayinfo() {
			cout << "Id:" << getId() << endl
				<< "Name:" << getName() << endl
			<< "password:" << getPassword() << endl;
	}
public:
	//default constructor
	Person() {
		id = 0;
		name = "";
		password = "";
	}
	//parameterized constructor
	Person(int id,string name,string password)
		:id(id)
	{
		if (Validation::checkname(name)) {
			this->name = name;
		}
		if (Validation::checkpassword(password)) {
			this->password = password;
		}  
	}
	
	//Getters
	string getName() {
		return name;
	}
	string getPassword() {
		return password;
	}
	int getId() {
		return id;
	}
	//Setters
	void setName(string name) {
		if (Validation::checkname(name)) {
			this->name = name;
		}
	}
	void setPassword(string password) {
		this->password = Validation::checkpassword(password);
	}
	virtual void displayInfo() = 0;
};

