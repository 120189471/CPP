#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int main1_4(){
    int sum = 0;
    int val = 1;
    //���� ��condition��
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
    //��ʼ����䣨init-statement����ѭ��������condition�������ʽ��expression��
    for (int i = 50; i <= 100; ++i)
    {
        sumi += i;
    }
    cout << "Sum(for) of 50 to 100 inclusiv is " << sumi << endl;

    int sumIn = 0;
    int j = 0;
    //�������ļ���������end-of-file��,�˴���Ϊj����Ϊint�����Բ���int���͵�ֵ����ô�ͽ���;
    //windows ��Ctrl+z��Ȼ��س�����unixϵͳ�У�����Mac ��Ctrl+D;
    while (cin >> j){
        sumIn += j;
    }
    cout << "SumIn is " << sumIn << endl;


    return 0;
}