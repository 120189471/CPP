//һ���ƶ��ĵ㣬���÷���������߼��̲��� 
/*
    ����
    1.����߽�
        1.1 4����������ʼ���꣬����
    2.����㣬��������ڷ���

    �������
    1.w,s,a,d, ���� ��������Ʒ����ƶ��ķ���
    2.ɾ���ƶ�ǰ�Ŀ�

	�ߵĶ���
	1.����
	2.ÿ������Ԫ�ذ���һ��2�����֣���һ���еĵ�x��y����
	3.����ǰ��ʳ���ô������ӣ��޳���
	4.����ǰû��ʳ���ӣ�������
	
	�߶��ζ���
	1.����
	2.������moving
		2.1 ����ǰ��ʳ���ô������ӣ��޳���
		2.2 ����ǰû��ʳ���ֵ�� * ����ӣ�������β
	3.�������µ�״̬��
	
    */

#include <iostream>
using std::cout;
using std::endl;

//��ǰ����
#include <string>
using std::string;

#include <conio.h>

#include <queue>
using std::queue;

static char block[20][20] ;
static int x = 10;
static int y = 10;



//��ʼ��λ��


//����Χǽ 
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

//���Ʋ��ݵ� 
/*
void paintPoint(int *pointX, int *pointY){
    block[*pointX][*pointY] = '#';

}
*/

///////////////////////////////////////////////////////////////////////
//������
/*
	�ߵĶ���
	1.����
	2.ÿ������Ԫ�ذ���һ��2�����֣���һ���еĵ�x��y
	3.����ǰ��ʳ���ô������ӣ��޳���
	4.����ǰû��ʳ���ӣ�������
*/

void paintSnake(char* s)
{
	//&s���ָ��ǰһλ
	queue<char*> snake;
	
    if (*s == '*')
	{
	//���ǰ·��food����ô�Ե�
        snake.push(s);
	}
	//������ǰ�ƶ��ƶ�
	else
	{
        *s = '*';
            snake.push(s);
            snake.front()==NULL;
            snake.pop();
	}
}

///////////////////////////////////////////////////////////////////////

//���ͼƬ
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
    

    //�ƶ�
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

//ײǽ�ж�
int hitWall(int x,int y){
    if (x == 0 || x == 19 || y == 0 || y == 19)
    {
        cout << "ײǽ��" << endl;
        return 0;
    }
    else
        return 1;
    
}

int main()
{
    //��ʼ����ʾ 
    paintWall();
    //paintPoint(&x, &y);
    paintImage();
    //�ƶ�����ʾ
    while (hitWall(x,y)){
        moving();
        //paintPoint(&x, &y);
        system("cls");
        paintImage();
    }
    system("pause");
    return 0;
}