//����0��10�� ƽ���������������Ʊ����ӡ����
//integer	square	cube

//���� 
//
//1.����10������ֵ�ֱ�Ϊ1��10
//2.�����ͷ
//3.����ڶ��е�11��

//�������Ӧ�ÿ��ԸĽ�

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

void test2_l10(){
    cout << "integer\t" << "square\t" << "cube\t" << endl;
    for (size_t i = 0; i < 9; i++)
    {
        int num = i + 1;
        cout << num << "\t" << num*num << "\t" << num*num*num << endl;
    }
}
