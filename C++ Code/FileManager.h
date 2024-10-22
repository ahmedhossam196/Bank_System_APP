#pragma once
#include <fstream>
#include "DataSourceInterface.h"
#include "FileHelper.h"


class FileManager : public DataSourceInterface {
private:

    //Add client

    static void addClient(Client client)  {
        FilesHelper::saveClient(client);
    }

    //Add Employee

    static void addEmployee(Employee employee)  {
        FilesHelper::saveEmployee("Employees.txt","EmployeeLastId.txt", employee);
    }

    //Add admin

    static void addAdmin(Admin admin)  {
        FilesHelper::saveEmployee("Admins.txt", "AdminLastId.txt", admin);
    }

    //Get clients 

    static void getAllClients()  {
        FilesHelper::getClients();
    }

    //Get Employees 

    static void getAllEmployees()  {
        FilesHelper::getEmployees();
    }

    //Get Admin 

   static void getAllAdmins()  {
       FilesHelper::getAdmins();
    } 
   

    //remove all clients 

    static void removeAllClients()  {
        FilesHelper::clearFile("Clients.txt", "ClientLastId.txt");
    }

    //remove all Employees

    static void removeAllEmployees()  {
        FilesHelper::clearFile("Employees.txt", "EmployeeLastId.txt");

    }
   
    //remove all Admins

    static void removeAllAdmins()  {
        FilesHelper::clearFile("Admins.txt", "AdminLastId.txt");

    }
public:
    //Get All Data

    static void getAllData() {
        FilesHelper::getAllData();
    }

    //Update the Data

    //Clients
    static void UpdateClients() {
        removeAllClients();
        for (clientIt = allClients.begin(); clientIt != allClients.end(); clientIt++) {
            addClient(*clientIt);
        }
    }

    //Employees
    static void UpdateEmployees() {
        removeAllEmployees();
        for (employeeIt = allEmployees.begin(); employeeIt != allEmployees.end(); employeeIt++) {
            addEmployee(*employeeIt);
        }
    }

    //Admins
    static void UpdateAdmins() {
        removeAllAdmins();
        for (adminIt = allAdmins.begin(); adminIt != allAdmins.end(); adminIt++) {
            addAdmin(*adminIt);
        }
    }
};
