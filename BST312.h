
/*  BST312.h
  CS 312 Fall 2018

  a simple implementation of a binary search tree


*/

#ifndef BST_312_H
#define BST_312_H

#include <cstdlib>  // Provides size_t
#include <iostream>
#include <vector>

using namespace std;

template<class ItemType>
class BST_312 {
public:

    BST_312();

    //Copy constructor
    BST_312(const BST_312 & src);

    ~BST_312();

/****************************
makeEmpty

Function: Removes all the items from the BST.
Preconditions: BST has been initialized
Postconditions: All the items have been removed
*****************************/
    void makeEmpty();

/****************************
isEmpty

Function: Checks to see if there are any items in the BST.
Preconditions: BST has been initialized
Postconditions: Returns true if there are no items in the BST, else false.
*****************************/
    bool isEmpty() const;

/****************************
isFull

Function: Determines if you have any more room to add items to the BST
Preconditions: BST has been initialized
Postconditions: Returns true if there is no more room to add items, else false
*****************************/
    bool isFull() const;

/****************************
insertItem

Function: Adds newItem to the BST.
Preconditions: BST has been initialized and is not full.
Postconditions: newItem is in the proper position for a BST.
*****************************/
    void insertItem(const ItemType &);

/****************************
deleteItem

Function: Removes target from BST.
Preconditions: BST has been initialized.
Postconditions: If found, element has been removed from BST.
*****************************/
    void deleteItem(const ItemType& newItem);

/****************************
countNodes

Function: Counts the number of nodes in the BST
Preconditions: BST has been initialized.
Postconditions: returns the number of nodes in the BST
*****************************/
    int countNodes();

/****************************
preOrderTraversal

Function: Returns the preOder (Node, Left, Right) as a vector of ItemTypes
Preconditions: BST has been initialized.
Postconditions: none
*****************************/
    vector<ItemType> preOrderTraversal();

/****************************
inOrderTraversal

Function: Returns the inOder (Left, Node, Right) as a vector of ItemTypes
Preconditions: BST has been initialized.
Postconditions: none
*****************************/
    vector<ItemType> inOrderTraversal();

/****************************
postOrderTraversal

Function: returns the postOder (Left, Right, Node) as a vector of ItemTypes
Preconditions: BST has been initialized.
Postconditions: none
*****************************/
    vector<ItemType> postOrderTraversal();

/********************
 isItemInTree

Function: Determines if a given Item is in tree.
Preconditions: BST has been initialized.
Postconditions: none
*****************************/

    bool isItemInTree(const ItemType& item);


private:
    struct TreeNode {
        ItemType data;
        TreeNode *left;
        TreeNode *right;
    };

    TreeNode * root;

    int numNodes;

    void insertItem(TreeNode*& t, const ItemType& newItem);
    void inOrderTraversal(TreeNode* t,vector<ItemType>& result) const;
    int countNodes(TreeNode* t) const;
    void deleteNode(TreeNode*& node);
    void makeEmpty(TreeNode*& t);
    void deleteItem(TreeNode*& t, const ItemType& newItem);
    void getPredecessor(TreeNode*& t, ItemType& data);
    void preOrderTraversal(TreeNode* t,vector<ItemType>& result) const;
    void postOrderTraversal(TreeNode* t,vector<ItemType>& result) const;
    void copyTree(TreeNode*& copy, const TreeNode *originalTree);

};

/*******************************
//Function implementations
********************************/

template<class ItemType>
BST_312<ItemType>::BST_312 ()
{
    root = NULL;
    numNodes = 0;
}

template<class ItemType>
BST_312<ItemType>::BST_312(const BST_312 & src)
{
    copyTree(root, src.root);
}

template<class ItemType>
BST_312<ItemType>::~BST_312()
{
    makeEmpty();

}


template<class ItemType>
void BST_312<ItemType>::copyTree(TreeNode*& copy, const TreeNode* originalTree)
{
    if (originalTree == NULL)
        copy = NULL;
    else
    {
        copy = new TreeNode;
        copy->data = originalTree->data;

        copyTree(copy->left, originalTree->left);
        copyTree(copy->right, originalTree->right);
    }
}


template<class ItemType>
void BST_312 <ItemType>::deleteNode(TreeNode*& t)
{
    ItemType info;
    TreeNode *tempPtr;

    tempPtr = t;

    if (t->left == NULL)
    {
        t = t->right;
        delete tempPtr;
        numNodes--;
    }
    else if (t->right == NULL)
    {
        t = t->left;
        delete tempPtr;
        numNodes--;
    }
    else
    {
        getPredecessor(t->left, info);
        t->data = info;
        deleteItem(t->left, info);
    }
}



//find largest in left subtree
template<class ItemType>
void BST_312 <ItemType>::getPredecessor(TreeNode*& t, ItemType& data) {
    while (t->right != NULL)
        t = t->right;

    data = t->data;
}


template<class ItemType>
void BST_312 <ItemType>::deleteItem(TreeNode*& t, const ItemType& newItem)
{
    if (t == NULL)
        return;
    else if (newItem < t->data)
        deleteItem(t->left, newItem);
    else if (newItem > t->data)
        deleteItem(t->right, newItem);
    else
        deleteNode(t);
}


template<class ItemType>
void BST_312 <ItemType>::deleteItem(const ItemType& newItem)
{
    deleteItem(root, newItem);

}

