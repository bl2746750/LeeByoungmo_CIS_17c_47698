
/* 
 * File:   main.cpp
 * Author: Student Byoung Mo Lee
 * Purpose: Permutation and Combination Comparison
 * Created on September 28, 2019, 1:49 PM
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>


using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int n,m;
    float pRepfloat, pNoRepfloat, cRepfloat, cNoRepfloat;
    int pRepPow,pNoRepPow, cRepPow, cNoRepPow;
    float pRepLog, pNoRepLog, cRepLog, cNoRepLog;
    string pRepStr,pNoRepStr, cRepStr, cNoRepStr;
    
    cout<<"P -> Permutation(Order Matters)"<<endl;
    cout<<"C -> Combination(Order does not matter)"<<endl;
    cout<<"Rep -> with replacement"<<endl;
    cout<<"no Rep -> no replacement"<<endl;
    cout<<"N -> Number of total elements"<<endl;
    cout<<"M -> Number of elements to take from the total"<<endl<<endl;
    cout<<" N M P Rep P no Rep C Rep C no Rep"<<endl;
    cout<<" N^M N!/(N-M)! (N+M-1)!/((N-1)!M!) N!/((N-M)!M!)"<<endl<<endl;
    
    for(n=2;n<=26;n++){
        for(m=0;m<=n;m++){
            pRepLog=m*log10(n);
            pRepPow=(int)pRepLog;
            pRepfloat=pow(10,pRepLog-pRepPow);
            pRepStr=to_string(pRepfloat) + "E+" +to_string(pRepPow);
            
            pNoRepLog=0;
            for(int i=n-m+1;i<=n;i++){
                pNoRepLog+=log10(i);
            }
            pNoRepPow=(int)pNoRepLog;
            pNoRepfloat=pow(10,pNoRepLog-pNoRepPow);
            pNoRepStr=to_string(pNoRepfloat)+"E+"+to_string(pNoRepPow); 
            
            cRepLog=0;
            for(int i=n;i<=n+m+1;i++){
                cRepLog+=log10(i);
            }
            for(int j=1;j<=m;j++){
                cRepLog-=log10(j);
            }
            cRepPow=(int)cRepLog;
            cRepfloat=pow(10,cRepLog-cRepPow);
            cRepStr=to_string(cRepfloat)+"E+"+to_string(cRepPow);
            
            
            cNoRepLog=0;
            for(int i=1;i<=m;i++){
                cNoRepLog+=log10(i);
            }
            cNoRepLog=pNoRepLog-cNoRepLog;
            cNoRepPow=(int)cNoRepLog;
            cNoRepfloat=pow(10,cNoRepLog-cNoRepPow);
            cNoRepStr=to_string(cNoRepfloat)+"E+"+to_string(cNoRepPow);

            
            cout << setw(5) << n 
                    << setw(5) << m 
                    << setw(15)<< pRepStr
                    << setw(15) << pNoRepStr 
                    << setw(15) << cRepStr 
                    << setw(15) << cNoRepStr << endl; 
        }
    }
    return 0;
}

