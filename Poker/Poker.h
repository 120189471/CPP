#include <string>
using std::string;
/*
poker
poker[51]

ϴ��
vector[52]
while(poker[random *52]!=vector[52])
{
vector.push_back;
}
����
for(i!52)
{
vector()
switch(i%4)
case:0
p1vector().push_back(vector[i])
}

��ʾ
����p1vector[]

for(i!=p1vector.size)
display_p1_vector[i]

����
��ָ����С��������

�����ж�
&vector[]+13/+26/+39 ����
count ++
if count==3
3count++;
if count==4
4count++;
*/

class Poker
{
public:
    Poker();								//��ʼ����

    void ShufflePoker();			//ϴ��
    void DealPoker();				//��4����ҷ���
    void DisplayPoker();			//��4�������ʾ

private:
    string poker[51];
    string shuffle_poker[51];
    int P1_poker[13];
    int P2_poker[13];
    int P3_poker[13];
    int P4_poker[13];
};