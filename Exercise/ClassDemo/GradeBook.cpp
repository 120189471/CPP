//dix.20160627  GradeBook.h
//GradeBook��ķ��룬���巽��������


#include<string>
using std::string;

#include<iostream>
using std::cout;
using std::endl;

#include "GradeBook.h"
//GradeBook�ķ���
GradeBook::GradeBook(string name,string tName){
    setCourseName(name);
    setTeachName(tName);

}
void GradeBook::setCourseName(string name){
    //coureName = name;
    // ���Ӷ�Courename���ȵ��ж�
    if (name.length() <= 25){
        courseName = name;
    }
    if (name.length() > 25){
        courseName = name.substr(0, 25);
        cout << "Name \"" << name << "\" exceeds maximum length(25). \n"
            << "Limiting courseName to frist 25 characters.\n" << endl;
    }
}

string GradeBook::getCourseName(){
    return courseName;

}

void GradeBook::displayCourseName(){
    cout << "Welcome to the grade book for\n"
        << getCourseName() << "!" << endl;
}

void GradeBook::setTeachName(string tName){
    teachName = tName;
}
string GradeBook::getTeachName(){
    return teachName;
}

void GradeBook::displayMessage(){
    cout << "This Course is presented by :" << teachName << endl;
}