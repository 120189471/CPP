//dx.2016.701  lx_05
//���⣬����һ����ΪDate����
/*
    ������
        a.��Ա����
            �� int���� int����
        b.���캯��
            ��֤�µ�ֵ��1~12�����ڴ˷�Χ������ΪΪ1
            ��֤����ֵ��ָ��ʱ���ڣ��ж�����28��29��30��31�죬��������ϣ�������ʾ
        c.ÿ����������һ��set��get
        d.��Ա����displayDate,�á�/���ָ��£��գ��ꡣ
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