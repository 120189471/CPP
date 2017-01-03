#include<iostream>
using std::cout;
using std::endl;

int reused = 34;
int main_2_2_4(){

    int unique = 0;
    cout << reused << " " << unique << endl;

    int reused = 0;
    cout << reused << " " << unique << endl;

    cout << ::reused << " " << unique << endl;



    return 0;
}