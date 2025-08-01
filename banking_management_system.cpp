#include <iostream>
#include <vector>
#include <string>
using namespace std;

// BankAccount class definition
class BankAccount {
public:
    string accountHolder;
    int accountNumber;
    double balance;

    BankAccount(string name, int accNo, double initialBalance) {
        accountHolder = name;
        accountNumber = accNo;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "₹" << amount << " deposited successfully!\n";
        } else {
            cout << "Invalid deposit amount!\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "₹" << amount << " withdrawn successfully!\n";
        } else {
            cout << "Insufficient balance or invalid amount!\n";
        }
    }

    void display() {
        cout << "\n--- Account Details ---\n";
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: ₹" << balance << endl;
    }
};

// Global list of accounts
vector<BankAccount> accounts;

// Find account by number
BankAccount* findAccount(int accNo) {
    for (auto &acc : accounts) {
        if (acc.accountNumber == accNo)
            return &acc;
    }
    return nullptr;
}

// Admin Menu
void adminMenu() {
    int choice;
    do {
        cout << "\n--- Admin Menu ---\n";
        cout << "1. View All Accounts\n";
        cout << "2. Create New Account\n";
        cout << "3. Exit Admin Mode\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                if (accounts.empty()) {
                    cout << "No accounts available.\n";
                } else {
                    for (auto &acc : accounts) {
                        acc.display();
                    }
                }
                break;

            case 2: {
                string name;
                int accNo;
                double initialBalance;

                cin.ignore(); // Clear leftover newline
                cout << "Enter account holder name: ";
                getline(cin, name);

                cout << "Enter new account number: ";
                cin >> accNo;

                if (findAccount(accNo)) {
                    cout << "⚠️ Account number already exists!\n";
                    break;
                }

                cout << "Enter initial balance: ";
                cin >> initialBalance;

                accounts.push_back(BankAccount(name, accNo, initialBalance));
                cout << "✅ Account created successfully!\n";
                break;
            }

            case 3:
                cout << "Exiting Admin Mode.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 3);
}

// User Menu
void userMenu(BankAccount* userAccount) {
    int choice;
    double amount;

    do {
        cout << "\n--- User Menu ---\n";
        cout << "1. View Account\n";
        cout << "2. Deposit\n";
        cout << "3. Withdraw\n";
        cout << "4. Check Balance\n";
        cout << "5. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                userAccount->display();
                break;

            case 2:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                userAccount->deposit(amount);
                break;

            case 3:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                userAccount->withdraw(amount);
                break;

            case 4:
                cout << "Your current balance is: ₹" << userAccount->balance << endl;
                break;

            case 5:
                cout << "Logging out...\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }
    } while (choice != 5);
}

// Main program
int main() {
    int mainChoice;

    do {
        cout << "\n==== Bank Management System ====\n";
        cout << "1. Admin Login\n";
        cout << "2. User Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice) {
            case 1: {
                string password;
                cout << "Enter admin password: ";
                cin >> password;
                if (password == "admin123") {
                    adminMenu();
                } else {
                    cout << "Incorrect password!\n";
                }
                break;
            }

            case 2: {
                int accNo;
                cout << "Enter your account number: ";
                cin >> accNo;
                BankAccount* userAcc = findAccount(accNo);
                if (userAcc) {
                    userMenu(userAcc);
                } else {
                    cout << "Account not found!\n";
                }
                break;
            }

            case 3:
                cout << "Thank you for using the system.\n";
                break;

            default:
                cout << "Invalid option.\n";
        }

    } while (mainChoice != 3);

    return 0;
}
