/*
    1.¼�����ݣ�
    2.�������֣�����������֣�������������г�link��
    char:string;

    3.for int i ���������������������
    3.1 �ж�����
    ����������ţ�
    {
    ִ��3��ѭ���Ǵ�i��ʼ��
    ɾ������
    }
    else if
    {
    �����*��/��
    ����ǰ��д��ǰһλ��
    ɾ�������λ�ͺ�һλ��
    }else if
    {
    �����+��-��
    ����ǰ��д��ǰһλ��
    ɾ�������λ�ͺ�һλ��
    }
    ���ص�һλ��
    4. �����һλ����
    */

#include <iostream>
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <list>
using std::list;

#include <stdlib.h>

//����2���ַ����ĺͲ�����Ϊ�ַ���
string add(string  a, string  b)
{
    char c[65];
    int temp = atoi(a.c_str()) + atoi(b.c_str());
    _itoa_s(temp, c, 10);
    return c;
}

//2���ַ��������������ַ���
string sub(string a, string b)
{
    char c[65];
    int temp = atoi(a.c_str()) - atoi(b.c_str());
    _itoa_s(temp, c, 10);
    //string s(&a[0], &a[strlen(a)]);
    //string s = *c;
    return c;
}

//2���ַ������˷������ַ���
string mult(string a, string b)
{
    char c[65];
    int temp = atoi(a.c_str()) * atoi(b.c_str());
    _itoa_s(temp, c, 10);

    return c;
}

//2���ַ��������������ַ���
string div(string a, string b)
{
    char c[65];
    int temp = atoi(a.c_str()) / atoi(b.c_str());
    _itoa_s(temp, c, 10);
    return c;
}

/*
//���ַ����ָ����������ʽ��д��vector���棬˵����
�ж������Ÿ������Ѹ����ֲ�д��vector����
*/
void fenge(string s, vector<string> &son_vs)
{
    //vector<string> son_vs;
    int sun_number = 0;
    string sun_mothervs;
    char nextc = '?';

    son_vs.push_back(sun_mothervs);

    for (char c : s)
    {
        if (c == '(')
        {
            ++sun_number;

            son_vs.push_back(sun_mothervs);

            son_vs[sun_number - 1] += nextc;
            continue;
        }
        else;

        if (c == ')')
        {
            --sun_number;
            continue;
        }
        else;

        son_vs[sun_number] += c;
    }

    //return son_vs;
}

//���������ŵ�����������
/*
    ���ַ�������Ϊvector��
    �����жϳ˳������жϼӼ���
    Ȼ����ݷ�������Ӧ���㣻
*/
string operation(string &s)
{
    vector<string> vs;
    string temp;
    //int signs_add = 0;
    //int signs_sub = 0;
    //int signs_mult = 0;
    // int signs_div = 0;
    int calculating_signs = 0;
    int operation_number;
    int last = 0;

    for (char c : s)
    {
        ++last;
        if (c != '+' && c != '-' && c != '*' && c != '/')
        {
            temp = temp + c;

            if (last == s.size())
            {
                vs.push_back(temp);
                temp = "";
            }
        }
        else
        {
            /*
            switch (c)
            {
            case '+':
            signs_add++;
            break;
            case '-':
            signs_sub++;
            break;
            case '*':
            signs_mult++;
            break;
            case '/':
            signs_div;
            break;
            default:
            cerr << "һ�㲻��������" << endl;
            }

            */
            calculating_signs++;
            vs.push_back(temp);
            temp = c;
            vs.push_back(temp);
            temp = "";
        }
    }

    operation_number = vs.size();

    for (int i = 0; i != calculating_signs; i++)
    {

        //for (int j = 1; j != vs.size();j++)
        for (vector<string>::iterator iter = vs.begin(); iter != vs.end(); iter++)
        {

            if (*iter == "*" || *iter == "/")
            {
                if (*iter == "*")
                {
                    *(iter - 1) = mult(*(iter - 1), *(iter + 1));
                    vs.erase(iter, (iter + 2));
                    break;
                }
                if (*iter == "/")
                {
                    *(iter - 1) = div(*(iter - 1), *(iter + 1));
                    vs.erase(iter, (iter + 2));

                    break;
                }
            }
            else if (*iter == "+" || *iter == "-")
            {
                if (*iter == "+")
                {
                    *(iter - 1) = add(*(iter - 1), *(iter + 1));
                    vs.erase(iter, (iter + 2));
                    break;
                }
                if (*iter == "-")
                {
                    *(iter - 1) = sub(*(iter - 1), *(iter + 1));
                    vs.erase(iter, (iter + 2));
                    break;
                }
            }
            else
            {
                cout << "����������  ~��~ \n ";
            }
        }
    }

    return vs.front();
}


//�������
/*
    ��vector�����ڶ��㿪ʼ����ÿ���ַ����͵���ʽ�Ľ��������������ظ�������ʽ����λ
    
    forѭ��������,�ǽ��ڲ�����Ŵ�����š������滻�������ڵ��ַ���ý��
        ע�����ַ��������滻�����ڵ��ַ����������⣬���Կ��ǽ�char������ �ַ�������
*/

void result(string s)
{
    vector<string> vs;
    fenge(s, vs);
    for (int i = vs.size() - 2; i != -1; i--)
    {
        const char *sun_sc = vs[i].c_str();

        //for (int j = 0; j != sun_s->size(); j++)
        for (int j = 0; j != vs[i].size(); j++)
        {

            if (sun_sc[j] == '?')
            {
                string temp = operation(vs[i + 1]);
                vs[i].insert(j, temp);
                vs[i].erase(j + temp.size(), 1);

                break;
            }
        }
    }
    cout << atoi(operation(vs[0]).c_str()) << endl;
}

int main()
{
    string s;
    getline(cin, s);

    result(s);

    //
    /*
    for (char c : s)
    {
    if (c != '+' | c != '-' | c != '*' | c != '/' | c != '(' | c != ')')
    temp = temp + c;
    else
    {
    vs.push_back(temp);
    temp = c;
    vs.push_back(temp);
    temp = "";
    }
    }
    */
    system("PAUSE");
    return 0;
}

