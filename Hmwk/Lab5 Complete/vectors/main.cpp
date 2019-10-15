/* 
 * File:   main.cpp
 * Author: Student Byoung Mo Lee
 * Purpose: Learing vector1 (p.169)
 * Created on October 9, 2019, 4:53 PM
 */

#include <vector>
#include <iostream>


using namespace std;

/*
 * 
 */
#include <vector>
#include <iostream>
using namespace std;

int main()
{
    vector<int> coll;    
    for (int i=1; i<=6; ++i) {
        coll.push_back(i);
    }

    
    for (int i=0; i<coll.size(); ++i) {
        cout << coll[i] << ' ';
    }
    cout << endl;
}