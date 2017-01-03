#include<iostream>
using std::cout;
using std::endl;

#include"INvoice.h"

int Invoice_main(){
    Invoice invoiceTest1("p001", "零件一", 5000, 3);
    cout << "\nPartNumber:        " << invoiceTest1.getPartNumber()
        << "\nPartDescription:     " << invoiceTest1.getPartDescription()
        << "\nSaleNumber:          " << invoiceTest1.getSaleNumber() 
        << "\nUnitPrice:          "<<invoiceTest1.getUnitPrice();
    cout << "\n发票总额是： " << invoiceTest1.getInvoiceAmount() << endl;

    Invoice invoiceTest2("p002", "零件二", -10, 3);
    cout << "\n零件二发票总额： "<<invoiceTest2.getInvoiceAmount() << endl;

    Invoice invoiceTest3("p003", "零件三", 10, -99);
    cout << "\n零件三发票总额： " << invoiceTest3.getInvoiceAmount() << endl;

    return 0;

}