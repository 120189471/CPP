#ifndef SALES_DATA_H
#define SALES_DATA_H

#include<string>
using std::string;

struct Sales_item{
    string bookNO;              //����book��� 
    unsigned units_sold = 0;    //�۳���
    double revenue = 0.0;       //����������
};


#endif