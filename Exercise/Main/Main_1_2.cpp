#include<iostream>

//std 命名空间
//：：作用域运算符
using std::cin;         //标准输入
using std::cout;        //标准输出
using std::cerr;        //标准错误
using std::clog;         //标准错误
using std::endl;         //操作符


int main_1_2(){
    //<<输出运算符
    cout << "Enter two numbers: " << endl;
    //定义字符，并初始化（initialize)
    int v1 = 0;
    int v2 = 0;

    //>>输入运算符
    cin >> v1 >> v2;
    cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << endl;

    //单行注释
    /*界定符注释*/

    return 0;         //返回值为 0 (0x0)
    //return 1;           //返回值为 1 (0x1)
    //return -1;        //返回值为 -1 (0xffffffff)
}