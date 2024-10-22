#pragma once
#include <sstream>
#include <string>

class Parser
{
	//split
	static vector<string> split(const string& line) {
		vector<string> data;
		stringstream ss(line);
		string word;
		while (getline(ss, word, ',')) {
			data.push_back(word);
		}
		return data;
	}
public:
	//parse to client
	static Client parseToClient(const string& line) {
		auto m=split(line);
		return Client(stoi(m[0]), m[1], m[2], stod(m[3]));
	}
	//parse to employee
	static Employee parseToEmployee(const string& line) {
		auto m = split(line);
		return Employee(stoi(m[0]), m[1], m[2], stod(m[3]));
	}
	//parse to admin
	static Admin parseToAdmin(const string& line) {
		auto m = split(line);
		return Admin(stoi(m[0]), m[1], m[2], stod(m[3]));
	}
};

