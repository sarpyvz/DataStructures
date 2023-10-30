#include <iostream>
#include "bank.h"
#include <vector>
using namespace std;


Account Bank::find_account(string name, string password) {
    Bank amo; // direk vector<Account> diyip de olabilir
    for (int i = 0; i < amo.accounts.size();i++){
        if (amo.accounts[i].name == name && amo.accounts[i].password == password ){
            return amo.accounts[i];
        }
    }


}


bool Bank::createAccount() {
    string name,password;
    double balance;
    Bank amo;
    cout << "Enter name and password and balance for account creating : " << endl;
    cin >> name >> password >> balance;
    for ( int i = 0; i < amo.accounts.size();i++){
        if ( amo.accounts[i].name == name && amo.accounts[i].password == password){
            return false;
        }
    }
    balance = 0.0;
    amo.accounts.emplace_back(name,password,balance);
    return true;
}


bool Bank::deleteAccount(string name, string password) {
    Bank amo;
    for (int i = 0; i < amo.accounts.size();i++){
        if (amo.accounts[i].name == name && amo.accounts[i].password == password){
            amo.accounts.erase(amo.accounts.begin() + i);
            return true;
        }
    return false;
    }


}


bool Bank::deposit(string name, string password) {
    Bank amo;
    double money;
    cout << "Enter the amount you want to deposit : ";
    cin >> money;
    for (int i = 0; i < amo.accounts.size();i++){
        if (amo.accounts[i].name == name && amo.accounts[i].password == password){
            amo.accounts[i].balance += money;
            return true;
        }
    }
    return false;

}


double Bank::getBalance(string name, string password) {
    Bank amo;

    for (int i = 0; i < amo.accounts.size();i++){
        if (amo.accounts[i].name == name && amo.accounts[i].password == password){
            return amo.accounts[i].balance;
        }
    }


}


void Bank::printDatabase(string name, string password) {
    Bank amo;
    for (int i = 0; i < amo.accounts.size(); i++){
        cout <<"Username: " <<  amo.accounts[i].name <<" Password: " <<  amo.accounts[i].password <<" Balance :" <<amo.accounts[i].balance<< "\n"<< endl;
    }

}



bool Bank::withdraw(string name, string password) {
    Bank amo;
    double money;
    cout << "Enter the amount you want to withdraw: ";
    cin >> money;
    for (int i = 0; i < amo.accounts.size();i++){
        if (amo.accounts[i].name == name && amo.accounts[i].password == password){
            if(amo.accounts[i].balance < money){
                return false;
            }
            else {
                amo.accounts[i].balance -= money;
                return true;
            }
        }
    }
    return false;
}
