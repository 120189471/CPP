#include <istream>
#include "Wage.h"
/*
int Wage::SetSales()
{
	cout<<"请输入当前销售额(输入-1退出): "<<endl;
	cin>>sales;
	return sales;
}
*/

int Wage::CalculatingSalaries()
{
	return base_pay+sales*0.09;
};
void Wage::DisplaySalaries()
{
	do
	(
	cout<<"请输入当前销售额(输入-1退出): "<<endl;
	cin>>sales;
	cout<<"本月薪水是: "<<CalculatingSalaries()<<endl;
	)
	while(sales=-1);
	
}
	