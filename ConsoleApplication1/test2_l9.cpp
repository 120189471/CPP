//输入一个5位数，分解每位数，并将这些数字间隔3个空格打印出来

//65535

#include<iostream>

using std::cout;
using std::endl;
using std::cin;

void test2_l9(){
    //定义待分解数
    int num;
    //定义单个位数
    int num1;       //定义万位数
    int num2;       //定义千位数
    int num3;       //定义百位数
    int num4;       //定义十位数
    int num5;       //定义个位数

    cout << "请输入一个5位数： " << endl;
    cin >> num;

    num1 = num / 10000;
    cout << num1 << endl;
    num2 = num / 1000 % 10;
    cout << num2 << endl;
    num3 = num / 100 % 100%10;
    cout << num3 << endl;
    num4 = num / 10 % 1000 % 100 % 10;
    cout << num4 << endl;
    num5 = num % 10000 % 1000 % 100 % 10;
    cout << num5 << endl;

    cout << "结果输出："
        << num1 << "   " << num2 << "   " << num3 << "   " << num4 << "   " << num5 << endl;

}