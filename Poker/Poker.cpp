#define _CRT_RAND_S

#include "Poker.h"

#include <cstdlib>
using std::rand;
using std::srand;

#include <ctime>
using std::time;

#include <iostream>
using std::cout;
using std::endl;

//初始化牌
Poker::Poker()
{
    for (int i = 0; i < 52; i++)
    {
        char c[8] ;
        _itoa(i, c, 10);
        string s;
        for (int j = 0; j < 9; j++)
        {
            s += c[j];
        }
        
        switch (i / 13)
        {
        case 0:
        {
            poker[i] = "Hearts" + s;
            break;
        }
        case 1:
            poker[i] = "Diamonds" + s;
            break;
        case 2:
            poker[i] = "Clubs" + s;
            break;
        case 3:
            poker[i] = "spades" + s;
            break;
        default:
            cout << "程序出错" << endl;
            break;
        }
    }
}

//洗牌
void Poker::ShufflePoker()
{
    //int shuffle_poker[51];
    for (size_t i = 0; i < 52; i++)
    {
        unsigned int    number;
        //int number = 100;
        shuffle_poker[i] = *(poker + rand_s(&number) % 52);
    }
}
//void Poker::DealPoker();				//按4个玩家发牌

//按4个玩家显示
void Poker::DisplayPoker()
{
    for (size_t i = 0; i < 52; i++)
    {
        if (i % 13 == 0)
        {
            cout << endl;
        }
        else
        {
            cout << shuffle_poker[i] << endl;
        }
    }
}