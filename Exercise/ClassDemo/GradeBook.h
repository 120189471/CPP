#include<iostream>
using std::cout;
using std::endl;

#include<string>
using std::string;


class GradeBook{
public:
    //GradeBook构造函数
    //dx.20160628 增加GradeBook构造函数中老师的名字
    GradeBook(string,string);
    void setCourseName(string);
    string getCourseName();
    void displayCourseName();
    void setTeachName(string);
    string getTeachName();
    void displayMessage();

private:
    string courseName;
    string teachName;
};

/*
class GradeBook{
public:
    //构造函数
    GradeBook(string name){
        setCourseName(name);
    }
    //构造方法
    void setCourseName(string name){
        courseName = name;
    }
    string getCourseName(){
        return courseName;
    }
    void displayCourseName(){
        cout << "Welcom to the Grade Book for\n" << getCourseName() << endl;
    }

private:
    string courseName;
};

*/
/*
class GradeBook{

public:
void displayMessage(){
cout << "Welcome to the Grade Book!" << endl;
}
};
*/
/*
class GradeBook{
public:
void displayMessage(string courseName){
cout << "Welcome to the Grade Book!\n" << courseName << endl;
}
};
*/
/*
class GradeBook{
public:
void setCourseName(string name){
courseName = name;
}
string getCourseName(){
return courseName;
}
void displayCourseName(){
cout << "Welcom to the Grade Book for\n" << getCourseName()<<endl;
}

private:
string courseName;
};
*/