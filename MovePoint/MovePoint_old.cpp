//一个移动的点，可用方向键，或者键盘操作 
/*
    界面
    1.创造边界
        1.1 4个参数，开始坐标，长宽
    2.创造点，随机出现在范围内
        

    方向控制
    1.w,s,a,d, 或者 方向键控制方块移动的方向
    2.删除移动前的块

    蛇说明
    1.一个队列
    2.先进先出
    3.如果前面有点，只进不出。
    4.如果前面无电，进一出一。

    */

#include <iostream>
using std::cout;
using std::endl;

//当前画面
#include <string>
using std::string;

#include <conio.h>

static char block[20][20] ;
static int x = 10;
static int y = 10;

//初始化位置


//绘制围墙 
void paintWall(){

    for (size_t i = 0; i < 20; i++)
    {
        for (size_t j = 0; j < 20; j++)
        {
            if (i == 0 || i == 19 || j == 0 || j == 19)
            {
                block[i][j] = '*';
            }
        }
    }
}

//绘制操纵点 

void paintPoint(int *pointX, int *pointY){
    block[*pointX][*pointY] = '#';

}
//输出图片
void paintImage()
{
    for (size_t i = 0; i < 20; i++)
    {
        for (size_t j = 0; j < 20; j++)
        {
            cout << block[i][j];
        }
        cout << endl;
    }
}

void moving()
{

    int *pointX = &x;
    int *pointY = &y;

    //移动
    switch (_getch())
    {
    case 'w':
        x--;
        break;
    case 's':
        x++;
        break;
    case 'a':
        y--;
        break;
    case 'd':
        y++;
        break;
    default:
        ;
    }
}

//撞墙判断
int hitWall(int x,int y){
    if (x == 0 || x == 19 || y == 0 || y == 19)
    {
        cout << "撞墙了" << endl;
        return 0;
    }
}

int main()
{
    //初始化显示 
    paintWall();
    paintPoint(&x, &y);
    paintImage();
    //移动并显示
    while (hitWall(x,y)){
        moving();
        paintPoint(&x, &y);
        system("cls");
        paintImage();
    }
    system("pause");
    return 0;
}