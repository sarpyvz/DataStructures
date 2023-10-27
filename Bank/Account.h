#include <iostream>
#include <vector>
#include <variant>
using namespace std;

class Account{

public:
    vector <variant<int,string>> accounts;

    Account();
    int getPassword(){
        return password;
    }
    int getBalance(){
        return balance;
    }
    string getName(){
        return name;
    }

private:
    string name;
    int password;
    int balance;


};
