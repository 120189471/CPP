#include<iostream>

//std �����ռ�
//���������������
using std::cin;         //��׼����
using std::cout;        //��׼���
using std::cerr;        //��׼����
using std::clog;         //��׼����
using std::endl;         //������


int main_1_2(){
    //<<��������
    cout << "Enter two numbers: " << endl;
    //�����ַ�������ʼ����initialize)
    int v1 = 0;
    int v2 = 0;

    //>>���������
    cin >> v1 >> v2;
    cout << "The sum of " << v1 << " and " << v2 << " is " << v1 + v2 << endl;

    //����ע��
    /*�綨��ע��*/

    return 0;         //����ֵΪ 0 (0x0)
    //return 1;           //����ֵΪ 1 (0x1)
    //return -1;        //����ֵΪ -1 (0xffffffff)
}