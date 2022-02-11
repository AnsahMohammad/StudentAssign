#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;


class Teacher {
    public:
        string names[25];
        int nameIndex = 0;
        int sizeOfTeach = 25;

        void dispNames() {
        // Method/function
            for(int i=0;i<sizeOfTeach;i++){
                if(names[i].length() > 0){
                    cout <<" | " <<names[i] <<" | " ;
                }
            }
            cout << endl;
        }
        void addName(){
            string newName;
            cout<<"Enter the name of Person you'd like to add : ";
            cin >> newName;
            names[nameIndex] = newName;
            nameIndex++;
        }
        string * teachArr(){
            string *p;
            p = new string[sizeOfTeach];
            for (int i=0;i<sizeOfTeach;i++){
                p[i] = names[i];
            }

            return p;
        }
        
};

class Student {
    public:
        string names[100];
        int nameIndex = 0;
        int sizeOfStud = 100;

        void dispNames() {
        // Method/function
            for(int i=0;i<sizeOfStud;i++){
                if(names[i].length() > 0){
                    cout <<" | " <<names[i] <<" | " ;
                }
            }
            cout << endl;
        }

        void addName(){
            string newName;
            cout<<"Enter the name of Person you'd like to add : ";
            cin >> newName;
            names[nameIndex] = newName;
            nameIndex++;
        }

        string * StudArr(){
            string *q;
            q = new string[sizeOfStud];
            for (int i=0;i<sizeOfStud;i++){
                q[i] = names[i];
            }

            return q;
        }
        
};


Teacher teach;
Student student;

void assignAlgorithm(){
    string *teachers;
    teachers = teach.teachArr();

    string *students;
    students = student.StudArr();


    int numTeachers = 0;
    int numStudents = 0;

    string Assigned[25][101]; 
    for(int i=0; i<teach.sizeOfTeach; i++){ //i<25 since thats the maximum no of teachers in current version
        if(teachers[i].length() > 0){
            Assigned[i][0] = teachers[i];
            numTeachers++;
        }
    }

    for(int i=0; i<student.sizeOfStud; i++){ //i<100 since thats the maximum no of students in current version
        if(students[i].length() > 0){
            numStudents++;
        }
    }
    
 
   //temporary assign algorithm;
   /*
    for(int j=0;j<numTeachers;j++){
        for (int i=0; i<numStudents;i++){
            Assigned[j][i+1] = students[i]; //i+1 since first column occupied by teachers above we are using upto 10 only inside the for loop
        }
    }
    */

   //random Assign algorithm
    srand(time(0));
    for(int i=0;i<numStudents;i++){
        int randint = ((rand() % numTeachers)); //get a random from 0 - NumberOfTeachers 
        Assigned[randint][i+1] = students[i];
        
    }
    
    //output-ing
    string output = "";
    for (int j=0; j<numTeachers; j++){
        for (int i=0; i< (numStudents+1); i++){ //numstudents+1 becuase one column of matrix is used by teachres index
            if (i == 0){
                output += "\n" + Assigned[j][i] + " :";
            }
            else{
                if (Assigned[j][i].length()>0){
                    output += " " + Assigned[j][i];
                }
            }
        }
        output += "\n";
    }
    cout << output;


}

void addTeacher(){

            int numOfTeachers;
            cout << "How many teachers do you want to add : ";
            cin >> numOfTeachers;
            for (int i=0;i<numOfTeachers;i++)    
                teach.addName();
            cout << "Teachers have been added suffessfully! " << endl;    
        }

void addStudent(){

            int numOfStuds;
            cout << "How many Students do you want to add : ";
            cin >> numOfStuds;
            for (int i=0;i<numOfStuds;i++)    
                student.addName();
            cout << "Students have been added suffessfully! " << endl;    
        }



int main() {
    int page=0;
    cout << "\n\n--------------------------------\n\n" << endl;
    cout << "Welcome" << endl;
    cout << "Type\n 1> to add a teacher \n 2> to show teachers \n 3> to Add Students \n 4> to show Students \n 5> Show Assigned \n : ";
    cin >> page;
    if (page == 1){
        addTeacher();
        main();
    }
    else if (page == 2){
        teach.dispNames();
        main();
    }
    else if(page==3){
        addStudent();
        main();
    }
    else if(page==4){
        student.dispNames();
        main();
    }
    else if(page==5){
        assignAlgorithm();
        main();
    }
    else{
        return 0;
    }

    return 0;
}