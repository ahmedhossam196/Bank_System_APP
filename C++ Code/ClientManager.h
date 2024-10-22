#pragma once
#include "Client.h"
#include "Validation.h"
#include "FileManager.h"


using namespace std;

class ClientManager {
private:
    // Method to print the client menu
    static void printClientMenu() {
        system("cls"); // Clear screen before showing menu
        cout << "(1) Display my info" << endl;
        cout << "(2) Check balance" << endl;
        cout << "(3) Update Password" << endl;
        cout << "(4) Withdraw" << endl;
        cout << "(5) Deposit" << endl;
        cout << "(6) Transfer amount" << endl;
        cout << "(7) Logout\n" << endl;
    }

public:
    // Method to update the password of a person
    static void updatePassword(Person* person) {
        string newPassword;
        cout << "Enter new password: ";
        cin >> newPassword;
        person->setPassword(newPassword); // Assuming the setPassword method is implemented
        cout << "\nPassword updated.\n";
    }

    // Method to login a client
    static Client* login(int id, string password) {
        for (auto& client : allClients) { // Assuming allClients is accessible here
            if (client.getId() == id && client.getPassword() == password) {
                return &client; // Return the client pointer
            }
        }
        return nullptr; // Return nullptr if login fails
    }

    static void withdrawAmount(Client* client) {
        double amount;
        cout << "Enter amount to withdraw: ";
        cin >> amount;
        if (!cin.fail() && amount > 0) {
            client->Withdraw(amount); // Assuming Withdraw is implemented in Client class
        }
        else {
            cout << "Invalid amount. Please try again.\n";
            cin.clear(); // Clear error state
            cin.ignore(10000, '\n'); // Ignore invalid input
        }
    }

    static void depositAmount(Client* client) {
        double amount;
        cout << "Enter amount to deposit: ";
        cin >> amount;
        if (!cin.fail() && amount > 0) {
            client->Deposit(amount); // Assuming Deposit is implemented in Client class
            system("pause");
            cout << "\nDeposit successful.\n";
        }
        else {
            cout << "Invalid amount. Please try again.\n";
            cin.clear(); // Clear error state
            cin.ignore(10000, '\n'); // Ignore invalid input
        }
    }

    static void transferAmount(Client* client) {
        int recipientId;
        double amount;

        cout << "Enter recipient ID: ";
        cin >> recipientId;
        Client* recipient = nullptr;

        // Search for the recipient by ID
        for (auto& c : allClients) { // Assuming allClients is a global vector containing all clients
            if (c.getId() == recipientId) {
                recipient = &c;
                break;
            }
        }

        if (recipient != nullptr) {
            cout << "Enter amount to transfer: ";
            cin >> amount;
            if (!cin.fail() && amount > 0 && amount <= client->CheckBalance()) {
                client->TransferTo(amount, *recipient); // Assuming TransferTo is implemented in Client class
            system("pause");
                cout << "\nTransfer successful.\n";
            }
            else {
                cout << "Invalid amount or insufficient balance.\n";
            }
        }
        else {
            cout << "Recipient not found.\n";
        }
    }


    // Method to manage client options
    static bool clientOptions(Client* client) {
        int choice;
        bool validChoice = false;

        do {
            printClientMenu();
            cout << "Your choice: ";
            cin >> choice;

            // Validate input
            if (cin.fail() || choice < 1 || choice > 7) {
                cin.clear(); // Clear the input flag
                cout << "Invalid choice, please try again.\n";
            }
            else {
                validChoice = true; // Valid input
            }
        } while (!validChoice);

        switch (choice) {
        case 1:
            client->displayInfo(); // Already implemented
            break;
        case 2:
            cout << "Balance: " << client->CheckBalance() << endl;
            break;
        case 3:
            updatePassword(client); // Already implemented
            FileManager::UpdateClients();
            break;
        case 4:
            withdrawAmount(client); // New method for withdraw
            FileManager::UpdateClients();
            break;
        case 5:
            depositAmount(client); // New method for deposit
            FileManager::UpdateClients();
            break;
        case 6:
            transferAmount(client); // New method for transfer
            FileManager::UpdateClients();
            break;
        case 7:
            return false; // Logout
        default:
            break;
        }
        return true;
    }

    // Public method to handle client login
    static void handleClientLogin(int id, string password) {
        Client* client = login(id, password);
        if (client) {
            while (clientOptions(client)); // Continue until logout
        }
        else {
            cout << "Invalid login credentials.\n";
        }
    }
};
