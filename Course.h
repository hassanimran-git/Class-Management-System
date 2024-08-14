#include <iostream>
using namespace std;

#pragma once

#include "User.h"
#include "Assignment.h"

class Course 
{
private:
    string name; //name or subject
    string description;
    Teacher* teacher;
    Student* list; //enrolled students
    string Notification;
    int studentCount=0;
    Assignment a ;

    //assingments + submissions
public:
    Course():name(""),teacher(nullptr),description(""),Notification("No New Notification"){}

    Course(string name,Teacher* teacher,string description,Student* list)
        :name(name),teacher(teacher),description(description),list(list){} 

    void setName(string n){name=n;}
    string GetName(){return name;}
    void SetDesc(string s){description=s;}
    string GetDesc(){return description;}

    Assignment getA(){return a;};

    
    void SetStudents(Student* l){list=l;}

    int getCount(){return studentCount;}
    void setCount(int c){studentCount=c;}

    string getNotification(){return Notification;}

    void setNotification(string s){
        Notification=s;
        ofstream notificationFile("NOTIFICATION.txt");
        if (notificationFile.is_open()) {
            notificationFile << Notification << endl;
            notificationFile.close();

        } else {
            cout << "Error opening notification file for writing." << endl;
        }
        
    }
    

void createStudentsArray(int studentCount) {
    ifstream userFile("USERS.txt");
    if (userFile.is_open()) {
        string id;
        string password, name, email, contact;
        char role;

        Student* studentsArray = new Student[studentCount]; // Create an array of students

        int i = 0;
        while (i < studentCount && userFile >> role >> id >> password >> name >> email >> contact) {
            if (role == 'S') {
                studentsArray[i] = Student(role, id, password, name, email, contact);
                ++i;
            }
        }

        // Set the array of students for the course
        SetStudents(studentsArray);

        userFile.close();
    } else {
        cout << "Error opening user file." << endl;
    }
}

void displayStudentList()
{
    for (int i = 0; i < studentCount; i++){
        list[i].displayProfile();
        cout<<endl;
    }
}

void loadTeacher() {
    ifstream userFile("USERS.txt");
    if (userFile.is_open()) {
        string id;
        string password, name, email, contact;
        char role;

        while (userFile >> role >> id >> password >> name >> email >> contact) {
            if (role == 'T') {
                teacher =  new Teacher(role, id, password, name, email, contact);
            }
        }
        userFile.close();
    } else {
        cout << "Error opening user file." << endl;
    }
}

void viewTeacherDetails(){teacher->displayProfile();}

void ViewCourseDetails()
{
    cout<<"Name: "<<name<<endl;
    cout<<"Description: "<<description<<endl;
    cout<<"Instructor: "<<teacher->getName()<<endl;
} 



void loadAssignment()
{
    ifstream assignmentFile("ASSIGNMENT.txt");
    if (assignmentFile.is_open())
    {
        string title, description, deadline, AFile;
        int marks;

        if (getline(assignmentFile, title, ',') && getline(assignmentFile, description, ',') &&
            getline(assignmentFile, deadline, ',') && getline(assignmentFile, AFile, ',') &&
            (assignmentFile >> marks))
        {
            assignmentFile.ignore(); // Ignore the newline character

            a = Assignment(title, description, deadline, AFile, marks);

        }
        else
        {
            cout << "Error reading assignment details from file." << endl;
        }

        assignmentFile.close();

    }
    else
    {
        cout << "Error opening assignment file." << endl;
    }
}


void displayAssignments()
{
    if(a.getTitle()!=""){

        cout << "Title: " << a.getTitle() << endl;
        cout << "Description: " << a.getDescription() << endl;
        cout << "Deadline: " << a.getDeadline() << endl;
        cout << "Assignment File Link: " << a.getAssignmentFile() << endl;
        cout << "Marks: " << a.getMarks() << endl;
    }
    else {cout << "No assignments have been added to this course." << endl;}
}



void saveSubmission(){a.getS()->saveToFile();}
void retriveSubmissionFromFile(string id){a.getS()->loadFromFile(id);}




};