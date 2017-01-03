/*
    1.录入数据；
    2.按照数字，运算符，数字，运算符。。。切成link。
    char:string;

    3.for int i 运算符个数，不包括括号
    3.1 判断括号
    如果有左括号，
    {
    执行3，循环是从i开始；
    删除括号
    }
    else if
    {
    如果有*，/；
    计算前后并写入前一位；
    删除运算符位和后一位；
    }else if
    {
    如果有+，-；
    计算前后并写入前一位；
    删除运算符位和后一位；
    }
    返回第一位；
    4. 输出第一位数字
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

//计算2个字符串的和并返回为字符串
string add(string  a, string  b)
{
    char c[65];
    int temp = atoi(a.c_str()) + atoi(b.c_str());
    _itoa_s(temp, c, 10);
    return c;
}

//2个字符串做减法返回字符串
string sub(string a, string b)
{
    char c[65];
    int temp = atoi(a.c_str()) - atoi(b.c_str());
    _itoa_s(temp, c, 10);
    //string s(&a[0], &a[strlen(a)]);
    //string s = *c;
    return c;
}

//2个字符串做乘法返回字符串
string mult(string a, string b)
{
    char c[65];
    int temp = atoi(a.c_str()) * atoi(b.c_str());
    _itoa_s(temp, c, 10);

    return c;
}

//2个字符串做除法返回字符串
string div(string a, string b)
{
    char c[65];
    int temp = atoi(a.c_str()) / atoi(b.c_str());
    _itoa_s(temp, c, 10);
    return c;
}

/*
//将字符串分割成无括号算式并写入vector里面，说明：
判断左括号个数，已个数分层写入vector各项
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

//计算无括号的四则混合运算
/*
    将字符串割裂为vector；
    优先判断乘除，在判断加减；
    然后根据符号作对应运算；
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
            cerr << "一般不会出这个错" << endl;
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
                cout << "遍历到数字  ~。~ \n ";
            }
        }
    }

    return vs.front();
}


//结果运算
/*
    从vector倒数第二层开始计算每个字符类型的算式的结果，并将结果返回给整个算式的首位
    
    for循环的作用,是将内层的括号代表符号“？”替换成括号内的字符算得结果
        注：用字符“？”替换括号内的字符数是有问题，可以考虑将char？换成 字符串（）
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

