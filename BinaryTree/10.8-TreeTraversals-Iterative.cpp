#include<bits/stdc++.h>
using namespace std;
struct BinaryTreeNode{
    int data;
    BinaryTreeNode *left, *right;
    
};

//iterative tree traversals using a stack

void inOrder(BinaryTreeNode *root){
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
            //right
            curr = curr->right;
        }
    }

}

void preOrder(BinaryTreeNode *root){
    stack<BinaryTreeNode*> s;
    s.push(root);
    while(!s.empty()){
        auto curr = s.top(); s.pop();
        if(curr){
            cout << curr->data << " ";
            s.push(curr->right);
            s.push(curr->left);
        }
    }
}

void postOrder(BinaryTreeNode *root){

}

int main(){
    
    BinaryTreeNode* root = new BinaryTreeNode();
    root->data = 5;
    root->left = new BinaryTreeNode();
    root->left->data = 3;
    root->right = new BinaryTreeNode();
    root->right->data = 1;
    root->left->left = new BinaryTreeNode();
    root->left->left->data = 2;
    root->left->right = new BinaryTreeNode();
    root->left->right->data = 7;

    inOrder(root);
    cout << endl;
    preOrder(root);
}