//dix test03_01
//¡∑œ∞¿‡

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include<string>
using std::string;
using std::getline;

#include"GradeBook.h"
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


void main(){
    string nameOfCourse;
    GradeBook myGradeBook1("CS101 Introduction to C++ Programing", "teache_name_01");
    GradeBook myGradeBook2("CS102 C++ Data Structures", "teache_name_02");
    //GradeBook myGradeBook();
    // ‰≥ˆ
    //cout << "Initial course name is: " << myGradeBook1.getCourseName() << endl;
    cout << "gradeBook1 created for course: " << myGradeBook1.getCourseName() << endl;
    myGradeBook1.displayMessage();
    cout << "\ngradeBook2 created for course: " << myGradeBook2.getCourseName() << endl;
    myGradeBook2.displayMessage();


    /*
    // ‰»Î nameOfCourse£ª
    cout << "Plase enter the course name: " << endl;
    getline(cin, nameOfCourse);

    myGradeBook.setCourseName(nameOfCourse);
    cout << endl;

    myGradeBook.displayCourseName();
    */
}