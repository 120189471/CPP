//dx.20160630  l04
//问题，创建一个发票(Invoice) 的类 ,商店用它表示点钟售出的一款商品的一种发票
/*
    分析：
    a.定义数据成员 string partNumber，零件描述，string partDescription 售出量 int saleNumber 单价 int unitPrice(单价>=0,如果小于0，输入0)
    b.构造函数
    c.每个数据成员获得set和get
    d.getInvoiceAmount成员函数，计算发票额（售出量乘以单价） 返回int，售出量>=0,如果小于0，输入0
    e.测试类
        
*/

#include <string>
using std::string;

class Invoice{
public:
    Invoice(string, string, int, int); //零件编号,零件描述，售出量，单价
    void setPartNumber(string);
    string getPartNumber();
    void setPartDescription(string);
    string getPartDescription();
    void setSaleNumber(int);
    int getSaleNumber();
    void setUnitPrice(int);
    int getUnitPrice();
    int getInvoiceAmount();
private:
    string partNumber;          //零件号
    string partDescription;     //零件描述
    int saleNumber;             //售出量
    int unitPrice;              //单价

};