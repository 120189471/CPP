#include<iostream>
using std::cout;
using std::endl;

#include"INvoice.h"

int Invoice_main(){
    Invoice invoiceTest1("p001", "���һ", 5000, 3);
    cout << "\nPartNumber:        " << invoiceTest1.getPartNumber()
        << "\nPartDescription:     " << invoiceTest1.getPartDescription()
        << "\nSaleNumber:          " << invoiceTest1.getSaleNumber() 
        << "\nUnitPrice:          "<<invoiceTest1.getUnitPrice();
    cout << "\n��Ʊ�ܶ��ǣ� " << invoiceTest1.getInvoiceAmount() << endl;

    Invoice invoiceTest2("p002", "�����", -10, 3);
    cout << "\n�������Ʊ�ܶ "<<invoiceTest2.getInvoiceAmount() << endl;

    Invoice invoiceTest3("p003", "�����", 10, -99);
    cout << "\n�������Ʊ�ܶ " << invoiceTest3.getInvoiceAmount() << endl;

    return 0;

}