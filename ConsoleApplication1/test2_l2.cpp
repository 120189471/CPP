//dix test 2.2
//���ֺͣ������������
////sum
//difference
//product
//quotient
//

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

int main2()
{
	//�������
	int number1;		//�����һ���ַ� 
	int number2;		//����ڶ����ַ�
	int sum;			//����ͽ�� 
	int diff;			//�������
	int product;		//��������
	int quotient;		//�����̽��

	std::cout << "�������һ���ַ�: ";
	std::cin >> number1;

	std::cout << "������ڶ����ַ�: ";
	std::cin >> number2;

	sum = number1 + number2;
	std::cout << "������ӽ��: ";
	std::cout << sum << endl;

	cout << "����������Ϊ�� " << number1 - number2 << endl;
	cout << "������˽��Ϊ�� " << number1*number2 << endl;
	cout << "����������Ϊ�� " << number1 / number2 << endl;
	cout << "����ȡ����Ϊ�� " << number1%number2 << endl;


	return 0;
}