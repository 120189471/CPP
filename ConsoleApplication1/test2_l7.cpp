//����һ�������ж�����������ż��

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

void tst2_l7(){
    int num;
    int nummodulo;
    cout << "������һ������ " << endl;
    cin >> num;
    nummodulo = num % 2;

    cout << "ȡģ�Ľ��" << num % 2 << endl;
    if (num % 2 == 0){
        cout << "�����������ż��" << endl;
    }
    else{
        cout << "���������������" << endl;
    }
    
}

