#include<vector>
using std::vector;

#include<string>
using std::string;

#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main_lx_3_17(){

    /*
    //��ϰ3.17
    vector<string> vs1;
    string s;
    while (cin >> s){
    vs1.push_back(s);
    }
    //ע�⣬����2��Ӧ�ã���ǿfor�����е�ǰֵ���½��Ķ���
    for (auto &s2 : vs1){
    for (auto &c : s2){
    c = toupper(c);
    }
    }

    for (decltype(vs1.size()) i = 0; i < vs1.size(); i++){
    cout << vs1[i] << " ";
    }
    */

    /*
    //��ϰ3.19
    vector<int> ivec1(10,42);
    ivec1[0]=42;

    vector<int> ivec2;
    for (int i = 0; i < 10; i++){
    ivec2.push_back(42);
    }

    vector<int> ivec3{ 42, 42, 42, 42, 42, 42, 42, 42, 42, 42 };

    cout << ivec1.size() << " "
    << ivec2.size() << " "
    << ivec3.size() << endl;
    */
    
    //��ϰ3.20
    /* 
    vector<int> n;
    int n1;
    while (cin >> n1){
        n.push_back(n1);
    }
    for (decltype(n.size()) i = 0; i < (n.size()+1) / 2; i++){
        cout << n[i] + n[n.size() - 1 - i] << endl;
    }
    */

    return 0;
}