#pragma once
#include <fstream>
#include "Parser.h"

class FilesHelper {
private:

	//save Last id
	
	static void saveLast(string fileName, int id) {
		ofstream file;
		file.open(fileName);
		file << id;
		file.close();
	}

public:
	//Get last id
	static int getLast(string fileName) {
		ifstream file;
		file.open(fileName);
		int id;
		file >> id;
		file.close();
		return id;
	}

	//Save Client

	static void saveClient(Client c) {
		int id = getLast("ClientLastId.txt");
		fstream file;
		file.open("Clients.txt", ios::app);
		file << id + 1 << ',' << c.getName() << ',' << c.getPassword() << ',' << c.CheckBalance() << "\n";
		file.close();
		saveLast("ClientLastId.txt", id + 1);
	}

	//Save Employee

	static void saveEmployee(string FileName,string LastId ,Employee e) {
		int id = getLast(LastId);
		ofstream file;
		file.open(FileName, ios::app);
		file << id + 1 << ',' << e.getName() << ',' << e.getPassword() << ',' << e.getSalary() << "\n";
		file.close();
		saveLast(LastId, id + 1);
	}

	//Get Clients

	static void getClients() {
		string line;
		ifstream file;
		file.open("Clients.txt");
		if (file.is_open())
		{
			cout << "\t\tClients Information\n";
			while (getline(file, line))
			{
				Client c = Parser::parseToClient(line);
				allClients.push_back(c);
			}
			file.close();
		}
		file.close();
	}

	//Get Employees

	static void getEmployees() {
		string line;
		ifstream file;
		file.open("Employees.txt");
		if (file.is_open())
		{
			cout << "\t\tEmployees Information\n";
			while (getline(file, line))
			{
				Employee c = Parser::parseToEmployee(line);
				allEmployees.push_back(c);
			}
		}
		file.close();
	}

	//Get Admins

	static void getAdmins() {
		string line;
		ifstream file;
		file.open("Admins.txt");
		if (file.is_open())
		{
			cout << "\t\tAdmins Information\n";
			while (getline(file, line))
			{
				Admin c = Parser::parseToAdmin(line);
				allAdmins.push_back(c);
			}
			file.close();
		}
		file.close();
	}
	
	//Get All Data
	static void getAllData() {
		cout << "\t\tClients Informations\n";
		getClients();
		cout << "\t\tEmployees Informations\n";
		getEmployees();
		cout << "\t\tAdmins Informations\n";
		getAdmins();
	}


	//Clear File

	static void clearFile(string fileName, string lastIdFile) {
		ofstream file1, file2;
		file1.open(fileName, ios::out);
		file1.close();
		file2.open(lastIdFile, ios::out);
		file2 << 0;
		file2.close();
	}
}; 