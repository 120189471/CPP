#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main_2_1(){
    cout << "----------定义变量----------" << endl;
    int units_sold1 = 0;
    int units_sold2 = { 0 };
    int units_sold3{ 0 };
    int units_sold4(0);
    
    /*
    int i = 10;
    //非bool赋值给bool时，如果初始化为0时，则对应为false，否则为true；
    //bool赋值给非bool时，false->0,true->1;
    if (i){
    cout << "True" << endl;
    }
    else{
    cout << "False" << endl;
    }
    */
    unsigned u = 10;
    unsigned u2 = 42;
    int i = 10;
    int i2 = 42;
    cout << u2 - u << endl;
    cout << u - u2 << endl;

    cout << i2 - i << endl;
    cout << i - i2 << endl;
    cout << i - u << endl;
    cout << u - i << endl;

    //字面值（literal）
    //20/*十进制*/         字面值类型 int,long,long long,
    //024/*八进制*/        字面值类型 int,unsigned int,long, unsigned long,long long, unsigned long long
    //0xl4/*十六进制*/     字面值类型 int,unsigned int,long, unsigned long,long long, unsigned long long
    //浮点数自勉之值是 double
    //字符串的面值是有字符常量组成的数组，结尾添加空字符（'\0'）
    //转义序列（escape sequence）
    /*
        \n    换行      \t   横向制表符      \a     报警符
        \v    纵向制表符\b   退格符          \?     问号
        \r    回车符    \f   进纸符

        Latin_1字符集

        \7 报警符      \12   换行            \40     空格
        \0 空字符      \115  字符M           \x4d    字符M
        */
    cout << "----------指针练习----------" << endl;
    extern int x;   //声明变量
    //extern int x = 100;   //不允许定义外部的变量的局部声明初始化 
    int y = 10;          //定义 
    int *yPtr = &y;


    //int *yPtr2 = y;           //错误，不能赋非指针值
    cout << &y << endl;         //y的地址 
    cout << yPtr << endl;       //y的地址
    cout << *yPtr << endl;      //y的值
    cout << *&yPtr << endl;     //y的地址，也就是yPtr
    cout << &*yPtr << endl;     //y的地址，也就是yPtr   
    //cout << &*y << endl;      //*y指针未定义，
    cout << *&y << endl;        //y的值
    int &y2 = y;
    //int y2 = 20;              //int 和 int& 的间接寻址级别不同 
    cout << "&y2: " << &y2 << endl;    //指向y的地址

    cout << "---------空指针----------" << endl;
    int *nPtr1 = nullptr;
    int *nPtr2 = 0;
    int *nPtr3 = NULL;
    //cout << *nPtr1 << endl;
    //cout << *nPtr2 << endl;
    //cout << *nPtr3 << endl;

    int i220 = 42;
    int *i220Ptr = &i220;
    *i220Ptr = *i220Ptr**i220Ptr;   //重新指向运算结果 
    cout << "i220: " << i220 << endl;
    cout << "*i220Ptr: " << *i220Ptr << endl;

    cout << "---------指针判断练习----------" << endl;

    *i220Ptr = NULL;
    cout << i220Ptr << endl;
    cout << *i220Ptr << endl;
    i220 = 0;
    if (i220Ptr)
        cout << 1 << endl;
    else
        cout << 0 << endl;

    if (*i220Ptr)
        cout << 1 << endl;
    else
        cout << 0 << endl;



    return 0;
}