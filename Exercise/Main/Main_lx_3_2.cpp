#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#include<string>
using std::string;
using std::getline;

int main_lx_3_2(){
    string line;
    //����һ�У�����һ����
    
    getline(cin, line);
    cout << line<< endl;
    
    //һ�ζ���һ����

    while (cin >> line){
        cout << line << endl;;
    }
    return 0;
}
