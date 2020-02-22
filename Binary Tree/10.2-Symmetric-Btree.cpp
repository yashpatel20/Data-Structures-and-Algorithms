#include<bits/stdc++.h>
using namespace std;
struct BinaryTreeNode{
    int data;
    BinaryTreeNode *left, *right;
    
};

bool dfs(BinaryTreeNode *subtree0, BinaryTreeNode *subtree1){
    if(subtree0 == nullptr && subtree1 == nullptr) return true;
    else if(subtree0!=nullptr && subtree1!=nullptr){
        return subtree0->data == subtree1->data && dfs(subtree0->right,subtree1->left) && dfs(subtree0->left,subtree1->right);
    }
    //only one is null
    return false;
}

bool isSymmetric(BinaryTreeNode *root){
    return root == nullptr || dfs(root->left,root->right);
}

int main(){
    BinaryTreeNode *root = new BinaryTreeNode();
    root->data = 1;
    root->right = new BinaryTreeNode();
    root->left = new BinaryTreeNode();
    root->left->data = 2;
    root->right->data =2;
    root->left->right = new BinaryTreeNode();
    root->left->right->data = 3;
    root->right->left = new BinaryTreeNode();
    root->right->left->data =2;
    cout << isSymmetric(root);

}