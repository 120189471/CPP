#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using std::cerr;

#include"Sales_item.h"
//Sales_item �ĸ�ʽ�� isbn ���� �۸� ����0-202-78346-z 9 30.31

int main_Sales_item(){
    /*
    //����2����ͬ��isbn������Ӵ���
    //���벢��ʾbook�������Ϣ
    Sales_item book;
    //����ISBN�� ���۳������Լ����ۼ۸�
    cin >> book;
    cout << book << endl;
    */
    /*
    Sales_item item1, item2;
    cin >> item1 >> item2;
    cout << item1 + item2 << endl;
    */
    /*
    //�ж�2��sibn���Ƿ�һ��
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
    //��ȡ�����ͬ��isbn�����ۼ�¼�������¼�ĺ�
    //ʹ��while������һ���ܼƵ�ֵ��������ֵ��Ȼ���ۼӣ����û�����룬����ʾû�У�����У�����ʾ�ۼ�ֵ���������eof�����˳�����ʾ��� 
    Sales_item itemSum;
    Sales_item otherItem;
    int itemCount = 1;
    cout << "������� " << itemCount << " ��book��ISBN��" << endl;
    if (cin >> itemSum){
        //����ط��߼������� 
        while (cout << "������� " << itemCount + 1 << " ��book��ISBN��" << endl&&cin >> otherItem){

            if (otherItem.isbn() == itemSum.isbn()){
                itemSum = itemSum + otherItem;
                ++itemCount;
            }
            else{
                cout << "�����ISBN��һ�£����������" << endl;
                //return -1;
            }
        }
        cout << "�ܹ����� " << itemCount << "��\n"
            << "ͳ�ƽ�����£� \n" << itemSum << endl;
    }
    else{
        cout << "û�����룬ϵͳ�˳���" << endl;
    }
    return 0;
}