#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int main1_4(){
    int sum = 0;
    int val = 1;
    //条件 （condition）
    while (val <= 10){
        sum += val;
        ++val;
    }
    cout << "Sum of 1 to 10 inclusiv is " << sum << endl;
    /*
    int second = 50;
    int sumScond = 0;

    while (second <= 100){
        sumScond += second;
        ++second;
    }
    */
    int sumi = 0;
    //初始化语句（init-statement），循环条件（condition），表达式（expression）
    for (int i = 50; i <= 100; ++i)
    {
        sumi += i;
    }
    cout << "Sum(for) of 50 to 100 inclusiv is " << sumi << endl;

    int sumIn = 0;
    int j = 0;
    //当遇见文件结束符（end-of-file）,此处因为j定义为int，所以不是int类型的值，那么就结束;
    //windows 是Ctrl+z，然后回车，在unix系统中，包括Mac 是Ctrl+D;
    while (cin >> j){
        sumIn += j;
    }
    cout << "SumIn is " << sumIn << endl;


    return 0;
}