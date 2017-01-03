//#include <iostream.h>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>  //使用当前时间做种子;



enum dir { up, down, left, right };  //枚举类型enum dir;
//围墙;
class Fence {
public:
    void InitFence();
    void OutputF();
public:
    char game[20][20];
}f; //定义对象;
//画框框;
void Fence::InitFence() {
    for (int i = 0; i<20; i++)
        for (int j = 0; j<20; j++) {
        if (i == 0 || i == 19 || j == 0 || j == 19)
            game[i][j] = '*';
        else game[i][j] = ' ';
        }
}
//显示框框;
void Fence::OutputF() {
    for (int i = 0; i<20; i++) {
        for (int j = 0; j<20; j++)
            cout << game[i][j] << ' ';
        cout << endl;
    }
}
//蛇结点;
class SnakeNode {
private:
    int x, y;
    SnakeNode *prior, *next;
public:
    void add_head(int x, int y);
    int get_x();
    int get_y();
    void delete_tail();
}*head = NULL, *tail = NULL;
//插入头结点;
void SnakeNode::add_head(int x, int y) {
    SnakeNode *q = new SnakeNode;
    q->x = x; q->y = y;
    q->next = head;
    q->prior = NULL;
    if (head) head->prior = q;
    head = q;
    if (!tail) tail = head;
    f.game[x][y] = '*';  //f对象可以在定义Fence类时定义; 且Fence类在SnakeNode类前定义;
}
int SnakeNode::get_x() {
    return x;
}
int SnakeNode::get_y() {
    return y;
}
//删除尾结点;
void SnakeNode::delete_tail() {
    SnakeNode *p = tail;
    f.game[tail->get_x()][tail->get_y()] = ' ';//把尾结点的坐标表示的'*'置为空格;
    if (tail == head)
        tail = head = NULL;
    else {
        tail = tail->prior;
        tail->next = NULL;
    }
    delete p;
}
//move移动;
class move {
public:
    dir point;    //枚举变量point: 控制方向;
    int food_x;
    int food_y;
public:
    void moving();
    void change_point(char);  //改变方向;
    void get_food();
};
void move::moving() {
    int a, b;
    a = head->get_x();  //取得头结点横坐标
    b = head->get_y();  //头结点纵坐标
    switch (point) {
    case up: --a; break;
    case down: ++a; break;
    case left: --b; break;
    case right: ++b; break;
    }
    if (a == 19 || b == 19 || a == 0 || b == 0) {    //判断是否撞墙;      
        cout << "GAME OVER!!!" << endl;
        system("pause");
        exit(0);
    }
    if (a == food_x && b == food_y) {     //吃food;
        head->add_head(a, b);
        get_food();
    }
    else {
        head->add_head(a, b); //插入头结点;
        head->delete_tail(); //删除尾结点;
    }
}
void move::change_point(char keydown) {
    switch (keydown) {
    case 'w': point = up; break;
    case 's': point = down; break;
    case 'a': point = left; break;
    case 'd': point = right; break;
    }
}
void move::get_food() {
    srand((unsigned int)time(NULL)); //做种子(程序运行时间); 
    food_x = rand() % 18 + 1;
    food_y = rand() % 18 + 1;
    f.game[food_x][food_y] = '*';
}

//main();

int main() {
    cout << "^_^ 请使用\" w,s,a,d \"控制方向 ^_^\n\n\n";
    //画框框和小蛇;
    move m;
    f.InitFence();
    head->add_head(4, 3);
    head->add_head(4, 4);
    head->add_head(4, 5);
    m.get_food();
    f.OutputF();
    while (true) {
        char keydown = _getch(); //getch()返回键盘上读取的字符;包含头文件<conio.h>
        m.change_point(keydown);
        while (!_kbhit()) { //判断有没有按键落下;
            system("cls");  //清屏函数;
            m.moving();
            f.OutputF();
            Sleep(200);
        }
    }
    return 0;
}