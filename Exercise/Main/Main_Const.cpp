#include<iostream>
using std::cout;
using std::endl;

//�ļ��乲�������ڿ���
extern const int bufSize2=512;

int main() {
    //����һ��const
    const int ci = 42;

    //�Գ���������,�����޸İ󶨵Ķ���
    const int &r1 = ci;

    //����������
    const int &r2 = 24;
    const int &r3 = r1 * 2;
    //int &r4=r1*2;

    //����ת��ʱ������������ʹ����ʱ��
    double dval = 3.14;
    const int &ri = dval;
    
    cout << r1 << endl;
    cout << &r1 << endl;

    //ָ������ָ��
    //����ͨ��ָ���޸Ķ����ֵ������û�涨�������������޸�
    const double *dvalPtr = &dval;
    
    //����ָ��
    //1.�����ʼ����2.��ʼ����ֵ���ڸı�
    const double *const dvalPtr2 = &dval;

    //����const�� ָ���Ǹ�����
    //�ײ�const�� ָ��ָ�����һ������


    

    
    
}