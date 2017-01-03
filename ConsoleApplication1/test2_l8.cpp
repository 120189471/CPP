//输入2个数，判断第二个数是否是第一个数的倍数

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

void test2_l8(){

    //定义需要判断的数字
    int num1;
    int num2;

    //输入
    cout << "请输入2个数：";
    cin >> num1 >> num2;
    
    if (num1%num2!=0)
    {
        cout << "数字1:" << num1 << ",不是数字2:" << num2 << "的倍数";
    } else{
        cout << "数字1:" << num1 << "，是数字2:" << num2 << "的倍数";
    }


}