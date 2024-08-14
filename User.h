#pragma once

#include <iostream>
using namespace std;

class Course; // Forward declaration of Course

class User
{
protected:
    string id;
    string password;
    string name;
    string email;
    char role;
    string contact;
    Course* c = nullptr;
    string Notification;
    
public:
    User(){}
    User(char role, string id, string password, string name, string email, string contact);
    char getRole();
    void displayProfile();
    bool authenticate(string& providedPassword);
    virtual void TellRole() = 0;
    void GrantAcess(Course& x); //setter for cource pointer 
    //assigns the referce to the course to the pointer to access the course thru
    void nameCourse();
    void setAll(char r,int i,string pas,string n,string e,string c);
    virtual void viewStudents() = 0;
    void viewCourseTeacherDetails();
    virtual void NewNotificaation(string s) = 0;
    void seeNotification();
    void ViewCourseDetails();
    void ViewAssignment();
    Course* getC(){return c;}
    string getID(){return id;}
    // virtual void displayMenu() = 0;
    void displayMenu() {
    cout << "============== Menu ==============" << endl;
    cout << "1. View Profile" << endl;
    cout << "2. View Assignments" << endl;
    cout << "3. Send Notification" << endl;
    cout << "4. View Student List" << endl;
    cout << "5. View Course Details" << endl;
    cout << "6. View Course Teacher Details" << endl;
    cout << "0. Exit" << endl;
    cout << "===================================" << endl;
}

    
};

class Student : public User
{
public:
    Student(){}
    Student(char role,string id,string password,string name,string email,string contact)
        :User(role,id,password,name,email,contact){}
    void TellRole(){cout<<"I am a Student!"<<endl;}
     void viewStudents();
    void NewNotificaation(string s);
    // void displayMenu();


};

class Teacher : public User
{
public:
    Teacher(){}
    Teacher(char role,string id,string password,string name,string email,string contact)
        :User(role,id,password,name,email,contact){}
    void TellRole(){cout<<"I am a Teacher!"<<endl;}
    void viewStudents();
    void NewNotificaation(string s);
    string getName();
    // void displayMenu();
};

class Admin : public User
{
public:
    Admin(){}
    Admin(char role,string id,string password,string name,string email,string contact)
        :User(role,id,password,name,email,contact){}
    void TellRole(){cout<<"I am an Admin!"<<endl;}
    void viewStudents();
    void NewNotificaation(string s);
    // void displayMenu();
};