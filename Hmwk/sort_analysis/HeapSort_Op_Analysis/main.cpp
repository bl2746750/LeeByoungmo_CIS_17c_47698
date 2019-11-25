 /*Author: Dr. Mark E. Lehr
 * Created on November 11, 2011, 9:26 AM
 * Purpose:  Heap Sort in 2 routines
 */

//System Libraries
#include <cstdlib>  //Random Function
#include <iostream> //I/O
#include <ctime>    //Set the seed
using namespace std;

//User Libraries

//Global Constants
//Math/Physics/Conversion/Higher Order Dimensions
int opCnt=0;
//Function Prototypes
int *fillAry(int);
void prntAry(int *,int,int);
void heapify(int *,int, int);
void heapSrt(int *, int);

//Execution Begins 
int main(int argc, char** argv) {
    //Set random number seed here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int *array;
    int size=10000;
    int perLine=20;
    
    //Initialize/Input Data/Variables
    array=fillAry(size);

    //Display output
    //prntAry(array,size,perLine);
    
    //Sort
    heapSrt(array,size);
    //Display output
    //prntAry(array,size,perLine);
    cout << "Number of Operations = " << opCnt << endl;
    cout << "For Shell Sort Array Size = " << size << endl;  
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
        array[i]=rand();//[10-99]
    }
    return array;
}

// To heapify a subtree rooted with node i which is 
// an index in arr[]. n is size of heap 
void heapify(int *arr, int n, int i) { 
    opCnt+=7;
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
    
    // If left child is larger than root 
    opCnt+=4;
    if (l < n && arr[l] > arr[largest]) {
        largest = l; 
        opCnt++;
    }
    // If right child is larger than largest so far 
    opCnt+=3;
    if (r < n && arr[r] > arr[largest]){ 
            largest = r; 
            opCnt++;
    }

    // If largest is not root 
    opCnt++;
    if (largest != i) 
    { 
        opCnt+=4;    
        swap(arr[i], arr[largest]); 
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 

void heapSrt(int *arr, int n) { 
    // Build heap (rearrange array) 
    opCnt+=5;
    for (int i = n / 2 - 1; i >= 0; i--){ 
            heapify(arr, n, i); 
            opCnt++;
    }
    // One by one extract an element from heap 
    opCnt+=4;
    for (int i=n-1; i>=0; i--) 
    { 
            // Move current root to end 
            swap(arr[0], arr[i]); 
            opCnt+=4;
            // call max heapify on the reduced heap 
            heapify(arr, i, 0); 
    } 
} 