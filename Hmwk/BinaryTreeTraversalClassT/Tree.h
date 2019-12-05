/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Tree.h
 * Author: libmo
 *
 * Created on December 4, 2019, 3:42 AM
 */

#ifndef TREE_H
#define TREE_H

#include <iostream>
using namespace std;


template <class T>
class Tree {
private:
    struct node {
        T data;
        node *left;
        node *right;
    };
    node *root;

    void insert(node *&, node *&);
    void destroySubTree(node*);
    void deleteNode(T,node *&);
    void makeDeletion(node *&);
    void prntPst(node*);
    void prntIn(node*);
    void prntLev(node*, int);
    int height(node *);    
    void prntPre(node*);

public:
    Tree() {root = nullptr;}
    ~Tree() {destroySubTree(root);}
    void insert(T);
    void remove(T val){deleteNode(val, root);}
    void prntPst(){prntPst(root);}
    void prntIn(){prntIn(root);}
    void prntPre() {prntPre(root);}
    void prntLev() {int h = height(root);for (int i = 1; i <= h; i++)prntLev(root, i);}
    int height() {return height(root);}
};

template <class T>
void Tree<T>::insert(node *&nodePtr, node *&newNode) {
    if (nodePtr == nullptr) nodePtr = newNode;
    else if (newNode->data < nodePtr->data) insert(nodePtr->left, newNode);
    else insert(nodePtr->right, newNode);
}

template <class T>
void Tree<T>::destroySubTree(node* nodePtr) {
    if (nodePtr) {
        if (nodePtr->left) {
            destroySubTree(nodePtr->left);
        }
        if (nodePtr->right) {
            destroySubTree(nodePtr->right);
        }
        delete nodePtr;

    }
}

template <class T>
void Tree<T>::deleteNode(T val, node *&nodePtr) {
    if (val < nodePtr->data) {
        deleteNode(val, nodePtr->left);
    } else if (val > nodePtr->data) {
        deleteNode(val, nodePtr->right);
    } else {
        makeDeletion(nodePtr);
    }
}

template <class T>
void Tree<T>::makeDeletion(node *&nodePtr) {
    node* tempNodePtr = nullptr;
    if (nodePtr == nullptr) {
        cout << "Empty Node\n";
    } else if (nodePtr->right == nullptr) {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->left;
        delete tempNodePtr;
    } else if (nodePtr->left == nullptr) {
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    } else {
        tempNodePtr = nodePtr->right;
        while (tempNodePtr->left) {
            tempNodePtr = tempNodePtr->left;
        }
        tempNodePtr->left = nodePtr->left;
        tempNodePtr = nodePtr;
        nodePtr = nodePtr->right;
        delete tempNodePtr;
    }
}


template <class T>
void Tree<T>::prntPst(node* node) {
    if (node == nullptr)return;
    // first recur on left subtree
    prntPst(node->left);
    // then recur on right subtree
    prntPst(node->right);
    // now deal with the node
    cout << node->data << " ";
}

template <class T>
void Tree<T>::prntIn(node* node) {
    if (node == nullptr)return;
    /* first recur on left child */
    prntIn(node->left);
    /* then print the data of node */
    cout << node->data << " ";
    /* now recur on right child */
    prntIn(node->right);
}

template <class T>
void Tree<T>::prntLev(node* node, int level) {
    if (node == nullptr)return;
    if (level == 1)
        cout << node->data << " ";
    else if (level > 1) {
        prntLev(node->left, level - 1);
        prntLev(node->right, level - 1);
    }
}

template <class T>
int Tree<T>::height(node *node) {
    if (node == nullptr) return 0;
    //compute the height of each subtree
    int lheight = height(node->left);
    int rheight = height(node->right);
    //use the larger one
    if (lheight > rheight) return (lheight + 1);
    else return (rheight + 1);
}



template <class T>
void Tree<T>::insert(T val) {
    node* newNode = nullptr;
    newNode = new node;
    newNode->data = val;
    newNode->left = newNode->right = nullptr;

    insert(root, newNode);
}

template <class T>
void Tree<T>::prntPre(node* node) {
    if (node == nullptr)return;
    /* first print data of node */
    cout << node->data << " ";
    /* then recur on left subtree */
    prntPre(node->left);
    /* now recur on right subtree */
    prntPre(node->right);
}

#endif /* TREE_H */

