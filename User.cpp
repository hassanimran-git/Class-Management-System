#include "User.h"
#include "Course.h" // Include Course header here

User::User(char role, string id,  string password,  string name,  string email,  string contact)
    : id(id), password(password), name(name), email(email), role(role), contact(contact) {}

char User::getRole() {
    return role;
}

void User::displayProfile() {
     cout << "___________Profile____________" <<  endl;
     cout << "Role: " << role << "\nId :" << id << "\nName: " << name << "\nEmail: " << email << "\nContact: " << contact <<  endl;
     cout << "______________________________" <<  endl <<  endl <<  endl;
}

bool User::authenticate(string& providedPassword) {
    return password == providedPassword;
}

void User::GrantAcess(Course& x) {c = &x;}

void User::nameCourse() {
    if (c) {
         cout <<c->GetName() <<  endl;
    } else {
         cout << "No course assigned" <<  endl;
    }
}

void User::setAll(char r,int i,string pas,string n,string e,string c)
    {role=r;id=i;password=pas;name=n;email=e;contact=c;}


void Admin::viewStudents(){c->displayStudentList();}
void Teacher::viewStudents(){c->displayStudentList();}
void Student::viewStudents(){cout<<"You are not Authroized to View Student Profiles!"<<endl;}

void User::viewCourseTeacherDetails(){c->viewTeacherDetails();}

void Admin::NewNotificaation(string s){c->setNotification(s);}
void Teacher::NewNotificaation(string s){c->setNotification(s);}
void Student::NewNotificaation(string s){cout<<"You are Not Authorized to create a nofication!";}

void User::seeNotification(){cout<<c->getNotification();}

string Teacher::getName(){return name;}

void User::ViewCourseDetails(){c->ViewCourseDetails();}

void User::ViewAssignment(){c->displayAssignments();}

// void Student::displayMenu()
// {
//     cout<<"1.view profile"<<endl;
//     cout<<"2.view assignment"<<endl;
//     cout<<"3.view notications"<<endl;
//     cout<<"4.view course details"<<endl;
//     cout<<"5.view course teacher details"<<endl;
// }

// void Teacher::displayMenu()
// {
//     cout<<"1.view profile"<<endl;
//     cout<<"2.view assignment"<<endl;
//     cout<<"3.Send Notification"<<endl;
//     cout<<"4.view student list"<<endl;
//     cout<<"5.create assignment"<<endl;
// }

// void Admin::displayMenu()
// {
//     cout<<"1.view profile"<<endl;
//     cout<<"2.view assignment"<<endl;
//     cout<<"3.Send Notification"<<endl;
//     cout<<"4.view student list"<<endl;
//     cout<<"5.add student"<<endl;
//     cout<<"6.remove students"<<endl;
// }

