//输入一个数，判断是奇数还是偶数

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

void tst2_l7(){
    int num;
    int nummodulo;
    cout << "请输入一个数： " << endl;
    cin >> num;
    nummodulo = num % 2;

    cout << "取模的结果" << num % 2 << endl;
    if (num % 2 == 0){
        cout << "输入的数字是偶数" << endl;
    }
    else{
        cout << "输入的数字是奇数" << endl;
    }
    
}

