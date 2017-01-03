/*变量
	basePay;			基础工资
	sales;				销售额
	bonus;				提成
	方法：
	计算总工资  total=basePay+sales*0.09
		
*/

class Wage
{
	public:
	int SetSales();
	int CalculatingSalaries();
	void DisplaySalaries();
	
	private:
	double base_pay;			基础工资
	double sales;					销售额
	
}