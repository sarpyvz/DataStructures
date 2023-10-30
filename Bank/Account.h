#include <iostream>
#include <vector>
#include <variant>
#pragma once
using namespace std;

class Account{

public:
    Account(string name, string password, double balance);

    string name;
    string password;
    double balance;

};
