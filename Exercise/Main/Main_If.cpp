//dix.20160816
//���ֶ�Ӧ��ĸ
/*����
    100 -��A++
    60  -> F

    60-69 ->D
    70-79 ->c
    80-89 ->B
    90-99 ->A

    ĩβ
    8,9  ->+
    0,1,2 ->-

    */

#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#include<string>
using std::string;

string getMark(int markScores){
    if (markScores % 10 < 3){
        return "-";
    }
    else if (markScores % 10 > 7){
        return "+";
    }
}

int main_If(){
    int scores = 0;
    cin >> scores;

    if (scores > 100 || scores < 0){
        cout << "����ɼ����������˳�����������" << endl;
    }
    else if (scores == 100){
        cout << "A++" << endl;
    }
    else if (scores / 10 == 9){
        cout << "B" << getMark(scores) << endl;
    }
    else if (scores / 10 == 8){
        cout << "C" << getMark(scores) << endl;
    }
    else if (scores / 10 == 7){
        cout << "D" << getMark(scores) << endl;
    }
    else if (scores / 10 == 6){
        cout << "E" << getMark(scores) << endl;
    }
    else if (scores / 10 < 6){
        cout << "F" << endl;
    }
    else{
        cout << "������ĳɼ������⣬��������⣡" << endl;
    }

    return 0;
}

