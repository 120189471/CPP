#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#include<string>
using std::string;
using std::getline;

int main_lx_3_4(){


    string s1;
    string s2;
    //cin >> s1 >> s2;

    //读入2个字符串，比较大小，如果不想等，输出大的，
    /*
    if (s1 == s2){
    cout << "输入字符相同" << endl;
    }
    else{
    if (s1 > s2){
    cout << "最大值是： " << s1;
    }
    else{
    cout << "最大值是： " << s2;
    }
    }
    */

    //读入2个字符串，比较是否等长，如果不等，输出长的
    /*
    if (s1.size() == s2.size()){
        cout << "两字符串长度相同" << endl;
    }
    else{
        if (s1.size() > s2.size()){
            cout << "长的文件是： " << s1 << " \n其长度是：" << s1.size() << endl;
        }
        else{
            cout << "长的文件是： " << s2 << " \n其长度是：" << s2.size() << endl;
        }
    }
    */
    //读入串，并将他们串联，然后改写代码，让他们间隔空格后串联。
    /*
    string word;
    string sWord;
    while (cin >> word){
        sWord = sWord + word+" ";
        cout << sWord << endl;
    }
    */
    //增强for循环
    /*
    string word="abcdefghijklmnopqistuvwxyz";
    for (char c : word){
        cout << c << endl;
    }
    //
    */

    string s("Hello Word!!!");
        decltype(s.size()) punct_cnt = 0;
        for (auto c : s)
            if (ispunct(c))
                ++punct_cnt;
        cout << punct_cnt << ".............." << s << endl;


    return 0;
}