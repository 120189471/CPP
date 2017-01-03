#include<iostream>
using std::cout;
using std::endl;

//文件间共享，定义在块外
extern const int bufSize2=512;

int main() {
    //定义一个const
    const int ci = 42;

    //对常量的引用,不能修改绑定的对象
    const int &r1 = ci;

    //常量的引用
    const int &r2 = 24;
    const int &r3 = r1 * 2;
    //int &r4=r1*2;

    //类型转换时，编译器暗中使用临时量
    double dval = 3.14;
    const int &ri = dval;
    
    cout << r1 << endl;
    cout << &r1 << endl;

    //指向常量的指针
    //不能通过指针修改对象的值，但是没规定其他方法不能修改
    const double *dvalPtr = &dval;
    
    //常量指针
    //1.必须初始化，2.初始化后值不在改变
    const double *const dvalPtr2 = &dval;

    //顶层const： 指针是个常量
    //底层const： 指针指向的是一个常量


    

    
    
}