//一个移动的点，可用方向键，或者键盘操作 
/*
    界面
    1.创造边界
        1.1 4个参数，开始坐标，长宽
    2.创造点，随机出现在分内

    方向控制
    1.w,s,a,d, 或者 方向键控制方块移动的方向
    2.删除移动前的块

	蛇的定义
	1.队列
	2.每个队列元素包括一个2个数字，蛇一节中的的x，y（）
	3.当蛇前有食物，那么我们入队，无出对
	4.当蛇前没有食物，入队，并出对
	
	蛇二次定义
	1.队列
	2.动作，moving
		2.1 当蛇前有食物，那么我们入队，无出对
		2.2 当蛇前没有食物，赋值“ * ”入队，并出队尾
	3.返回最新的状态。
	
    */

#include <iostream>
using std::cout;
using std::endl;

//当前画面
#include <string>
using std::string;

#include <conio.h>

#include <queue>
using std::queue;

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
/*
void paintPoint(int *pointX, int *pointY){
    block[*pointX][*pointY] = '#';

}
*/

///////////////////////////////////////////////////////////////////////
//绘制蛇
/*
	蛇的定义
	1.队列
	2.每个队列元素包括一个2个数字，蛇一节中的的x，y
	3.当蛇前有食物，那么我们入队，无出队
	4.当蛇前没有食物，入队，并出队
*/

void paintSnake(char* s)
{
	//&s这个指蛇前一位
	queue<char*> snake;
	
    if (*s == '*')
	{
	//如果前路有food，那么吃掉
        snake.push(s);
	}
	//否则，向前移动移动
	else
	{
        *s = '*';
            snake.push(s);
            snake.front()==NULL;
            snake.pop();
	}
}

///////////////////////////////////////////////////////////////////////

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
    //char* snakeFood = &block[x][y];
    //*snakeFood = block[x][y];
    

    //移动
    switch (_getch())
    {
    case 'w':
        --x;
        paintSnake(&block[x][y]);
        break;
    case 's':
        ++x;
        paintSnake(&block[x][y]);
        break;
    case 'a':
        --y;
        paintSnake(&block[x][y]);
        break;
    case 'd':
        ++y;
        paintSnake(&block[x][y]);
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
    else
        return 1;
    
}

int main()
{
    //初始化显示 
    paintWall();
    //paintPoint(&x, &y);
    paintImage();
    //移动并显示
    while (hitWall(x,y)){
        moving();
        //paintPoint(&x, &y);
        system("cls");
        paintImage();
    }
    system("pause");
    return 0;
}