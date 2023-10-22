#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

void ispalindrome ( string arr ){
    int i = 0;
    int j = arr.length() - 1 ;
    int count = 0;

    if (arr.length() % 2 != 0){

        while( i != j  ){
            if ( arr[i] == arr[j] ){
                count += 1;
            }
            i++;
            j--;
        }
        if ( count == (arr.length() -1) / 2 ){
            cout << arr  << " is palindrome";

        }
        else cout << arr << " is not palindrome";

    }
    else if(arr.length() % 2 == 0) {
        while( i < j  ){
            if ( arr[i] == arr[j] ){
                count += 1;
            }
            j--;
            i++;
        }
        if ( count == arr.length() / 2 ){
            cout << arr  << " is palindrome";
        }
        else cout << arr  << " is not palindrome";;

    }

}


int main(){
    string kelime;
    std::cin >> kelime;
    ispalindrome(kelime);

}
