//һ���ƶ��ĵ㣬���÷���������߼��̲��� 
/*
    ����
    1.����߽�
        1.1 4����������ʼ���꣬����
    2.����㣬��������ڷ�Χ��
        

    �������
    1.w,s,a,d, ���� ��������Ʒ����ƶ��ķ���
    2.ɾ���ƶ�ǰ�Ŀ�

    ��˵��
    1.һ������
    2.�Ƚ��ȳ�
    3.���ǰ���е㣬ֻ��������
    4.���ǰ���޵磬��һ��һ��

    */

#include <iostream>
using std::cout;
using std::endl;

//��ǰ����
#include <string>
using std::string;

#include <conio.h>

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

void paintPoint(int *pointX, int *pointY){
    block[*pointX][*pointY] = '#';

}
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

    //�ƶ�
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

//ײǽ�ж�
int hitWall(int x,int y){
    if (x == 0 || x == 19 || y == 0 || y == 19)
    {
        cout << "ײǽ��" << endl;
        return 0;
    }
}

int main()
{
    //��ʼ����ʾ 
    paintWall();
    paintPoint(&x, &y);
    paintImage();
    //�ƶ�����ʾ
    while (hitWall(x,y)){
        moving();
        paintPoint(&x, &y);
        system("cls");
        paintImage();
    }
    system("pause");
    return 0;
}