/*
dix.20161210 电梯练习
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

    //运行
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
                printf("运行出现问题，请等待维护人员检查");
            }
        }
        else
        {
            return floor;
        }

    }

    //计算与登陆着的权值
    int CalcElevatorWeight(int require_run_director, int require_floor)
    {
        if (status == 1)
        {
            //电梯不运行情况下
            //如果电梯方向一致
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
                printf("计算出问题了");
            }
        }
        else
        {
            printf("电梯正处在非运行状态，无法计算权值");
            return elevator_weight;
        }
    }

private:
    int status;                     //状态 0：不服务状态，1 ：运行，2：开门状态，3.关门状态。
    int floor;                       //所在楼层 
    int run_director;                 //运行方向,0 没有运行， 1向上运行，2，向下运行。
    int elevator_weight;              //权值，根据与登录者的距离判断。
    int isfloor[g_floor_numbers];                //需要达到的楼层，0，需要，1，不需要
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
    
    //门外点击 点击登陆的方向，和所在楼层
    //require_run_director 前进的方向
    //require_floor 所在的楼层
    //reach_floor 到达的楼层

    int islogin(int require_run_director, int require_floor)
    {
        
        
    }
   
    //按钮队列
private:
    //电梯队列
    int login=

};


int main()
{



    return 0;
};