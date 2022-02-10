#include <iostream>
#include <time.h>

using namespace std;


void assignAlgorithm(){
    string teachers[4] = {"prasad","timmy","jobs","nana"};
    
    string students[10] = {"Ansa","bab","jack","jacob","rajw","dam","tripod","ans","er","daniel"};

    int maxStudent = 2;
    int numTeachers = 4;

    string Assigned[4][11];

    for(int i=0;i<4;i++){
        Assigned[i][0] = teachers[i];
    }
    

   //temporary assign algorithm;
   
    for(int j=0;j<4;j++){
        for (int i=0; i<10;i++){
            Assigned[j][i+1] = students[i+1]; //i+1 since first column occupied by teachers above we are using upto 10 only inside the for loop
        }
    }
    
    //output-ing
    string output = "";
    for (int j=0; j<4; j++){
        for (int i=0; i< 11; i++){
            if (i == 0){
                output += "\n" + Assigned[j][i] + " : ";
            }
            else{
            output += Assigned[j][i] + " - ";
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
