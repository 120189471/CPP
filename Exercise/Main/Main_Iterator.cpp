#include<vector>
using std::vector;

#include<string>
using std::string;

#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main_Iterator(){
  
    vector<string> vs;
    string s;
    while (cin >> s){
        vs.push_back(s);
    }

    auto b = vs.begin();
    auto e = vs.end();

    
    cout << *b << " " << *e << endl;


    return 0;

}