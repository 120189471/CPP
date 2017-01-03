//dix test 2.2
//数字和，差，积，商运算
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
	//定义变量
	int number1;		//定义第一个字符 
	int number2;		//定义第二个字符
	int sum;			//定义和结果 
	int diff;			//定义差结果
	int product;		//定义积结果
	int quotient;		//定义商结果

	std::cout << "请输入第一个字符: ";
	std::cin >> number1;

	std::cout << "请输入第二个字符: ";
	std::cin >> number2;

	sum = number1 + number2;
	std::cout << "两者相加结果: ";
	std::cout << sum << endl;

	cout << "两者相减结果为： " << number1 - number2 << endl;
	cout << "两者相乘结果为： " << number1*number2 << endl;
	cout << "两者相除结果为： " << number1 / number2 << endl;
	cout << "两者取余结果为： " << number1%number2 << endl;


	return 0;
}