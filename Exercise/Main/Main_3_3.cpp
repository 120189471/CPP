#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#include<vector>
using std::vector;

#include<string>
using std::string;

int main_3_3(){


    vector<unsigned>  scores(11, 0);
    unsigned grade;

    while (cin >> grade){
        ++scores[grade / 10];
    }
    for (auto s : scores){
        cout << s << " ";
    }



    return 0;

}