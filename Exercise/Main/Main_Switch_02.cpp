//dix.02160817
//��ϰ5.9����if��cin�ж����ı����ж���Ԫ����ĸ

#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#include<string>
using std::string;
using std::getline;

int main_Switch_02() {
    string s;

    unsigned int aCnt = 0;
    unsigned int eCnt = 0;
    unsigned int iCnt = 0;
    unsigned int oCnt = 0;
    unsigned int uCnt = 0;
    unsigned int spaceCnt = 0;
    unsigned int enterCnt = 0;
    unsigned int tableCnt = 0;
    unsigned int NonVowelCnt = 0;

    getline(cin, s);

    /*
    for (auto c : s){
        if (c == 'a' || c == 'A'){
            ++aCnt;
        }
        else if (c == 'e'){
            ++eCnt;
        }
        else if (c == 'i'){
            ++iCnt;
        }
        else if (c == 'o'){
            ++oCnt;
        } else if (c == 'u'){
            ++uCnt;
        }
        else if (isalpha(c)){
            ++NonVowelCnt;
        }
        else
            ;
    }
    */
    for (auto c : s){
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
        case' ':
            ++spaceCnt;
            break;
        case'\n':
            ++enterCnt;
            break;
        case'\t':
            ++tableCnt;
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
        << "�ո��ַ�: " << spaceCnt << endl
        << "�س��ַ�: " << enterCnt << endl
        << "�Ʊ��: " << tableCnt << endl
        << "��Ԫ���ַ�: " << NonVowelCnt << endl;

    

    return 0;
}