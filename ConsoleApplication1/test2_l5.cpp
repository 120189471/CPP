//dx test2_l5
//��������3��������Ӧ���ǵĺͣ�ƽ��ֵ���˻�����Сֵ�����ֵ��

//����
//1.����3����
//1.1����������
//2.���������ĺ�
//3.����������ƽ��ֵ
//4.���������ĳ˻�
//5.�����ֵ
//6.����Сֵ

#include<iostream>

using std::cout;
using std::cin;
using std::endl;

void test2_l5(){
	int number1;
	int number2;
	int number3;
	int min;
	int max;

	cout << "Input three different integers: ";
	cin >> number1 >> number2 >> number3;
	cout << "Sum is " << number1 + number2 + number3 << endl;
	cout << "Average is " << (number1 + number2 + number3) / 3 << endl;
	cout << "Product is " << number1*number2*number3 << endl;
	//�����㷨�����⣬����̫��
	//if (number1 > number2&&number1 > number3)
	//	cout << "Largest is " << number1;
	//if (number2 > number1&&number2 > number3)
	//	cout << "Largest is " << number2;
	//if (number3 > number2&&number3 > number1)
	//	cout << "Largest is " << number3;

	if (number1 > number2)
		max = number1;
		//min = number2; 
	
	
		if (max > number3){
			cout << "Largest is " << max << endl;
		}
		else{
			cout << "Largest is" << number3 << endl;
		}

		if (min < number3){
			cout << "Smallest is " << min << endl;
		}
		else{
			cout << "Smallest is " << number3 << endl;
		}		
}

