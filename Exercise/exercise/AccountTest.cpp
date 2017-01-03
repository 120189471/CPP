#include<iostream>
using std::cout;
using std::endl;

#include"Account.h"

int Acccount_main(){
    Account accountTestN();
    //cout << "ÕË»§Ê£Óà¶îÊÇ£º " << accountTestN().getBalance << endl;
    Account accountTest1(-1);
    cout << "ÕË»§Ê£ÓàÓà¶îÊÇ£º " << accountTest1.getBalance() << endl;

    Account accountTest2(0);
    accountTest2.credit(3000);
    cout << "ÕË»§Ê£ÓàÓà¶îÊÇ£º " << accountTest2.getBalance() << endl;
    accountTest2.debit(5000);
    cout << "ÕË»§Ê£ÓàÓà¶îÊÇ£º " << accountTest2.getBalance() << endl;
    accountTest2.debit(300);
    cout << "ÕË»§Ê£ÓàÓà¶îÊÇ£º " << accountTest2.getBalance() << endl;
    return 0;
}