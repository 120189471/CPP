//dx.2016.701  lx_05
//问题，创建一个名为Date的类
/*
    分析：
        a.成员数据
            月 int，日 int，年
        b.构造函数
            保证月的值在1~12，不在此范围，设置为为1
            保证余额的值在指定时间内，判断其在28，29，30，31天，如果不符合，给出提示
        c.每个函数增加一个set和get
        d.成员函数displayDate,用”/“分隔月，日，年。
*/

struct Date{

public:
    Date(int,int,int);
    void setMonth(int);
    void setDay(int);
    void setYear(int);
    int getMonth();
    int getDay();
    int getYear();
    void displayDate();
    int leapMonth();

private:
    int month=1;
    int day=1;
    int year=0;
};