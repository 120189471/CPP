/*
dix.20161210 ������ϰ
1.find

*/
#include "head_file.h"

class Elevator
{
public:
    //initialize
    Elevator()
    {
        status = 0;
        floor = 0;
        run_director = 0;
        elevator_weight = 0;

        for (int i = 0; i != g_floor_numbers; ++i)
        {
            isfloor[i] = 0;
        }
    }

    ~Elevator();

    //����
    int RunElevator(int status,int floor, int run_director)
    {
        if (status == 1)
        {
            if (run_director == 0)
                return floor;
            else if (run_director == 1)
            {
                ++floor;
                return floor;
            }
            else if (run_director == 2)
            {
                --floor;
                return floor;
            }
            else
            {
                return 0;
                printf("���г������⣬��ȴ�ά����Ա���");
            }
        }
        else
        {
            return floor;
        }

    }

    //�������½�ŵ�Ȩֵ
    int CalcElevatorWeight(int require_run_director, int require_floor)
    {
        if (status == 1)
        {
            //���ݲ����������
            //������ݷ���һ��
            if (run_director == 0)
            {
                elevator_weight == abs(require_floor-floor);
            }
            else if (require_run_director == 1 && require_floor - floor>0 || require_run_director == 2 && require_floor - floor<0
                )
            {
                elevator_weight = abs(require_floor - floor);
            }
            else if (require_run_director == 1&&require_run_director != run_director)
            {
                elevator_weight = abs(g_floor_numbers - floor);
            }
            else if (require_run_director == 2 && require_run_director != run_director)
            {
                elevator_weight = floor;
            }
            else
            {
                elevator_weight = g_floor_numbers;
                printf("�����������");
            }
        }
        else
        {
            printf("���������ڷ�����״̬���޷�����Ȩֵ");
            return elevator_weight;
        }
    }

private:
    int status;                     //״̬ 0��������״̬��1 �����У�2������״̬��3.����״̬��
    int floor;                       //����¥�� 
    int run_director;                 //���з���,0 û�����У� 1�������У�2���������С�
    int elevator_weight;              //Ȩֵ���������¼�ߵľ����жϡ�
    int isfloor[g_floor_numbers];                //��Ҫ�ﵽ��¥�㣬0����Ҫ��1������Ҫ
};

class ElevatorControl
{
    ElevatorControl()
    {
        Elevator elevator[g_elevator_numbers];
        

        //
        

    }
    ~ElevatorControl()
    {
    }
    
    //������ �����½�ķ��򣬺�����¥��
    //require_run_director ǰ���ķ���
    //require_floor ���ڵ�¥��
    //reach_floor �����¥��

    int islogin(int require_run_director, int require_floor)
    {
        
        
    }
   
    //��ť����
private:
    //���ݶ���
    int login=

};


int main()
{



    return 0;
};