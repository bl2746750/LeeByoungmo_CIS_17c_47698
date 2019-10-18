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
using namespace std::chrono; 

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
    int N=20000;
    string* arr1=new string[N];
    //Initialize Variables
    for(int i=0;i<N;i++){
        arr1[i]=str;
    }
    //Process inputs to outputs/map
    auto start1 = high_resolution_clock::now();
    linearSearch(arr1,N,str);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1 - start1);
    auto start2 = high_resolution_clock::now();
    linearSearch(arr1,N,str1);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    
    //Display the results
     
  
    cout << "linear Search1: "
         << duration1.count() << " microseconds" << endl; 
    cout << "linear Search2: "
         << duration2.count() << " microseconds" << endl; 
    //Clean up and exit stage right
    delete[] arr1;
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