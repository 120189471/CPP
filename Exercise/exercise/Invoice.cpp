#include<string>
using std::string;

#include"Invoice.h"

Invoice::Invoice(string newPartNumber, string newPartDescription,
    int newSaleNumber, int newUnitPrice){
    setPartNumber(newPartNumber);
    setPartDescription(newPartDescription);
    setSaleNumber(newSaleNumber);
    setUnitPrice(newUnitPrice);
}

void Invoice::setPartNumber(string newPartNumber){
    partNumber = newPartNumber;
}
string Invoice::getPartNumber(){
    return partNumber;
}

void Invoice::setPartDescription(string newPartDescription){
    partDescription = newPartDescription;
}

string Invoice::getPartDescription(){
    return partDescription;
}

void Invoice::setSaleNumber(int newSaleNumber){
    saleNumber = newSaleNumber;
}
int Invoice::getSaleNumber(){
    return saleNumber;
}

void Invoice::setUnitPrice(int newUnitPrice){
    if (newUnitPrice >= 0)
        unitPrice = newUnitPrice;
    if (newUnitPrice < 0)
        unitPrice = 0;
}

int Invoice::getUnitPrice(){
    return unitPrice;
}

int Invoice::getInvoiceAmount(){
    int sum;
    if (saleNumber >= 0)
        sum = saleNumber*unitPrice;
    if (saleNumber < 0)
        sum = 0;
    return sum;
}

