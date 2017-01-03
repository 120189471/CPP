#include <string>
using std::string;
/*
poker
poker[51]

洗牌
vector[52]
while(poker[random *52]!=vector[52])
{
vector.push_back;
}
发牌
for(i!52)
{
vector()
switch(i%4)
case:0
p1vector().push_back(vector[i])
}

显示
排序p1vector[]

for(i!=p1vector.size)
display_p1_vector[i]

排序
按指数从小到大排序

特殊判断
&vector[]+13/+26/+39 存在
count ++
if count==3
3count++;
if count==4
4count++;
*/

class Poker
{
public:
    Poker();								//初始化牌

    void ShufflePoker();			//洗牌
    void DealPoker();				//按4个玩家发牌
    void DisplayPoker();			//按4个玩家显示

private:
    string poker[51];
    string shuffle_poker[51];
    int P1_poker[13];
    int P2_poker[13];
    int P3_poker[13];
    int P4_poker[13];
};