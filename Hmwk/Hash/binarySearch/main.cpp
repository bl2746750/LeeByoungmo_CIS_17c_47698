/* 
 * File:   main.cpp
 * Author: Name
 * Date:
 * Purpose:
 */

//System Libraries
#include <chrono> 
#include <iostream>
#include <string>

using namespace std;
//using namespace std::chrono; 

//User Libraries

//Global Constants

//Function Prototypes
int linearSearch(const string[],int,string);
int binarySearch(const string[],int,string);
//Execution Begins Here
int main(int argc, char** argv) {
    //Set random number seed here
    
    //Declare Variables
    string str="kjeljwa32lkae94;23oe";
    string str1="oekjlajfljekljvklklj";
    int N=100;
    string* arr2=new string[N];
    //Initialize Variables
    for(int i=0;i<N;i++){
        arr2[i]=str;
    }
    //Process inputs to outputs/map
    auto start3 = chrono::high_resolution_clock::now();
    int a=binarySearch(arr2,N,str);
    auto stop3 = chrono::high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(stop3 - start3);
    auto start4 = chrono::high_resolution_clock::now();
    int b=binarySearch(arr2,N,str1);
    auto stop4 = chrono::high_resolution_clock::now();
    auto duration4 = duration_cast<microseconds>(stop4 - start4);
    //Display the results
     
  
    cout << "binary Search1: "
         << duration3.count() << " microseconds" << endl 
         << a  << endl;
    cout << "binary Search2: "
         << duration4.count() << " microseconds" << endl 
         << b  << endl;
    //Clean up and exit stage right
    delete[] arr2;
    return 0;
}

int linearSearch(const string arr[],int size, string value){
    int index=0;
    int position=-1;
    bool found=false;
    
    while(index<size&&!found){
        if(arr[index]==value){
            found=true;
            position=index;
        }
        index++;
    }
    return position;
}
int binarySearch(const string arr[],int size,string value){
    int first=0,
            last=size-1,
            middle,
            position=-1;
    bool found=false;
    
    while(!found && first<=last){
        middle=(first+last)/2;
        if(arr[middle]==value){
            found=true;
            position=middle;
        }
        else if(arr[middle]>value) last=middle-1;
        else first=middle+1;
    }
    return position;
}