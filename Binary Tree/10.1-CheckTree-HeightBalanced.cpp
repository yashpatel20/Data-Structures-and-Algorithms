#include<bits/stdc++.h>
using namespace std;
struct BinaryTreeNode{
    int data;
    BinaryTreeNode *left, *right;
};

//two ways : multiple pass : O(n*n) and single pass : O(n)
int dfs1(BinaryTreeNode *root){
    if(root==NULL) return -1;
    return max(dfs1(root->left),dfs1(root->right))+1;
}

//O(n^2)
bool multiplePass(BinaryTreeNode *root){
    if(root == NULL) return true;
    //check left and right subtree
    int left = dfs1(root->left);
    int right = dfs1(root->right);
    return abs(left -right) <=1 && multiplePass(root->left) && multiplePass(root->right);
}


//O(n) : time and O(h): space

struct BalancedWithHeight{
    bool balanced;
    int height;
};
BalancedWithHeight dfs2(BinaryTreeNode *root){
    //check root
    if(root == nullptr) return {true,-1};
    //check leftsubtree
    auto left_balanced = dfs2(root->left);
    if(!left_balanced.balanced) return {false,0};
    //check right subtree
    auto right_balanced = dfs2(root->right);
    if(!right_balanced.balanced) return {false,0};
    //return 
    bool is_balanced = abs(left_balanced.height - right_balanced.height) <=1;
    int height = max(left_balanced.height,right_balanced.height)+1;
    return {is_balanced,height};
}

bool singlePass(BinaryTreeNode *root){
    return dfs2(root).balanced;
}




int main(){
    BinaryTreeNode* root = new BinaryTreeNode();
    root->left = new BinaryTreeNode();
    root->right = new BinaryTreeNode();
    root->left->left = new BinaryTreeNode();
    //root->left->left->left = new BinaryTreeNode();
    cout << singlePass(root);

}