#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#include<string>
using std::string;
using std::getline;

int main_lx_3_4(){


    string s1;
    string s2;
    //cin >> s1 >> s2;

    //����2���ַ������Ƚϴ�С���������ȣ������ģ�
    /*
    if (s1 == s2){
    cout << "�����ַ���ͬ" << endl;
    }
    else{
    if (s1 > s2){
    cout << "���ֵ�ǣ� " << s1;
    }
    else{
    cout << "���ֵ�ǣ� " << s2;
    }
    }
    */

    //����2���ַ������Ƚ��Ƿ�ȳ���������ȣ��������
    /*
    if (s1.size() == s2.size()){
        cout << "���ַ���������ͬ" << endl;
    }
    else{
        if (s1.size() > s2.size()){
            cout << "�����ļ��ǣ� " << s1 << " \n�䳤���ǣ�" << s1.size() << endl;
        }
        else{
            cout << "�����ļ��ǣ� " << s2 << " \n�䳤���ǣ�" << s2.size() << endl;
        }
    }
    */
    //���봮���������Ǵ�����Ȼ���д���룬�����Ǽ���ո������
    /*
    string word;
    string sWord;
    while (cin >> word){
        sWord = sWord + word+" ";
        cout << sWord << endl;
    }
    */
    //��ǿforѭ��
    /*
    string word="abcdefghijklmnopqistuvwxyz";
    for (char c : word){
        cout << c << endl;
    }
    //
    */

    string s("Hello Word!!!");
        decltype(s.size()) punct_cnt = 0;
        for (auto c : s)
            if (ispunct(c))
                ++punct_cnt;
        cout << punct_cnt << ".............." << s << endl;


    return 0;
}