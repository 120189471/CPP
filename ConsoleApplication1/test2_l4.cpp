//dx testl2_4
//�ж�2�����Ĵ�С�����������֣����ں���д��is large.��
//���2������ȣ������Thes numbers are equal.��

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

void test2_l4(){
	int number1;		//����Ƚϵĵ�һ����
	int number2;		//����Ƚϵĵڶ�����

	cout << "������Ƚϵĵ�һ����: ";
	cin >> number1;
	
	cout << "������Ƚϵĵڶ�����: ";
	cin >> number2;

	if (number1 > number2){
		cout << number1 << " is large." << endl;
	}
	else if (number1 < number2){
		cout << number2 << " is large." << endl;
	}
	else{
		cout << "These numbers are equal.";
	}





}