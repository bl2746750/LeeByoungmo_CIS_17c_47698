/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Student Byoung Mo Lee
 * Purpose: Tic Tac Toe
 * Created on September 28, 2019, 8:47 PM
 */

#include <string>
#include <iostream>

using namespace std;

/*
 * 
 */

string check(string [][3]);
int main(int argc, char** argv) {
    
    string table[3][3];
    string mark;
    int row, col;
    int end=0;
    string winner="0";
    
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            table[i][j]=to_string(i*j);
        }
    }
    
    do{
        cout << "Enter row, col, and mark(o or x)" << endl;
        cin >> row >> col >> mark;
        table[row][col]=mark;
        winner=check(table);
        
    }while(winner=="0");
    
    cout << winner << " won!!!" << endl;
    
    return 0;
}
string check(string tab[][3]){
    int end=0;
    string winner="0";
    if(tab[0][0]==tab[0][1] && tab[0][1]==tab[0][2]) {end=1;winner=tab[0][0];}
    else if(tab[1][0]==tab[1][1] && tab[1][1]==tab[1][2]) {end=1;winner=tab[1][0];}
    else if(tab[2][0]==tab[2][1] && tab[2][1]==tab[2][2]) {end=1;winner=tab[2][0];}
    else if(tab[0][0]==tab[1][0] && tab[1][0]==tab[2][0]) {end=1;winner=tab[0][0];}
    else if(tab[0][1]==tab[1][1] && tab[1][1]==tab[2][1]) {end=1;winner=tab[0][1];}
    else if(tab[0][2]==tab[1][2] && tab[1][2]==tab[2][2]) {end=1;winner=tab[0][2];}
    else if(tab[0][2]==tab[1][1] && tab[1][1]==tab[2][0]) {end=1;winner=tab[0][2];}
    else if(tab[0][0]==tab[1][1] && tab[1][1]==tab[2][2]) {end=1;winner=tab[0][0];}
    return winner;
}
