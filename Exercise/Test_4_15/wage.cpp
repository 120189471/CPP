#include <istream>
#include "Wage.h"
/*
int Wage::SetSales()
{
	cout<<"�����뵱ǰ���۶�(����-1�˳�): "<<endl;
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
	cout<<"�����뵱ǰ���۶�(����-1�˳�): "<<endl;
	cin>>sales;
	cout<<"����нˮ��: "<<CalculatingSalaries()<<endl;
	)
	while(sales=-1);
	
}
	