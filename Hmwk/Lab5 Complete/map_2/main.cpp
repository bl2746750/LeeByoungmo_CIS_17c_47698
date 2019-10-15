/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: byoung
 *
 * Created on October 11, 2019, 2:29 PM
 */
#include <map>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    map<string,double> coll { { "tim", 9.9 },
                              { "struppi", 11.77 }
                            } ;

    // square the value of each element:
    for_each (coll.begin(), coll.end(),
              [] (pair<const string,double>& elem) {
                    elem.second *= elem.second;
              });

    // print each element:
    for_each (coll.begin(), coll.end(),
              [] (const map<string,double>::value_type& elem) {
                    cout << elem.first << ": " << elem.second << endl;
              });
}