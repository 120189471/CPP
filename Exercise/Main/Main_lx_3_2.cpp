#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#include<string>
using std::string;
using std::getline;

int main_lx_3_2(){
    string line;
    //输入一行，读入一整行
    
    getline(cin, line);
    cout << line<< endl;
    
    //一次读入一个词

    while (cin >> line){
        cout << line << endl;;
    }
    return 0;
}
