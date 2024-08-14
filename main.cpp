#include <iostream>
#include <fstream>
#include <cstdlib>

#include "Course.h" //already indludes user


using namespace std;

bool authenticateUser(string &username, string &password, char &role, string &name, string &email, string &contact)
{
    ifstream userFile("USERS.txt");
    if (userFile.is_open())
    {
        string id;
        string storedPassword;

        while (userFile >> role >> id >> storedPassword >> name >> email >> contact)
        {
            if (id == username)
            {
                if (storedPassword == password)
                {
                    return true;
                }
                // else{cout << "Invalid password." << endl;}
                break;
            }
        }
        // cout << "User not found or incorrect details." << endl;
    }
    // else{cout << "Error opening user file." << endl;}
    return false;
}

User *login() //returns the user object once its fully authenciated
{
    string username; //takin as string rn so easy to compare
    string password;
    while (true) // runs till a succeful login  (add bonus for 3 tries)
    {
        cout << "Enter user ID: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;


        char role;string name, email, contact;
        //sent by reference
        //populated by authencicating function 
        
        if (authenticateUser(username, password, role, name, email, contact) == true) // valid credentials
        {
            //if credentials match, according to role return created object
            cout<<endl<<"Login Succesfull!"<<endl<<endl;
            if (role == 'S')
            {
                return (new Student(role, username, password, name, email, contact));
            }
            else if (role == 'T')
            {
                return (new Teacher(role, username, password, name, email, contact));
            }
            else if (role == 'A')
            {
                return (new Admin(role, username, password, name, email, contact));
            }
            
        }
        cout << "Invalid Username or Password!!! Please try again." << endl;
    }
}




void loadCourse(Course& c) 
{
    string name, description;
    ifstream courseFile("COURSE.txt");
    if (courseFile.is_open()) {
        getline(courseFile, name, ',');
        getline(courseFile, description, '.');
        courseFile.close();
    } else {
        cout << "Error opening course file." << endl;
    }

    c.setName(name);
    c.SetDesc(description); // set description etc

    char role; 
    //read file and check how many studnet 
    //set count to that number so that array is created loaded in the creat array function of that size
    ifstream userFile("USERS.txt");
    int  studentCount=0;
    while (userFile >> role) {
        if (role == 'S') {
            studentCount++;
        }
    }
    c.setCount(studentCount); //assign count
    c.createStudentsArray(studentCount);//students assigned 
    c.loadTeacher();//loads the teacher from file
    c.loadAssignment();

    ifstream notificationFile("NOTIFICATION.txt");
    if (notificationFile.is_open()) {
        string notification;
        getline(notificationFile, notification);
        c.setNotification(notification); // Set the notification from the file
        notificationFile.close();
    } else {
        cout << "Error opening notification file." << endl;
    }
}







int main()
{
    //ADD ENCRYPTION & DECRYPTION USING XOR CYPHER
    // XOR CYPER IS REVERSIBLE

    User *user = login();  //recieve autheticated user (teacher or student or admin)
    system("clear");

    // user->displayProfile();

    Course C; //make course object
    loadCourse(C); //load details from files
    user->GrantAcess(C);
    //grant user access to the course based on their role
///////////////////////////////////////////////////////////////////////////
    // user->displayMenu();
    // cout<<"Displaying Course Teacher Details: "<<endl;
    // user->viewCourseTeacherDetails();

    // user->ViewAssignment();

    // string s = "";
    // cout << "Enter New Notifications: " << endl;
    // cin.ignore(); // Clear the input buffer
    // getline(cin, s); // Use getline to read the full sentence
    // // cin>>s;
    // user->NewNotificaation(s);
    // cout << endl;

    
    // user->getC()->getA().retriveSubmissionFromFile(user->getID());
    
    // user->getC()->getA().getS()->displaySubmission();
    // cout<<endl<<endl<<endl;
while (true) {
        user->displayMenu();
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
                string s;

        switch (choice) {
            case 1:
                system("clear");
                user->displayProfile();
                break;
            case 2:
                system("clear");
                user->ViewAssignment();
                break;
            case 3:
                system("clear");
                cout<<"Enter Notification Text: "<<endl;
                cin>>s;
                user->NewNotificaation(s);
                break;
            case 4:
                system("clear");
                user->viewStudents();
                break;
            case 5:
                system("clear");
                if (user->getRole() == 'T' || user->getRole() == 'A') {
                    ////
                } else {
                    cout << "You are not authorized to create assignments." << endl;
                }
                break;
            case 6:
                system("clear");
                if (user->getRole() == 'A') {
                    ////
                } else {
                    cout << "You are not authorized to add students." << endl;
                }
                break;
            case 7:
                system("clear");
                if (user->getRole() == 'A') {
                    ////
                } else {
                    cout << "You are not authorized to remove students." << endl;
                }
                break;
            case 8:
                system("clear");
                if (user->getRole() == 'T' || user->getRole() == 'A') {
                    /////
                } else {
                    cout << "You are not authorized to perform this action." << endl;
                }
                break;
            case 0:
                /////
                delete user;
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }




    



//////////////////////////////////////////////////////////////////////////
    delete user;
    return 0;
}
