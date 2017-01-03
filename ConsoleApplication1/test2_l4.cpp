//dx testl2_4
//判断2个数的大小，输入大的数字，并在后面写”is large.“
//如果2个数相等，输出”Thes numbers are equal.“

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

void test2_l4(){
	int number1;		//定义比较的第一个数
	int number2;		//定义比较的第二个数

	cout << "请输入比较的第一个数: ";
	cin >> number1;
	
	cout << "请输入比较的第二个数: ";
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