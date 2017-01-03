//统计元音字母出现数值

#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main_Switch_01(){
    unsigned int aCnt = 0;
    unsigned int eCnt = 0;
    unsigned int iCnt = 0;
    unsigned int oCnt = 0;
    unsigned int uCnt = 0;
    unsigned int NonVowelCnt=0;
    char c;
    while (cin >> c){
        switch (c){
        case 'a':
        case 'A':
            ++aCnt;
            break;
        case'e':
        case'E':
            ++eCnt;
            break;
        case'i':
        case'I':
            ++iCnt;
            break;
        case'o':
        case'O':
            ++oCnt;
            break;
        case'u': 
        case'U':
            ++uCnt;
            break;
        default:
            ++NonVowelCnt;
            break;
        }
    }

    cout << "a: " << aCnt << endl
        << "e: " << eCnt << endl
        << "i: " << iCnt << endl
        << "o: " << oCnt << endl
        << "u: " << uCnt << endl
        << "非元音字符: " << NonVowelCnt << endl;
    return 0;
}