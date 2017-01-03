//dx.20160630  l04
//���⣬����һ����Ʊ(Invoice) ���� ,�̵�������ʾ�����۳���һ����Ʒ��һ�ַ�Ʊ
/*
    ������
    a.�������ݳ�Ա string partNumber�����������string partDescription �۳��� int saleNumber ���� int unitPrice(����>=0,���С��0������0)
    b.���캯��
    c.ÿ�����ݳ�Ա���set��get
    d.getInvoiceAmount��Ա���������㷢Ʊ��۳������Ե��ۣ� ����int���۳���>=0,���С��0������0
    e.������
        
*/

#include <string>
using std::string;

class Invoice{
public:
    Invoice(string, string, int, int); //������,����������۳���������
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
    string partNumber;          //�����
    string partDescription;     //�������
    int saleNumber;             //�۳���
    int unitPrice;              //����

};