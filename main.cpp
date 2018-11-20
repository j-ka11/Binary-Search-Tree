// Sample driver
// EE 312 Fall 2018
//
// The BST should work for any data type or object.
// Other user created objects must have the << operator overloaded for 
// output.
//
//Joshua Kall
//jsk2544
//11/19/18

#include <iostream>
#include <fstream>
#include "BST312.h"

using namespace std;

template <typename T>
void print(vector<T> vec){
    for(int i = 0 ; i < vec.size() ; i++){
        cout << vec[i] << endl;;
    }
}

int main() {

    ifstream inFile;
    inFile.open("test.txt");

    BST_312<string> bst;
   
    string s;
    inFile >> s;
    while (inFile) {;
        cout << "inserting ... " << s << endl;
        bst.insertItem(s);
        inFile >> s;
    }

    cout << "preorder traversal is " << endl;
    print(bst.preOrderTraversal());
    cout << endl;

    cout << "inorder traversal is " << endl;
    print(bst.inOrderTraversal());
    cout << endl;

    cout << "postorder traversal is " << endl;
    print(bst.postOrderTraversal());
    cout << endl;

    cout << "testing isItemInTree" << endl;
    string test1 = "This";
    string test2 = "is";
    string test3 = "a";
    string test4 = "series";
    string test5 = "of";
    string test6 = "words";
    string test7 = "to";
    string test8 = "test";
    string test9 = "the";
    string test10 = "tree";
    string test11 = "this";
    string test12 = "notIn";
    string test13 = " ";
    string test14 = "A";
    string test15 = "series of";
    cout << "This: " << bst.isItemInTree(test1) << endl;
    cout << "is: " << bst.isItemInTree(test2) << endl;
    cout << "a: " << bst.isItemInTree(test3) << endl;
    cout << "series: " << bst.isItemInTree(test4) << endl;
    cout << "of: " << bst.isItemInTree(test5) << endl;
    cout << "words: " << bst.isItemInTree(test6) << endl;
    cout << "to: " << bst.isItemInTree(test7) << endl;
    cout << "test: " << bst.isItemInTree(test8) << endl;
    cout << "the: " << bst.isItemInTree(test9) << endl;
    cout << "tree: " << bst.isItemInTree(test10) << endl;
    cout << "this: " << bst.isItemInTree(test11) << endl;
    cout << "notIn: " << bst.isItemInTree(test12) << endl;
    cout << " : " << bst.isItemInTree(test13) << endl;
    cout << "A: " << bst.isItemInTree(test14) << endl;
    cout << "series of: " << bst.isItemInTree(test15) << endl;

    cout << "Remove items " << endl;
    cout << "number of nodes in tree before delete is " << bst.countNodes() << endl;
    s = "tree";
    bst.deleteItem(s);
    cout << endl;
    cout << "number of nodes in tree after delete is " << bst.countNodes() << endl;
    cout << endl;



}

