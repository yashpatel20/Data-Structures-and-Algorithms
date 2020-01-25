#include<bits/stdc++.h>
using namespace std;
struct BinaryTreeNode{
    int data;
    BinaryTreeNode *left, *right ,*parent; 
};

//kth smallest elem and successor are mostly bst questions so inorder
BinaryTreeNode* successor(BinaryTreeNode *root, BinaryTreeNode *node){
    //inorder traversal
    stack<BinaryTreeNode*> s;
    auto curr = root;
    while(curr || !s.empty()){
        //keep moving left till it is not null
        if(curr){
            s.push(curr);
            curr = curr->left;
        }else{
            //up
            curr = s.top(); s.pop();
            cout << curr->data << " ";
            if(curr == node){
                return s.top();
            }
            //right
            curr = curr->right;
        }
    }
}

BinaryTreeNode* successor_ParentPointers(BinaryTreeNode* node){
    auto iter = node;
    if(!(iter->right)){
        //successor is the leftmost element in the right subtree
        iter = iter->right;
        while(iter->left) iter = iter->left;
        return iter;
    }
    //Find the closest anacestor whose left subtree contains node
    while(iter!=nullptr && iter->parent->right==iter) iter = iter->parent;
    return iter;
}

int main(){
    
}