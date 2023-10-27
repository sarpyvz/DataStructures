#include <string>
#include <vector>
#include "account.h"
using namespace std;

class Bank{

public:
    Bank( );
    string find_account(string ,int );
    bool deposit(string , int ,int );
    bool withdraw(string , int, int );
    bool getBalance(string , int ,int);
    bool createAccount(string ,int );
    bool deleteAccount(string , int );
    void printDatabase(string , int , int );



private:
    vector< Account >Accounts;

};


