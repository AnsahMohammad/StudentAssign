#include <iostream>
#include <time.h>

using namespace std;

void assignAlgorithm(){
    //string teachers[4] = {"Pep","Guardiola","Bekham","David"};
    string teachers[100] = {"Bekham","David","heidy"};
    
    string students[100] = {"Ansah","bobby","Jacky","Yacob","Rajiv","Daksh","Hakim","Messi","Sane","Salah","daniela","rachel"};

    int numTeachers = 0;
    int numStudents = 0;

    string Assigned[4][11]; 
    for(int i=0; i<4; i++){ //i<4 since thats the maximum no of teachers in current version
        if(teachers[i].length() > 0){
            Assigned[i][0] = teachers[i];
            numTeachers++;
        }
    }
    
    for(int i=0; i<100; i++){ // i<100 since thats the maximum no of teachers in current version
        if(students[i].length() > 0){
            numStudents++;
        }
    }

    /*count blcok
    for(int j=0;j<4;j++){
        for(int i=0;i<10;i++){
            cout << Assigned[j][i];
        }
        cout<<endl;
    }
    */
   
    //random Assign algorithm
    srand(time(0));
    for(int i=0;i<numStudents;i++){
        int randint = ((rand() % numTeachers)); //get a random from 0 - NumberOfTeachers 
        Assigned[randint][i+1] = students[i];
        
    }



   //temporary assign algorithm;
   /*
    for(int j=0;j<4;j++){
        for (int i=0; i<10;i++){
            Assigned[j][i+1] = students[i]; //i+1 since first column occupied by teachers above we are using upto 10 only inside the for loop
        }
    }
    */

   
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

int main(){
assignAlgorithm();
return 0;
}
