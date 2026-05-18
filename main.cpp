#include <iostream>
#include <fstream>
using namespace std;

class BankAccount
{
private:

    int accountNumber;
    string name;
    float balance;

public:

    void createAccount()
    {
        cout << "Enter Account Number: ";
        cin >> accountNumber;

        cin.ignore();

        cout << "Enter Customer Name: ";
        getline(cin, name);

        cout << "Enter Initial Balance: ";
        cin >> balance;
    }

    void displayAccount()
    {
        cout << "\nAccount Number: " << accountNumber;

        cout << "\nCustomer Name: " << name;

        cout << "\nBalance: " << balance << endl;
    }

    void deposit(float amount)
    {
        balance = balance + amount;

        cout << "Amount Deposited Successfully!\n";
    }

    void withdraw(float amount)
    {
        if(amount > balance)
        {
            cout << "Insufficient Balance!\n";
        }
        else
        {
            balance = balance - amount;

            cout << "Withdrawal Successful!\n";
        }
    }

    void saveToFile(ofstream &file)
    {
        file << accountNumber << endl;
        file << name << endl;
        file << balance << endl;
    }
    void loadFromFile(ifstream &file)
    {
        file >> accountNumber;

        file.ignore();

        getline(file, name);

        file >> balance;
    }
    int getAccountNumber()
    {
        return accountNumber;
    }
};

int main()
{
    BankAccount customers[100];

    int totalAccounts = 0;

    int choice;

    while(true)
    {
        cout << "\n===== BANK MANAGEMENT SYSTEM =====\n";

        cout << "1. Create Account\n";
        cout << "2. Search Account\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Save All Accounts\n";
        cout << "6. Load Accounts\n";
        cout << "7. Display All Accounts\n";
        cout << "8. Exit\n";

        cout << "Enter Your Choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:

                customers[totalAccounts].createAccount();

                totalAccounts++;

                break;

            case 2:
            {
                int searchAccount;

                bool found = false;

                cout << "Enter Account Number to Search: ";
                cin >> searchAccount;

                for(int i = 0; i < totalAccounts; i++)
                {
                    if(customers[i].getAccountNumber() == searchAccount)
                    {
                        cout << "\nAccount Found!\n";

                        customers[i].displayAccount();

                        found = true;

                        break;
                    }
                }

                if(found == false)
                {
                    cout << "Account Not Found!\n";
                }

                break;
            }
            case 3:
            {
                int accNo;

                float amount;

                bool found = false;

                cout << "Enter Account Number: ";
                cin >> accNo;

                for(int i = 0; i < totalAccounts; i++)
                {
                    if(customers[i].getAccountNumber() == accNo)
                    {
                        cout << "Enter Deposit Amount: ";
                        cin >> amount;

                        customers[i].deposit(amount);

                        found = true;

                        break;
                    }
                }

                if(found == false)
                {
                    cout << "Account Not Found!\n";
                }

                break;
            }
            case 4:
            {
                int accNo;

                float amount;

                bool found = false;

                cout << "Enter Account Number: ";
                cin >> accNo;

                for(int i = 0; i < totalAccounts; i++)
                {
                    if(customers[i].getAccountNumber() == accNo)
                    {
                        cout << "Enter Withdraw Amount: ";
                        cin >> amount;

                        customers[i].withdraw(amount);

                        found = true;

                        break;
                    }
                }

                if(found == false)
                {
                    cout << "Account Not Found!\n";
                }

                break;
            }
            case 5:
            {
                ofstream file("bank.txt");

                for(int i = 0; i < totalAccounts; i++)
                {
                    customers[i].saveToFile(file);
                }

                file.close();

                cout << "All Accounts Saved Successfully!\n";

                break;
            }
            case 6:
            {
                ifstream file("bank.txt");

                totalAccounts = 0;

                while(file)
                {
                    customers[totalAccounts].loadFromFile(file);

                    if(file)
                    {
                        totalAccounts++;
                    }
                }

                file.close();

                cout << "Accounts Loaded Successfully!\n";

                break;
            }
            case 7:
            {
                for(int i = 0; i < totalAccounts; i++)
                {
                    customers[i].displayAccount();
                }

                break;
            }
            case 8:

                cout << "Thank You!\n";

                return 0;
            default:

                cout << "Invalid Choice!\n";
        }
    }
}