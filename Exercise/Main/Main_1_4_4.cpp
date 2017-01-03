#include<iostream>
using std::cin;
using std::cout;
using std::endl;

int main_1_4_4(){
    int currVal = 0;
    int val = 0;
    if (cin >> currVal){
        int cnt = 1;
        while (cin >> val){
            //==ÏàµÈÔËËã·û
            if (val==currVal)
                ++cnt;
            else{
                cout << currVal << " occurs " << cnt << " time " << endl;
                currVal = val;
                cnt = 1;
            }
        }
        cout << currVal << " occurs " << cnt << " times " << endl;
            
    }

    return 0;
}