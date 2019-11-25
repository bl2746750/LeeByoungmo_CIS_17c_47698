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
void shelSrt(int *, int);

//Execution Begins 
int main(int argc, char** argv) {
    //Set random number seed here
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    int *array;
    int size=1000;
    int perLine=20;
    
    //Initialize/Input Data/Variables
    array=fillAry(size);

    //Display output
    //prntAry(array,size,perLine);
    
    //Sort
    int beg=time(0);
    shelSrt(array,size);
    int end=time(0);
    //Display output
    //prntAry(array,size,perLine);
    cout << "Total Time= " << end-beg << " Seconds" << endl;
    cout << "For Quick Sort Array Size = " << size << endl;
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

void shelSrt(int *arr, int n) { 
    // Start with a big gap, then reduce the gap 
    for (int gap = n/2; gap > 0; gap /= 2){ 
        // Do a gapped insertion sort for this gap size. 
        // The first gap elements a[0..gap-1] are already in gapped order 
        // keep adding one more element until the entire array is 
        // gap sorted 
        for (int i = gap; i < n; i += 1){ 
            // add a[i] to the elements that have been gap sorted 
            // save a[i] in temp and make a hole at position i 
            int temp = arr[i]; 

            // shift earlier gap-sorted elements up until the correct 
            // location for a[i] is found 
            int j;			 
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) 
                    arr[j] = arr[j - gap]; 

            // put temp (the original a[i]) in its correct location 
            arr[j] = temp; 
        } 
    } 
} 