//����һ��5λ�����ֽ�ÿλ����������Щ���ּ��3���ո��ӡ����

//65535

#include<iostream>

using std::cout;
using std::endl;
using std::cin;

void test2_l9(){
    //������ֽ���
    int num;
    //���嵥��λ��
    int num1;       //������λ��
    int num2;       //����ǧλ��
    int num3;       //�����λ��
    int num4;       //����ʮλ��
    int num5;       //�����λ��

    cout << "������һ��5λ���� " << endl;
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

    cout << "��������"
        << num1 << "   " << num2 << "   " << num3 << "   " << num4 << "   " << num5 << endl;

}