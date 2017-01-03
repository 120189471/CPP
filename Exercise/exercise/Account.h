//dix.20160630 l03
//问题 表示客户的银行账号
/*分析 ：
//  a:int数据成员,表示账户余额
    
//  b.构造函数，接受初始余额，并用他初始化账户余额，
        数据有效性，>=0,否则设置为0；
        提示数据无效。
    c.成员函数 credit 将一笔金额添加到当前余额中
    b.成员函数debit从账户中取钱，保证金额不超过月，如果不是这样，余额不变并打印“Debit amount exceeded account balance.”
    c.成员函数getBalance返回这个余额
    d.编写测试程序，创建2个Account对象，并测试Account类的成员函数
*/


class Account{
public:
    Account();
    Account(int);       //构造函数

    int credit(int);    //添加金额
    void debit(int);     //取钱
    int getBalance();   //返回当前余额数
private:
    int balance;        //定义余额

};

