#include<string>
using std::string;
using std::getline;
// using std::is_empty;

#include<iostream>
using std::cout;
using std::endl;
using std::cin;

int main_3_2(){
    //ʹ�õȺų�ʼ��һ��������������ʼ����copy initialization��
    //�����õȺ� ֱ�ӳ�ʼ����direct initialization��
    string s1;
    string s2 = s1;
    string s3 = "hiya";
    string s4(10, 'c');      //�����10��C
    cout << s1 << endl;

    //string�Ĳ���
    /*
    os<<s           ����
    is>>s           ��ȡ�ַ����Կհ׷ָ�������is����ͷ�Ŀհ׺��ԣ��ո�����Ʊ�������з�
    getline(is,s)   ��is�ж�ȡһ�и�ֵ��s������is,��ǰ�п�ͷ���ļ�������
    s.empty()        Ϊ�շ���true�����򷵻�false��
    s.size()        �����ַ��ĸ���
    s[n]            ���ص�n���ַ������ã�λ�ô�0��ʼ
    s1+s2           ����s1��s2���Ӻ�Ľ��
    s1=s2           ��s2�ĸ�������s1��ԭ�����ַ�
    s1==s2          ��������ַ���ȫһ��������ȣ��Դ�Сд����
    s1��=s2
    <,<=,>,>=       �����ַ����ֵ����е�˳����бȽϣ��Դ�Сд����
    */
    /*
    string word;
    while (cin >> word){
    cout << word << endl;
    }
    */

    string line;
    cout << line.empty() << endl;
    while (getline(cin, line)){
        if (!line.empty()){
            cout << line.empty() << endl;
            cout << line.size() << endl;
            cout << line << endl;
        }
    }

    return 0;
}