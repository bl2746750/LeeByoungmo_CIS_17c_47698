 /*Author: Dr. Mark E. Lehr
 * Created on November 11, 2011, 9:26 AM
 * Purpose:  Shell Sort
 */

//System Libraries
#include <cstdlib>  //Random Function
#include <iostream> //I/O
#include <ctime>    //Set the seed
using namespace std;

//User Libraries

//Global Constants
//Math/Physics/Conversion/Higher Order Dimensions

//Function Prototypes
int *fillAry(int);
void prntAry(int *,int,int);
void swap(int *, int *);
int prtiShn (int *,int,int);
void quikSrt(int *,int,int);

//Execution Begins 
int main(int argc, char** argv) {
    //Set random number seed here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int *array;
    int size=200;
    int perLine=20;
    
    //Initialize/Input Data/Variables
    array=fillAry(size);

    //Display output
    prntAry(array,size,perLine);
    
    //Sort
    quikSrt(array,0,size-1);
    
    //Display output
    prntAry(array,size,perLine);
    
    //Clean up dynamic memory
    delete []array;
    
    //Exit program
    return 0;
}

void prntAry(int *a,int n,int perLine){
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
        if(i%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

int *fillAry(int n){
    int *array=new int[n];
    for(int i=0;i<n;i++){
        array[i]=rand()%90+10;//[10-99]
    }
    return array;
}

// A utility function to swap two elements 
void swap(int* a, int* b) { 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

/* This function takes last element as pivot, places 
the pivot element at its correct position in sorted 
array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right 
of pivot */
int prtiShn(int *arr,int low,int high){ 
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element 

    for (int j = low; j <= high - 1; j++){ 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 

/* The main function that implements QuickSort 
arr --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quikSrt(int *arr,int low,int high){ 
    if (low < high){ 
            /* pi is partitioning index, arr[p] is now 
        at right place */
        int pi = prtiShn(arr, low, high); 

        // Separately sort elements before 
        // partition and after partition 
        quikSrt(arr, low, pi - 1); 
        quikSrt(arr, pi + 1, high); 
    } 
} 
