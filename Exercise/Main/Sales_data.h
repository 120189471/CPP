#ifndef SALES_DATA_H
#define SALES_DATA_H

#include<string>
using std::string;

struct Sales_item{
    string bookNO;              //定义book编号 
    unsigned units_sold = 0;    //售出量
    double revenue = 0.0;       //销售总收入
};


#endif