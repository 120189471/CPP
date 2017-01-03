#include<vector>
using std::vector;

#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#include<string>
using std::string;

int main_3_2_2(){
    //vector<int> v1;
    /*
    for (int i = 0; i <= 100; i++){
    v1.push_back(i);
    }
    */
    /*
    int i;
    while(cin>>i){
    v1.push_back(i)
    }
    */


    //下面代码有严重越界问题
    vector<char> vs1;
    string s1("abcdefghijklmnopqistuvwxyz1234567890");
    //cin >> s1;
    //不能用范围for
    //for (auto c : s1){
    //    vs1.push_back();
    //}
    decltype(s1.size()) i = 0;;
    while (i <= s1.size()){
        char c = s1[i];
        vs1.push_back(c);
        i++;
    }
    /*
    for (auto vs1c : vs1){
    cout << vs1c << "\t"<<vs1.size()<<endl;
    }
    */
    for (decltype(vs1.size()) j = 0; j <= vs1.size() - 1; j++){
        cout << j << "\t" << vs1[j] << endl;
    }

    cout << vs1.size() << endl;




    return 0;
}