//����5�������������ֵ����Сֵ

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void test2_l6(){

    //��������5����
	int num1;
	int num2;
	int num3;
	int num4;
	int num5;
    int max;
    int min;

	cout << "����5����: " << endl;
    cin >> num1 >> num2 >> num3 >> num4 >> num5 ;
    
    max = num1;
    min = num1;

    if (max < num2)
        max = num2;
    if (max < num3)
        max = num3;
    if (max < num4)
        max = num4;
    if (max < num5)
        max = num5;
    cout << "5�����е����ֵ�ǣ� " << max << endl;



}