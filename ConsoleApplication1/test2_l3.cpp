//dx test2.3
//在同一行打印1到4，中间用空格隔开
//要求一：使用一条语句，包含一个流插入运算符
//要求二：使用一条语句，包含4个流插入运算符
//要求三：使用4条语句

#include <iostream>

using std::cout;
using std::endl;

//2章第3个练习题 取名 2l_3
void test2l_3()
{
	cout << "第一次输入结果 ";
	cout << "1 2 3 4" << endl;
	cout << "第二次输入结果 ";
	cout << "1 " << "2 " << "3 " << "4" << endl;
	cout << "第三次输入结果 ";

	cout << "1 ";
	cout << "2 ";
	cout << "3 ";
	cout << "4";

	//return 0;
}