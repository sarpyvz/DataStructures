#include <vector>
#include "account.h"
using namespace std;

class Bank{

public:
    Bank();
    Account find_account(string ,string );
    bool deposit(string , string );
    bool withdraw(string , string );
    double getBalance(string , string);
    static bool createAccount( );
    bool deleteAccount(string , string );
    void printDatabase(string , string );

    vector< Account > accounts;

};



