#include<vector>
using std::vector;

#include<iostream>
using std::cout;
using std::endl;

#include<string>
using std::string;

int main_4_5(){
    vector<int> vi{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    auto viBeg = vi.begin();
    while (viBeg != vi.end() && *viBeg >= 0){
        //cout << *viBeg << endl;
        cout << *viBeg++ << endl;
    }

    vector<string> vs{ "a", "b", "c","d","e","f","g" };
    auto vsBeg = vs.begin();
    //判断表达式是否正确，错误的是注释
    *vsBeg++;
    //(*vsBeg)++;
    //*vsBeg.empty();
    vsBeg->begin();
    //++*vsBeg;
    vsBeg++->empty();

    cout << "---------------------------------------" << endl;

    //联系4.21
    vector<int> vi2{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    for (auto &vi1 : vi2){


        cout << ((vi1 % 2) == 1 ? vi1 = vi1 * 2 : vi1) << endl;
    }

    auto vi2Beg = vi2.begin();
    cout << *vi2Beg << endl;

    return 0;
}