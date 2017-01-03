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
        cout << "�����ʼ������" << endl;
    }
}

int Account::credit(int addMoney){
    if (addMoney >= 0){
        balance = addMoney + balance;
    }
    else{
        cout << "�������������" << endl;
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
