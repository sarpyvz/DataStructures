
#include <iostream>
#include "Bank.cpp"

using namespace std;

int main()
{
    Bank DataBank;
    DataBank.createAccount();
    DataBank.createAccount();
    DataBank.printDatabase("amo","123");

    DataBank.deposit("amo", "123");
    DataBank.withdraw("amo", "123");
    DataBank.printDatabase("amo","123");

    return 0;
}
