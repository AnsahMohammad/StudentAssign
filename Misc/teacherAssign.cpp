#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

class Teacher {
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
        string * teachArr(){
            string *p;
            p = new string[10];
            for (int i=0;i<10;i++){
                p[i] = names[i];
            }

            return p;
        }
        
        
};


Teacher teach;

void assignAlgorithm(){
    string *teachers;
    teachers = teach.teachArr();
    
    string students[10] = {"Ansa","bab","jack","jacob","rajw","dam","tripod","ans","er","daniel"};

    int maxStudent = 2;
    int numTeachers = 4;

    string Assigned[maxStudent][10];
    for(int i=0;i<10;i++){
        Assigned[0][i] = teachers[i];
    }
    
    //taking random integer

    srand(time(0));
    int count = 0;
    for (int i=0;count==10;i++){
        int randint = ((rand() % numTeachers));//getting a random index of teacher
        for (int j=0;j<maxStudent;j++){
            if (Assigned[j][randint] == string(0)){
                Assigned[j][randint] = students[j];
                cout << students[j];
                count++;
                break;
            }
        }
    }
    for(int i;i<10;i++){
        for(int j=0;j<2;j++){
            cout <<Assigned[j][i];
        }
    }


}

void addTeacher(){

            int numOfTeachers;
            cout << "How many teachers do you want to add : ";
            cin >> numOfTeachers;
            for (int i=0;i<numOfTeachers;i++)    
                teach.addName();
            cout << "Teachers have been added suffessfully! " << endl;    
        }


int main() {
    int page=0;
    cout << "\n\n--------------------------------\n\n" << endl;
    cout << "Welcome" << endl;
    cout << "Type\n 1> to add a teacher\n 2> to show teachers \n : ";
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
        assignAlgorithm();
    }
    else{
        return 0;
    }

    return 0;
}