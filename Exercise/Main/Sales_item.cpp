#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

#include"Sales_item.h"
//Sales_item 的格式是 isbn 个数 价格 例如0-202-78346-z 9 30.31

int main_Sales_item(){
    /*
    //输入2个相同的isbn并作相加处理
    //输入并显示book的相关信息
    Sales_item book;
    //输入ISBN号 ，售出册数以及销售价格
    cin >> book;
    cout << book << endl;
    */
    /*
    Sales_item item1, item2;
    cin >> item1 >> item2;
    cout << item1 + item2 << endl;
    */
    /*
    //判断2个sibn号是否一致
    Sales_item item1;
    Sales_item item2;

    cin >> item1 >> item2;

    if (item1.isbn() == item2.isbn()){
    cout << item1 + item2 << endl;
    return 0;
    }
    else{
    cerr << "Data must refer to same ISBN" << endl;
    return -1;
    }

    */
    //读取多个相同的isbn的销售记录，输出记录的和
    //使用while，定义一个总计的值，个数的值，然后累加，如果没有输入，则显示没有，如果有，则显示累加值，如果输入eof，这退出并显示结果 
    Sales_item itemSum;
    Sales_item otherItem;
    int itemCount = 1;
    cout << "请输入第 " << itemCount << " 个book的ISBN：" << endl;
    if (cin >> itemSum){
        //这个地方逻辑有问题 
        while (cout << "请输入第 " << itemCount + 1 << " 个book的ISBN：" << endl&&cin >> otherItem){

            if (otherItem.isbn() == itemSum.isbn()){
                itemSum = itemSum + otherItem;
                ++itemCount;
            }
            else{
                cout << "输入的ISBN不一致，不计入计算" << endl;
                //return -1;
            }
        }
        cout << "总共输入 " << itemCount << "次\n"
            << "统计结果如下： \n" << itemSum << endl;
    }
    else{
        cout << "没有输入，系统退出。" << endl;
    }
    return 0;
}