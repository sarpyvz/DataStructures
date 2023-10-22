#include <iostream>
//#include <string>
#include <algorithm>
using namespace std;


int Most_Least_eat( string Names[], int Number[] ){
    int most= 0;
    int least;
    int index_most;
    int index_least;
    for ( int name = 0; name < 7; name ++){
        if ( Number[name] > most  ){
            most = Number[name];
            index_most = name;
        }
        if( Number[name] < least){
            least = Number[name];
            index_least = name;
        }
    }
    cout << Names[index_most] << " is the person who ate " << most << " pancakes which is the biggest \n";
    cout << Names[index_least] << " is the person who ate " << least << " pancakes which is lowest ";
    return 0;
}


int Compare( string Names[], int Number[]){
    string name;
    string name2;
    int index1;
    int index2;
    cout << "Enter two people names";
    cin >> name;
    cin >> name2;
    for (int index = 0; index < 7; index++ ){
        if (Names[index] == name){
            index1 = index;
        }
        else if ( Names[index] == name2){
            index2 = index;
        }
    }
    if (Number[index1] > Number[index2]){
        cout << Names[index1] << " has eaten more than " << Names[index2] << endl;
    }
    else if ( Number[index1] < Number[index2]){
        cout << Names[index1] << " has eaten less than " << Names[index2] << endl;
    }
    else cout << "They ate equal amount";

    return 0;
}



int spesific(string Names[], int Number[]){
    int num;
    int index_;
    cout << "Enter who ate the wanted amount";
    cin >> num;
    for(int index = 0; index < 7;index++){
        if( Number[index] == num ){
            index_ = index;
        }
    }
    cout << Names[index_] << " ate " << Number[index_] << " amounts of pancakes ";
}



int sort( string Names[], int Number[]){
    int Num[7];
    string Name[7];
    for (int i = 0; i < 7; i++){
        int count = 0;
        for ( int j = 0; j < 7; j++){
            if ( Number[i] < Number[j] ){
                Num[i] = Number[i];
                Name[i] = Names[i];
            }
            else{
                Num[i] = Number[j];
                Name[i] = Names[j];
            }

        }
    }
    for ( int yar = 0; yar < 7; yar++){
        cout << Name[yar] << "." << Num[yar] << endl;
    }
    return 0;
}





int main(){
    string Names[7];
    int Number[7];
    string Name;
    int number;
    for( int i = 0; i <7; i++ ){
        cin >> Names[i];
        cin >> Number[i];
    }
    Most_Least_eat(Names,Number);
    sort(Names,Number);
    spesific(Names,Number);
    Compare(Names,Number);

}
