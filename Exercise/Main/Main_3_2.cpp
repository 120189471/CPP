#include<string>
using std::string;
using std::getline;
// using std::is_empty;

#include<iostream>
using std::cout;
using std::endl;
using std::cin;

int main_3_2(){
    //使用等号初始化一个变量，拷贝初始化（copy initialization）
    //不试用等号 直接初始化（direct initialization）
    string s1;
    string s2 = s1;
    string s3 = "hiya";
    string s4(10, 'c');      //结果是10个C
    cout << s1 << endl;

    //string的操作
    /*
    os<<s           输入
    is>>s           读取字符，以空白分隔，返回is，开头的空白忽略，空格符，制表符，换行符
    getline(is,s)   从is中读取一行赋值给s，返回is,当前行开头的文件不忽略
    s.empty()        为空返回true，否则返回false；
    s.size()        返回字符的个数
    s[n]            返回第n个字符的引用，位置从0开始
    s1+s2           返回s1和s2连接后的结果
    s1=s2           用s2的副本代替s1中原来的字符
    s1==s2          如果所含字符完全一样，则相等，对大小写敏感
    s1！=s2
    <,<=,>,>=       利用字符在字典中中的顺序进行比较，对大小写敏感
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