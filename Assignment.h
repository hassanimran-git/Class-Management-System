#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

#include "Submission.h"

 class Assignment
 {
    private:
         string title;
         string description;
         string deadline;
         string AFile; //assignment file link
         int marks;
         Submission* s; 
    public:
        Assignment():title(""),description(""),AFile(""),marks(0),s(new Submission()){}

        Assignment(string t,string desc,string d,string link,int marks)
            :title(t),description(desc),deadline(d),AFile(link),marks(marks),s(new Submission()){}
        

        string getTitle() { return title; }
        string getDescription() { return description; }
        string getDeadline()  { return deadline; }
        string getAssignmentFile()  { return AFile; }
        int getMarks()  { return marks; }

        Submission* getS(){return s;}

        //to read from file and assign values if any
        void setSubmission(string id, string date, string link, int obtained = 0, string feedback = "", bool status = false) {
            s->setID(id);
            s->setSubmissionDate(date);
            s->setFile(link);
            s->setEvaluationStatus(status);
            s->setFeedback(feedback);
            s->setMarks(obtained);
        }

        void saveSubmission(){s->saveToFile();}
        void retriveSubmissionFromFile(string id){s->loadFromFile(id);}

}; 

