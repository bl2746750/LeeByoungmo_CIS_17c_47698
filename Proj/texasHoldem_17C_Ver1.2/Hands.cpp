/* 
 * File:   Hands.cpp
 * Author: Byoung Mo Lee
 * Created on May 18, 2019 20:43 PM
 * Purpose: Hands Class for Texas Holdem
 * 
 */
#include <iostream>
#include <iomanip>
#include <set>
#include <list>
#include <algorithm>
#include <iterator>
#include <map>
#include <string>
#include "Hands.h"

using namespace std;

Hands::Hands():Player(){
    
}
int Hands::getHands(){
    this->checkStraight();
    this->Hands::setSuits();
    this->Hands::setFaces();
    
    if(this->isStraight!=0&&this->isFlush!=0){
        this->isStFl=1;
        this->hands=8;
        set<int,greater<int>> stFl;
        for(auto& it: this->Hands::getMyCards()){
            if(it.getSuit()==this->isFlush) {stFl.insert(it.getFace());}
        }
        if(this->isStraight==15){
            for(int i=14;i>9;i--){
                if(stFl.find(i)==stFl.end()) this->isStFl=0;
            }
        }
        else if(this->isStraight==15){
            for(int i=5;i>1;i--){
                if(stFl.find(i)==stFl.end()) this->isStFl=0;
            }
        }
        else{
            for(int i=this->isStraight;i>this->isStraight-5;i--){
                if(stFl.find(i)==stFl.end()) this->isStFl=0;
            }
        }
        if(this->isStFl==0){
            this->hands=5;
        }
    }
    else if(this->Hands::isPair==7) {this->hands=7;}
    else if(this->isPair==6) {this->hands=6;}
    else if(this->isFlush!=0) {this->hands=5;}
    else if(this->isStraight!=0) {this->hands=4;}
    else if(this->isPair==3) {this->hands=3;}
    else if(this->isPair=2) {this->hands=2;}
    else if(this->isPair=1) {this->hands=1;}
    else {this->hands=0;}
    cout << endl;
    for(auto& it: this->Hands::getMyCards()){
            it.toString();
    }
    cout << endl << this->hands << endl;
}
void Hands::checkStraight(){
    this->isStraight=0;
    set<int, greater<int>> faceSet;
    int cnt=0;
    for(auto& it: this->Hands::getMyCards()){
        faceSet.insert(it.getFace());
    }
//    cout << endl;
    
    set<int>::iterator it=faceSet.begin();
    
    while(it != faceSet.end()&&cnt!=4){
        if(*it-*faceSet.upper_bound(*it)==1) {cnt++;}
        else{cnt=0;}
//        cout << *it << ' ';
        ++it;
    }  
    if(cnt==4&&*it+4!=14) {this->isStraight=*it+4;}
    else if(cnt==4&&*it+4==14) {this->isStraight=15;}
    if(*it==14){
        while(it != faceSet.end()&&cnt!=3){
        if(*it-*faceSet.upper_bound(*it)==1) {cnt++;}
        else{cnt=0;}
//        cout << *it << ' ';
        ++it;
        }
    }
    if(cnt==3&&*it+3==5) {this->isStraight=14;}
//    cout << endl << isStraight << endl;
//    
//    }
//    while(it != faceSet1.end()) {
//        it=faceSet1.begin();
//        int diff=*it-*faceSet1.upper_bound(*it);
//        //cout << *it << endl;
//        if(diff==1) {cnt++;}
//        else if (diff!=1){
//            if(cnt<4) {
//                cnt=0;
//                faceSet1.erase(it);
//            }
//        }
//        ++it;
//    }
//    for(int elem:faceSet1){
//        cout << elem << ' ';
//        if(elem - *faceSet1.upper_bound(elem)==1) {
////            cout << endl << "elem=" << elem << endl;
////            cout << endl << "next=" << *faceSet.upper_bound(elem) << endl;
//            
//            
//            cnt++;
//        }   
//        else if(elem - *faceSet1.upper_bound(elem)!=1&&cnt>=4){
//                break;
//        }
//        else if(elem - *faceSet1.upper_bound(elem)!=1&&cnt<4){
//            cnt=0;
//            faceSet1.erase(elem);
//        }
//        
//            
//    }
//    
//    
//    int cntA=0;
//    if(cnt<4&&faceSet2.find(14)!=faceSet2.end()){
//        faceSet2.insert(1);
//        
//        for(int elem:faceSet2){
//            if(elem - *faceSet2.upper_bound(elem)==1) {
//    //            cout << endl << "elemA=" << elem << endl;
//                cntA++;
//            }        
//            else if(elem - *faceSet2.upper_bound(elem)!=1&&cnt<4){
//                cntA=0;
//            }
//             else if(elem - *faceSet2.upper_bound(elem)!=1&&cnt>=4){
//                break;
//            }
//        }   
//    }
//    cout << endl;
//    cout << cnt << ' ' << cntA << endl;
//    cout << endl;
//    if(cnt>=4) {this->isStraight=*(faceSet1.begin());}
//    else if(cntA>=4) {this->isStraight=*(faceSet2.begin());}
//    
//    cout << "isStraight: " << this->isStraight << endl;
}


void Hands::setSuits(){
    this->isFlush=0;
    multiset<int> suitSet;
    for(auto& it: this->Hands::getMyCards()){
        suitSet.insert(it.getSuit());
    }
//    for(int elem:suitSet){
//        cout << elem << ' ';
//    }
    
    for(int i=0;i<4;i++){
        if(suitSet.count(i)>4) {
            this->suits.insert(pair<int,int>(suitSet.count(i),i));
            this->isFlush=1;
        }
    }
//    cout << endl;
    map<int,int>::iterator pos;
//    for(pos=this->suits.begin();pos!=this->suits.end();++pos){
//        cout << "num: " <<  pos->first << ' '
//             << "suits: " << pos->second << endl;
//    }
//        
//    cout << endl;
    
    
}
void Hands::setFaces(){
    
    multiset<int> faceSet;
    for(auto& it: this->Hands::getMyCards()){
        faceSet.insert(it.getFace());
    }
//    for(int elem:faceSet){
//        cout << elem << ' ';
//    }
    for(int i=2;i<15;i++){
        if(faceSet.count(i)>1) this->faces.insert(pair<int,int>(faceSet.count(i),i));
    }
//    cout << endl;
    map<int,int>::iterator pos;
//    for(pos=this->faces.begin();pos!=this->faces.end();++pos){
//        cout << "pairs: " <<  pos->first << ' '
//             << "faces: " << pos->second << endl;
//    }
//    cout << endl;
    
    if(this->faces.empty()) {this->isPair=0;}
    else if(this->faces.size()==1){
        for(pos=this->faces.begin();pos!=this->faces.end();++pos){
            if(pos->first==2) this->isPair=1;
            if(pos->first==3) this->isPair=3;
            if(pos->first==4) this->isPair=7;
        }
    }
    else if(this->faces.size()==2){
        for(pos=this->faces.begin();pos!=this->faces.end();++pos){
            if(pos->first==2) this->isPair=2;
            if(pos->first==3) this->isPair=6;
        }
    }
    
}