template<class ItemType>
void BST_312 <ItemType>::makeEmpty(TreeNode*& t)
{
    //YOUR CODE GOES HERE
    while(t != NULL){
        deleteItem(t->data);
    }
}

template<class ItemType>
void BST_312 <ItemType>::makeEmpty()
{
    makeEmpty(root);
    root = NULL;
}

template<class ItemType>
bool BST_312 <ItemType>::isEmpty() const
{
    return root == NULL;
}



template<class ItemType>
bool BST_312 <ItemType>::isFull() const
{
    try
    {
        TreeNode *temp = new TreeNode;
        delete temp;
        return false;
    }
    catch (std::bad_alloc)
    {
        return true;
    }

}


template<class ItemType>
void BST_312 <ItemType>::insertItem(TreeNode*& t, const ItemType& newItem)
{
    //YOUR CODE GOES HERE
    if(this->root == NULL){
        root = new TreeNode();
        numNodes++;
        root->data = newItem;
    }else {
        TreeNode *newNode = new TreeNode();
        numNodes++;
        newNode->data = newItem;
        newNode->left == NULL;
        newNode->right == NULL;
        if (newItem.compare(t->data) < 0) {
            t->left = newNode;
        } else {
            t->right = newNode;
        }
    }
}

template<class ItemType>
void BST_312 <ItemType>::insertItem(const ItemType& newItem)
{
    //YOUR CODE GOES HERE
    if(this->root == NULL){
        TreeNode* temp = root;
        insertItem(root, newItem);
    }else{
        TreeNode* temp = root;
        while(temp != NULL) {
            if (newItem.compare(temp->data) < 0) {
                if (temp->left != NULL) {
                    temp = temp->left;
                } else {
                    insertItem(temp, newItem);
                    return;
                }
            } else {
                if (temp->right != NULL) {
                    temp = temp->right;
                } else {
                    insertItem(temp, newItem);
                    return;
                }
            }
        }
    }
}



template<class ItemType>
int BST_312 <ItemType>::countNodes(TreeNode* t) const
{
    //YOUR CODE GOES HERE
    return numNodes;
}


template<class ItemType>
int BST_312 <ItemType>::countNodes()
{
    //YOUR CODE GOES HERE
    int numberNodes = countNodes(root);
    return numberNodes;
}

template<class ItemType>
void BST_312 <ItemType>::preOrderTraversal(TreeNode* t,vector<ItemType>& result) const
{
    //YOUR CODE GOES HERE
    //first add the data to the vector
    if(t != NULL){
        result.push_back(t->data);
    }
    //try to go left every time
    if(t->left != NULL){
        preOrderTraversal(t->left, result);
    }
    //after we tried to go left, try to go right
    if(t->right != NULL){
        preOrderTraversal(t->right, result);
    }
}


template<class ItemType>
vector<ItemType> BST_312 <ItemType>::preOrderTraversal()
{
    //YOUR CODE GOES HERE
    vector<ItemType> preOrder;
    TreeNode* temp1 = root;
    TreeNode* temp2 = NULL;
    //temp1 will be the original tree while temp2 will be the scratch tree
    copyTree(temp2, temp1);
    preOrderTraversal(temp2, preOrder);
    return preOrder;
}

template<class ItemType>
void BST_312 <ItemType>::inOrderTraversal(TreeNode* t,vector<ItemType>& result) const
{
    //YOUR CODE GOES HERE
    //first try to go left
    if(t->left != NULL){
        inOrderTraversal(t->left, result);
    }
    //after we can't go left add the data
    if(t != NULL){
        result.push_back(t->data);
    }
    //after we added the data, try to go right
    if(t->right != NULL){
        inOrderTraversal(t->right, result);
    }
}

template<class ItemType>
vector<ItemType> BST_312 <ItemType>::inOrderTraversal()
{
    //YOUR CODE GOES HERE
    vector<ItemType> inOrder;
    TreeNode* temp1 = root;
    TreeNode* temp2 = NULL;
    //temp1 will be the original tree while temp2 will be the scratch tree
    copyTree(temp2, temp1);
    inOrderTraversal(temp2, inOrder);
    return inOrder;
}

template<class ItemType>
void BST_312 <ItemType>::postOrderTraversal(TreeNode* t,vector<ItemType>& result) const
{
    //YOUR CODE GOES HERE
    //first try to go left
    if(t->left != NULL){
        postOrderTraversal(t->left, result);
    }
    //after we can't go left, try to go right
    if(t->right != NULL){
        postOrderTraversal(t->right, result);
    }
    //after we can't go right, add the data
    if(t != NULL){
        result.push_back(t->data);
    }
}

template<class ItemType>
vector<ItemType> BST_312 <ItemType>::postOrderTraversal()
{
    //YOUR CODE GOES HERE
    vector<ItemType> postOrder;
    TreeNode* temp1 = root;
    TreeNode* temp2 = NULL;
    //temp1 will be the original tree while temp2 will be the scratch tree
    copyTree(temp2, temp1);
    postOrderTraversal(temp2, postOrder);
    return postOrder;
}

template<class ItemType>
bool BST_312 <ItemType>::isItemInTree(const ItemType& item)
{
   //YOUR CODE GOES HERE
   TreeNode *temp = root;
   while(temp != NULL) {
      if (item.compare(temp) > 0) {
          temp = temp->left;
      } else if (item.compare(temp) < 0) {
          temp = temp->right;
      } else if (item.compare(temp) == 0) {
          return true;
      }
   }
   return false;
}
#endif

