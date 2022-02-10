#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class Teacher {
    public:
        string names[4];
        int nameIndex = 0;

        void dispNames() {
        // Method/function
            for(int i=0;i<4;i++){
                cout <<" | " <<names[i] <<" | " ;
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
            p = new string[4];
            for (int i=0;i<4;i++){
                p[i] = names[i];
            }

            return p;
        }
        
};

class Student {
    public:
        string names[10];
        int nameIndex = 0;

        void dispNames() {
        // Method/function
            for(int i=0;i<10;i++){
                cout <<" | " <<names[i] <<" | " ;
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
            q = new string[10];
            for (int i=0;i<10;i++){
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

    int maxStudent = 3;
    int numTeachers = 4;
    int numStudents = 10;

    string Assigned[4][11]; 
    for(int i=0; i<numTeachers; i++){
        Assigned[i][0] = teachers[i];
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
    for(int i=0;i<10;i++){
        int randint = ((rand() % numTeachers)); //get a random from 0 - NumberOfTeachers 
        Assigned[randint][i+1] = students[i];
        
    }
    
    //output-ing
    string output = "";
    for (int j=0; j<4; j++){
        for (int i=0; i< 11; i++){
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