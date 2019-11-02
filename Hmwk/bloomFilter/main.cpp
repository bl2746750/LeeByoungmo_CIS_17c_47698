/* 
 * File:   main.cpp
 * Author: Student Byoung Mo lee        
 * Date: November 1st, 2019 4:22 PM
 * Purpose: Bloom Filter
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

//User Libraries

//Global Constants

//Function prototypes
unsigned int mrkHash(char*);
unsigned int MurmurHash2 (char*);
char* filArry();

//Execution begins here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare Variables
    const int LSTSIZE=4;  //number of name created 
    const int BFSIZE=15;   //Bloom Filter list size
    int randSize;          //name array size
    int count[BFSIZE]={};
    int k=2;               //number of hash functions
    char* array;
    //Create the String and Record the hash collissions
    for(int i=0;i<LSTSIZE;i++){
        array=filArry();
        cout<<array<<endl;
        count[mrkHash(array)%BFSIZE]++;
        count[MurmurHash2(array)%BFSIZE]++;
    }
    
    //Output the array occupation
    cout<<"Bloom Filter: ";
    for(int i=0;i<BFSIZE;i++){
        cout<<setw(3) << count[i]<<" ";
    }
    cout << endl;
    cout<<"Index       : ";
    for(int i=0;i<BFSIZE;i++){
        cout<<setw(3)<<i<<" ";
    }
    cout << endl << endl;
    
    char* array2=filArry();
    cout << "Name to find in the bloomfilter: " << array2 << endl;
    cout << "mrkHash:" << mrkHash(array2)%BFSIZE << endl; 
    cout << "MurmurHash2: " << MurmurHash2(array2)%BFSIZE << endl;
    if(count[mrkHash(array2)%BFSIZE]==0||count[MurmurHash2(array2)%BFSIZE]==0){
        cout << "Not in the list" << endl;
    }
    else cout << "Maybe" << endl;
    cout << endl;
    cout << "Probability of false alarm" << endl;
    cout << "1. Equation: (1-(1-1/n)^(km))^k" << endl;
    cout << "              where n=Bloom Filter Size=" << BFSIZE 
            << ", m=number of name in the list=" << LSTSIZE;
    cout << ", k=number of hash function=" << 2 << endl;
    float x=1-1.0/BFSIZE;
    float y=1-pow(x,1.0*k*LSTSIZE);
    cout << "2. Calculation: " << pow(y,k)*100 << "%" << endl;
    
    //Exit stage right
    delete [] array;
    delete [] array2;
    return 0;
}

char* filArry(){
    int randSize=rand()%10+3;  //name size: 3> and <13
    char* a=new char [randSize];
    for(int i=0;i<randSize-1;i++){
        int any=rand()%26;
        if(i==0)a[i]=any+65;
        else a[i]=any+97;
        }
    a[randSize-1]='\0';
    
    return a;
}

unsigned int mrkHash(char *a){
    unsigned int sum=0,prod=1;
    char c;
    int n=0;
    while(a[n]!='\0'){n++;}
    
    for(int i=0;i<n;i++){
        if(a[i]<=91)c=a[i]-65;
        else c=a[i]-71;
        sum+=(sum+c*prod);
        prod*=52;
        prod%=9999991;
        sum%=999999991;
    }
    return sum;
}


//-----------------------------------------------------------------------------
// MurmurHash2, by Austin Appleby

// Note - This code makes a few assumptions about how your machine behaves -

// 1. We can read a 4-byte value from any address without crashing
// 2. sizeof(int) == 4

// And it has a few limitations -

// 1. It will not work incrementally.
// 2. It will not produce the same results on little-endian and big-endian
//    machines.

unsigned int MurmurHash2 (char *a)
{
	// 'm' and 'r' are mixing constants generated offline.
	// They're not really 'magic', they just happen to work well.
        unsigned int seed=1;
	const unsigned int m = 0x5bd1e995;
	const int r = 47;
        int len=0;
        //find the value of len
        while(a[len]!='\0'){len++;}
	// Initialize the hash to a 'random' value
        
	unsigned int h = seed ^ len;

	// Mix 4 bytes at a time into the hash

	const unsigned char * data = (const unsigned char *)a;

	while(len >= 4)
	{
		unsigned int k = *(unsigned int *)data;

		k *= m; 
		k ^= k >> r; 
		k *= m; 
		
		h *= m; 
		h ^= k;

		data += 4;
		len -= 4;
	}
	
	// Handle the last few bytes of the input array

	switch(len)
	{
	case 3: h ^= data[2] << 16;
	case 2: h ^= data[1] << 8;
	case 1: h ^= data[0];
	        h *= m;
	};

	// Do a few final mixes of the hash to ensure the last few
	// bytes are well-incorporated.

	h ^= h >> 13;
	h *= m;
	h ^= h >> 15;

	return h;
} 
