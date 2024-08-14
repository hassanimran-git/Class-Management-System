#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

 class Submission
 {
    private:
        string StudentID;
        string submissionDate;
        string file; //link to the file 
        bool evaluationStatus;//marked or not
        string feedback;
        int obtainedMarks;

    public:
        Submission(){}
        Submission(string date,string file):submissionDate(date),file(file),evaluationStatus(false),feedback(""),obtainedMarks(0),StudentID(""){}
       
       void setSubmissionDate(string date) {submissionDate = date;}
       void setFile(string fileLink){file = fileLink;}
       void setEvaluationStatus(bool status) {evaluationStatus = status;}
       void setFeedback(std::string feedbackText) {feedback = feedbackText;}
       void setMarks(int m){obtainedMarks=m;}
       void setID(string s){StudentID=s;}
       
       string getSubmissionDate(){return submissionDate;}
       string getFile(){return file;}
       bool getEvaluationStatus(){return evaluationStatus;}
       string getFeedback(){return feedback;}
       int getMarks(){return obtainedMarks;}
       string getStudentID(){return StudentID;}


void saveToFile()
{
    ofstream submissionFile("SUBMISSION.txt", ios::app); // Open in append mode

    if (submissionFile.is_open())
    {
        submissionFile << StudentID << " " << submissionDate << " " << file << " "
                       << obtainedMarks << " " << evaluationStatus << " " << feedback << endl;

        submissionFile.close();
    }
    else
    {
        cout << "Error opening submission file." << endl;
    }
}


//loads target id submisiion into the object
void loadFromFile(string targetStudentID)
{
    // cout<<"Recieved ID: "<<targetStudentID<<endl;

    ifstream submissionFile("SUBMISSION.txt");
    if (submissionFile.is_open())
    {
        while (submissionFile >> StudentID >> submissionDate >> file >> obtainedMarks >> evaluationStatus)
        {
            getline(submissionFile, feedback); // Read the rest of the line as feedback

            if (StudentID == targetStudentID)
            {
                // cout << "Student ID: " << getStudentID() << endl;
                // cout << "Submission Date: " << getSubmissionDate() << endl;
                // cout << "File Link: " << getFile() << endl;
                // cout << "Obtained Marks: " << getMarks() << endl;
                // cout << "Evaluation Status: " << (evaluationStatus ? "Marked" : "Not Marked") << endl;
                // cout << "Feedback: " << feedback << endl;
                return; // Found the target student's submission, stop loading
            }
        }
    }
    else
    {
        cout << "Error opening submission file." << endl;
    }
}


void displaySubmission()
{
    if(StudentID!=""){
        cout << "Student ID: " << getStudentID() << endl;
        cout << "Submission Date: " << getSubmissionDate() << endl;
        cout << "File Link: " << getFile() << endl;
        cout << "Obtained Marks: " << getMarks() << endl;
        cout << "Evaluation Status: " << (evaluationStatus ? "Marked" : "Not Marked") << endl;
        cout << "Feedback: " << feedback << endl;
    }
    else{cout<<"No Submission has been Made!"<<endl;}
}


 };

