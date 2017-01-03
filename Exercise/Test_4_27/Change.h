/*进制转换

	输入一个二进制 十进制转换
	1. 2->10
		1.1 计算长度
		1.2 循环，当前位value*2的位次幂
		1.3 输出结果
	2. 10-〉2
		2.1 计算长度
		2.2 循环，while 当余数不为0 
					余数*10 i次幂
					除数=除数/2
					输出余数。
	
		
	
	
*/
class Conversion
{
public:
	void SetNumber(int);
	int GetNumber();
	int Chiose();
	int  DecimalConversion();

private:
	int number=0;
};

