#include<string>
using std::string;

#include<iostream>
using std::cout;
using std::endl;

int main_lx_3_6(){
    //��for���ַ����е������ַ��滻��x
    string s1("abcdefghijklmnopqistuvwxyz0123456789");
    //��һ�ַ�����λ������
    /*for (auto &c : s1){
        c = 'X';
        }

        */
    //�ڶ��ַ������±������
    /*
    for (auto n = 0; n <= s1.size(); n++){
    s1[n] = 'X';
    }
    */
    //��char����ѭ���ı���
    /*
        for (char &n : s1){
        n = 'X';
        }
        */
    //��while�޸��������
    //while (decltype(s1.size()) n = 0 && n <= s1.size()){
    decltype(s1.size()) n = 0;
    while (n <= s1.size()){
        s1[n] = 'x';
        n++;
    }

    cout << s1 << endl;
    cout << s1.size() << endl;


    return 0;
}