#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main_2_1(){
    cout << "----------�������----------" << endl;
    int units_sold1 = 0;
    int units_sold2 = { 0 };
    int units_sold3{ 0 };
    int units_sold4(0);
    
    /*
    int i = 10;
    //��bool��ֵ��boolʱ�������ʼ��Ϊ0ʱ�����ӦΪfalse������Ϊtrue��
    //bool��ֵ����boolʱ��false->0,true->1;
    if (i){
    cout << "True" << endl;
    }
    else{
    cout << "False" << endl;
    }
    */
    unsigned u = 10;
    unsigned u2 = 42;
    int i = 10;
    int i2 = 42;
    cout << u2 - u << endl;
    cout << u - u2 << endl;

    cout << i2 - i << endl;
    cout << i - i2 << endl;
    cout << i - u << endl;
    cout << u - i << endl;

    //����ֵ��literal��
    //20/*ʮ����*/         ����ֵ���� int,long,long long,
    //024/*�˽���*/        ����ֵ���� int,unsigned int,long, unsigned long,long long, unsigned long long
    //0xl4/*ʮ������*/     ����ֵ���� int,unsigned int,long, unsigned long,long long, unsigned long long
    //����������ֵ֮�� double
    //�ַ�������ֵ�����ַ�������ɵ����飬��β��ӿ��ַ���'\0'��
    //ת�����У�escape sequence��
    /*
        \n    ����      \t   �����Ʊ��      \a     ������
        \v    �����Ʊ��\b   �˸��          \?     �ʺ�
        \r    �س���    \f   ��ֽ��

        Latin_1�ַ���

        \7 ������      \12   ����            \40     �ո�
        \0 ���ַ�      \115  �ַ�M           \x4d    �ַ�M
        */
    cout << "----------ָ����ϰ----------" << endl;
    extern int x;   //��������
    //extern int x = 100;   //���������ⲿ�ı����ľֲ�������ʼ�� 
    int y = 10;          //���� 
    int *yPtr = &y;


    //int *yPtr2 = y;           //���󣬲��ܸ���ָ��ֵ
    cout << &y << endl;         //y�ĵ�ַ 
    cout << yPtr << endl;       //y�ĵ�ַ
    cout << *yPtr << endl;      //y��ֵ
    cout << *&yPtr << endl;     //y�ĵ�ַ��Ҳ����yPtr
    cout << &*yPtr << endl;     //y�ĵ�ַ��Ҳ����yPtr   
    //cout << &*y << endl;      //*yָ��δ���壬
    cout << *&y << endl;        //y��ֵ
    int &y2 = y;
    //int y2 = 20;              //int �� int& �ļ��Ѱַ����ͬ 
    cout << "&y2: " << &y2 << endl;    //ָ��y�ĵ�ַ

    cout << "---------��ָ��----------" << endl;
    int *nPtr1 = nullptr;
    int *nPtr2 = 0;
    int *nPtr3 = NULL;
    //cout << *nPtr1 << endl;
    //cout << *nPtr2 << endl;
    //cout << *nPtr3 << endl;

    int i220 = 42;
    int *i220Ptr = &i220;
    *i220Ptr = *i220Ptr**i220Ptr;   //����ָ�������� 
    cout << "i220: " << i220 << endl;
    cout << "*i220Ptr: " << *i220Ptr << endl;

    cout << "---------ָ���ж���ϰ----------" << endl;

    *i220Ptr = NULL;
    cout << i220Ptr << endl;
    cout << *i220Ptr << endl;
    i220 = 0;
    if (i220Ptr)
        cout << 1 << endl;
    else
        cout << 0 << endl;

    if (*i220Ptr)
        cout << 1 << endl;
    else
        cout << 0 << endl;



    return 0;
}