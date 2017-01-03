#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using std::cout;
using std::endl;

int main()
{
    int a[10] = { 99, 3, 44, 2, 3, 44, 5, 5, 6, 67 };
    int* pa = a;
    printf("%c,%c\n",a,*a);
    cout << "a: " << a << "\n" << "*a: " << *a << endl;
    system("PAUSE");
    return 0;
}