#include<iostream>
using std::cout;
using std::endl;

//extern �ڶ���ļ�֮�乲��const�������ڱ�������֮ǰ���extern�ؼ���
extern const int buffSize;

int main_2_4(){
    const int buffSize = 512; //��������ⲿ�ģ�������ʼ����������
    //buffSize = 1024;        //���ܸ�������ֵ

    cout << "---------�Գ���������---------" << endl;
    //C++������������ı��������󶨵Ķ���

    const int &bf = buffSize;
    cout << &buffSize << endl;
    cout << &bf << endl;
    int i = 42;
    //int &bf = i;      // �ض��壻��ͬ���������η�
    const int &i1 = i;
    i = 55;
    cout << i1 << endl;

    int j = 42;
    const int &r1 = i;
    const int &r2 = 42;
    const int &r3 = r1 * 2;
    //int &r4 = r1 * 2;     //�޷��ӡ�int��ת��Ϊ��int &

    cout << "---------ָ������ָ��---------" << endl;

    const double pi = 3.14;
    //double *piPtr = &pi;
    const double *cPtr = &pi;
    //*cPtr = 42;       //���ʽ�����ǿ���������ֵ
    double dval = 3.14;
    cPtr = &dval;       //����ͨ��cPtr�ı�dval��ֵ
    //*cPtr = 99;         //���ʽ�����ǿ���������ֵ

    double E = 2.71;
    const double *ePtr = &E;
    E = 2.7182;
    cout << E << endl;
    //*ePtr = pi;
    return 0;
}