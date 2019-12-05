/* 
 * Author: Student Byoung Mo Lee
 * Created on December 4, 2019, 3:44 PM
 * Purpose: C++ program for different tree traversals
 * reference to: Gaddis, Tonny "C++ From Control Structures Tthrough Object", chapter21 
 */


#include <iostream>
using namespace std;
 
//User Library
#include "Tree.h"


/* Driver program to test above functions*/
int main(){
    Tree<int> tree;
    tree.insert(8);
    tree.insert(4);
    tree.insert(12);
    tree.insert(2);
    tree.insert(6);
    tree.insert(10);
    tree.insert(14);
    tree.insert(1);
    tree.insert(3);
    tree.insert(5);
    tree.insert(9);
    tree.insert(11);
    tree.insert(13);
    tree.insert(15);
    
    tree.remove(8);
    tree.remove(15);
    
    cout<<endl<<"Preorder traversal of binary tree is "<<endl;
    tree.prntPre();

    cout<<endl<<"Inorder traversal of binary tree is "<<endl;
    tree.prntIn();  

    cout<<endl<<"Postorder traversal of binary tree is "<<endl;
    tree.prntPst();

    cout<<endl<<"Level Order traversal of binary tree is"<<endl;  
    tree.prntLev();

    //Exit stage right!
    return 0;
}

//Helper function that allocates a new node with the
//given data and NULL left and right pointers.
//node* newNode(int data){
//     node *n;
//     n=new node;
//     n->data = data;
//     n->left = NULL;
//     n->right = NULL;
//     return n;
//}
 
