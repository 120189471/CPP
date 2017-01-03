//计算0到10的 平方和立方，并用制表符打印出来
//integer	square	cube

//分析 
//
//1.定义10个数，值分别为1到10
//2.输出表头
//3.输出第二行到11行

//这个方案应该可以改进

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

void test2_l10(){
    cout << "integer\t" << "square\t" << "cube\t" << endl;
    for (size_t i = 0; i < 9; i++)
    {
        int num = i + 1;
        cout << num << "\t" << num*num << "\t" << num*num*num << endl;
    }
}
