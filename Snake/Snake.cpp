//#include <iostream.h>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>  //ʹ�õ�ǰʱ��������;



enum dir { up, down, left, right };  //ö������enum dir;
//Χǽ;
class Fence {
public:
    void InitFence();
    void OutputF();
public:
    char game[20][20];
}f; //�������;
//�����;
void Fence::InitFence() {
    for (int i = 0; i<20; i++)
        for (int j = 0; j<20; j++) {
        if (i == 0 || i == 19 || j == 0 || j == 19)
            game[i][j] = '*';
        else game[i][j] = ' ';
        }
}
//��ʾ���;
void Fence::OutputF() {
    for (int i = 0; i<20; i++) {
        for (int j = 0; j<20; j++)
            cout << game[i][j] << ' ';
        cout << endl;
    }
}
//�߽��;
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
//����ͷ���;
void SnakeNode::add_head(int x, int y) {
    SnakeNode *q = new SnakeNode;
    q->x = x; q->y = y;
    q->next = head;
    q->prior = NULL;
    if (head) head->prior = q;
    head = q;
    if (!tail) tail = head;
    f.game[x][y] = '*';  //f��������ڶ���Fence��ʱ����; ��Fence����SnakeNode��ǰ����;
}
int SnakeNode::get_x() {
    return x;
}
int SnakeNode::get_y() {
    return y;
}
//ɾ��β���;
void SnakeNode::delete_tail() {
    SnakeNode *p = tail;
    f.game[tail->get_x()][tail->get_y()] = ' ';//��β���������ʾ��'*'��Ϊ�ո�;
    if (tail == head)
        tail = head = NULL;
    else {
        tail = tail->prior;
        tail->next = NULL;
    }
    delete p;
}
//move�ƶ�;
class move {
public:
    dir point;    //ö�ٱ���point: ���Ʒ���;
    int food_x;
    int food_y;
public:
    void moving();
    void change_point(char);  //�ı䷽��;
    void get_food();
};
void move::moving() {
    int a, b;
    a = head->get_x();  //ȡ��ͷ��������
    b = head->get_y();  //ͷ���������
    switch (point) {
    case up: --a; break;
    case down: ++a; break;
    case left: --b; break;
    case right: ++b; break;
    }
    if (a == 19 || b == 19 || a == 0 || b == 0) {    //�ж��Ƿ�ײǽ;      
        cout << "GAME OVER!!!" << endl;
        system("pause");
        exit(0);
    }
    if (a == food_x && b == food_y) {     //��food;
        head->add_head(a, b);
        get_food();
    }
    else {
        head->add_head(a, b); //����ͷ���;
        head->delete_tail(); //ɾ��β���;
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
    srand((unsigned int)time(NULL)); //������(��������ʱ��); 
    food_x = rand() % 18 + 1;
    food_y = rand() % 18 + 1;
    f.game[food_x][food_y] = '*';
}

//main();

int main() {
    cout << "^_^ ��ʹ��\" w,s,a,d \"���Ʒ��� ^_^\n\n\n";
    //������С��;
    move m;
    f.InitFence();
    head->add_head(4, 3);
    head->add_head(4, 4);
    head->add_head(4, 5);
    m.get_food();
    f.OutputF();
    while (true) {
        char keydown = _getch(); //getch()���ؼ����϶�ȡ���ַ�;����ͷ�ļ�<conio.h>
        m.change_point(keydown);
        while (!_kbhit()) { //�ж���û�а�������;
            system("cls");  //��������;
            m.moving();
            f.OutputF();
            Sleep(200);
        }
    }
    return 0;
}