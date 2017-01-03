//dx test2_l5
//键盘输入3个数，答应他们的和，平均值，乘积，最小值，最大值；

//分析
//1.定义3个数
//1.1输入三个数
//2.求三个数的和
//3.求三个数的平均值
//4.求三个数的乘积
//5.求最大值
//6.求最小值

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
	//下面算法有问题，代码太多
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

