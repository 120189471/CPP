//����2�������жϵڶ������Ƿ��ǵ�һ�����ı���

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

void test2_l8(){

    //������Ҫ�жϵ�����
    int num1;
    int num2;

    //����
    cout << "������2������";
    cin >> num1 >> num2;
    
    if (num1%num2!=0)
    {
        cout << "����1:" << num1 << ",��������2:" << num2 << "�ı���";
    } else{
        cout << "����1:" << num1 << "��������2:" << num2 << "�ı���";
    }


}