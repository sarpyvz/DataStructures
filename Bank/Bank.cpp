#include <iostream>
#include "bank.h"
#include <vector>
#include "account.h"
using namespace std;

Bank::Bank(){
    vector< Account > accounts;
}

string Bank::find_account(string name, int password) {
    for (int acc = 0; acc < accounts.size() ; acc++){
        for (int i = 0; i < 2; i++){
            if ( accounts[acc][i] == name || accounts[acc][i+1] == password ){
                return accounts[acc];
            }
        }

    }


}







bool Bank::createAccount(string name, int password) {
    cout << "Enter name and password for account creating : " << endl;
    cin >> name >> password;
}

bool Bank::deleteAccount(string name, int password) {}

bool Bank::deposit(string name, int password) {}

bool Bank::getBalance(string name, int password) {}

void Bank::printDatabase(string name, int password, int balance) {}



bool Bank::withdraw(string name, int password) {}


