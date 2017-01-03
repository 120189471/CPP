#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "Largest.h"

Largest::GetLargest(){
	for(int counter =0;counter!=10;counter++)
	{
		cout<<"Enter the "<<counter+1<<"number"<<endl;
		cin>>number;
		if (counter=0)
			largest=number;
		if(number>largest)
		{
			largest=number;
		}
		else;
	}
}