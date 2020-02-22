#include<bits/stdc++.h>
using namespace std;
struct BinaryTreeNode{
    int data;
    BinaryTreeNode *left, *right;
    
};

//Find root to lead path with specified sum

bool dfs(BinaryTreeNode *root, int sum){
    if(!root) return 0;
    //leaf 
    if(!(root->left) && !(root->right) && sum == root->data) return true;
    //non leaf
    return dfs(root->left, sum-(root->data)) || dfs(root->right,sum-(root->data));
}

bool pathSum1(BinaryTreeNode *root , int sum){
    return dfs(root, sum);
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

    cout << pathSum1(root,15) << endl;
    
}