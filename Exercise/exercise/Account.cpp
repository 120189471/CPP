#include <iostream>
using std::cout;
using std::endl;

#include"Account.h"
Account::Account(){};

Account::Account(int initialBalance){
    if (initialBalance >= 0){
        balance = initialBalance;
    }
    else{
        balance = 0;
        cout << "ÊäÈë³õÊ¼½ð¶î´íÎó" << endl;
    }
}

int Account::credit(int addMoney){
    if (addMoney >= 0){
        balance = addMoney + balance;
    }
    else{
        cout << "ÊäÈë½ð¶îÊý¶î´íÎó£º" << endl;
    }
    return balance;
}

void Account::debit(int withdrawals){
    if (withdrawals <= balance){
        balance = balance - withdrawals;
    }
    else{
        cout << "Debit amount exceeded account balance" << endl;
    }
    
}
int Account::getBalance(){
    return balance;
}
