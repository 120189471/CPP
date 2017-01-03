#include<iostream>
using std::cout;
using std::endl;

//extern 在多个文件之间共享const，必须在变量定义之前添加extern关键词
extern const int buffSize;

int main_2_4(){
    const int buffSize = 512; //如果不是外部的，则必须初始化常量对象
    //buffSize = 1024;        //不能给常量赋值

    cout << "---------对常量的引用---------" << endl;
    //C++并不允许随意改变引用所绑定的对象

    const int &bf = buffSize;
    cout << &buffSize << endl;
    cout << &bf << endl;
    int i = 42;
    //int &bf = i;      // 重定义；不同的类型修饰符
    const int &i1 = i;
    i = 55;
    cout << i1 << endl;

    int j = 42;
    const int &r1 = i;
    const int &r2 = 42;
    const int &r3 = r1 * 2;
    //int &r4 = r1 * 2;     //无法从“int”转换为“int &

    cout << "---------指向常量的指针---------" << endl;

    const double pi = 3.14;
    //double *piPtr = &pi;
    const double *cPtr = &pi;
    //*cPtr = 42;       //表达式必须是可修正的左值
    double dval = 3.14;
    cPtr = &dval;       //不能通过cPtr改变dval的值
    //*cPtr = 99;         //表达式必须是可修正的左值

    double E = 2.71;
    const double *ePtr = &E;
    E = 2.7182;
    cout << E << endl;
    //*ePtr = pi;
    return 0;
}