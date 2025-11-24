//ATM MACHINE SYSTEM USING OOPs CONCEPT 

#include <iostream>
#include <string>
using namespace std;

class atm { // CLASS ATM
private:
    long int account_No;
    string name;
    int PIN;
    double balance;
    string mobile_no;

public:
    // SET DATA
    void setData(long int account_No_a, string name_a, int PIN_a, double balance_a, string mobile_no_a) {
        account_No = account_No_a;
        name = name_a;
        PIN = PIN_a;
        balance = balance_a;
        mobile_no = mobile_no_a;
    }

    //GETTER FUNCTIONS
    long int getaccountNo() { return account_No; }
    string getName() { return name; }
    int getPIN() { return PIN; }
    double getBalance() { return balance; }
    string getmobileno() { return mobile_no; }

    //SET MOBILE 
    void setmobile(string mob_prev, string mob_new) {
        if (mob_prev == mobile_no) {
            mobile_no = mob_new;
            cout << "\nSuccessfully Updated Mobile No.\n";
        } else {
            cout << "\nIncorrect Old Mobile No.\n";
        }
    }

    //CASH WITHDRAW SYSTEM
    void cashwithdraw(int amount_a) {
        if (amount_a > 0 && amount_a <= balance) {
            balance -= amount_a;
            cout << "\nPlease Collect Your Cash";
            cout << "\nAvailable Balance: " << balance << "\n";
        } else {
            cout << "\nInvalid Input or Insufficient Balance\n";
        }
    }
};

int main() {
    int choice = 0, enterPIN;
    long int enterAccountNo;

    
    //DEFAULT DATA
    atm user1;
    user1.setData(12345, "Nitin", 8595, 100000, "8595972820");

    do {
        system("cls");
        cout << "\n****Welcome To ATM****\n";
        cout << "\nEnter Your Account No: ";
        cin >> enterAccountNo;
        cout << "Enter PIN: ";
        cin >> enterPIN;

        //CHECKING 
        if ((enterAccountNo == user1.getaccountNo()) && (enterPIN == user1.getPIN())) {
            do {
                system("cls");
                cout << "\n****ATM Menu****\n";
                cout << "1. Check Balance\n";
                cout << "2. Cash Withdraw\n";
                cout << "3. Show User Details\n";
                cout << "4. Update Mobile Number\n";
                cout << "5. Exit\n";
                cout << "Enter Your Choice: ";
                cin >> choice;

                int amount;
                string oldMob, newMob;

                switch (choice) {
                    case 1:
                        cout << "\nAvailable Balance: " << user1.getBalance() << "\n";
                        break;
                    case 2:
                        cout << "Enter amount to withdraw: ";
                        cin >> amount;
                        user1.cashwithdraw(amount);
                        break;
                    case 3:
                        cout << "\nUser Details:";
                        cout << "\nName: " << user1.getName();
                        cout << "\nAccount No: " << user1.getaccountNo();
                        cout << "\nMobile No: " << user1.getmobileno() << "\n";
                        break;
                    case 4:
                        cout << "Enter Old Mobile No: ";
                        cin >> oldMob;
                        cout << "Enter New Mobile No: ";
                        cin >> newMob;
                        user1.setmobile(oldMob, newMob);
                        break;
                    case 5:
                        cout << "\nExiting...\n";
                        break;
                    default:
                        cout << "\nInvalid Choice\n";
                }
                cin.ignore(); 
                cin.get();    
            } while (choice != 5);
        } else {
            cout << "\nInvalid Account No or PIN. Try Again.\n";
            cin.ignore();
            cin.get();
        }
    } while (true);

    return 0;
}
