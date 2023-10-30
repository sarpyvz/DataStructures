#include <iostream>
#include <utility>
#include "account.h"
using namespace std;


Account::Account(string name, string password,  double balance){
    Account::name = name;
    Account::password = password;
    Account::balance = balance;

}
