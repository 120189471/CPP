#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#include"Sales_data.h"

int main_Sales_data(){
    Sales_item data1;
    Sales_item data2;

    double price = 0.0;         //销售单价

    cin >> data1.bookNO >> data1.units_sold >> price;
    data1.revenue = price*data1.units_sold;

    cin >> data2.bookNO >> data2.units_sold >> price;
    data2.revenue = price*data2.units_sold;

    //统计数据
    Sales_item sum;

    if (data1.bookNO == data2.bookNO){
        sum.bookNO = data1.bookNO;
        sum.revenue = data1.revenue + data2.revenue;
        sum.units_sold = data1.units_sold + data2.units_sold;
        cout << sum.bookNO << " " << sum.units_sold << " " << sum.revenue<< endl;
    }
    else
    {
        cout << "你输入的编号不对" << endl;
    }
    return 0;
}