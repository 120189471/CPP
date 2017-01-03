#include<string>
using std::string;

int main_4_6(){
    string s1 = "a string";
    string *p = &s1;
    auto n = s1.size();
    n = (*p).size();
    n = p->size();              //µÈ¼ÛÓÚ(*p).size()

    return 0;
}