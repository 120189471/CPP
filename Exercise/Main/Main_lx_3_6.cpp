#include<string>
using std::string;

#include<iostream>
using std::cout;
using std::endl;

int main_lx_3_6(){
    //用for将字符串中的所有字符替换成x
    string s1("abcdefghijklmnopqistuvwxyz0123456789");
    //第一种方法，位数遍历
    /*for (auto &c : s1){
        c = 'X';
        }

        */
    //第二种方法，下标遍历。
    /*
    for (auto n = 0; n <= s1.size(); n++){
    s1[n] = 'X';
    }
    */
    //用char代替循环的变量
    /*
        for (char &n : s1){
        n = 'X';
        }
        */
    //用while修改上面代码
    //while (decltype(s1.size()) n = 0 && n <= s1.size()){
    decltype(s1.size()) n = 0;
    while (n <= s1.size()){
        s1[n] = 'x';
        n++;
    }

    cout << s1 << endl;
    cout << s1.size() << endl;


    return 0;
}