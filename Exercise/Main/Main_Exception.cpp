#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#include<stdexcept>
using std::runtime_error;

int main_Exception() {
    int i;
    int j;

    cin >> i >> j;
    try {
        if (j == 0)
            throw runtime_error("j 不能等于0");
    }
    catch (runtime_error) {
    }
    cout << i / j << endl;
}