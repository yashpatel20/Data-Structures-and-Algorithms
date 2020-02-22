#include<bits/stdc++.h>
using namespace std;
struct BinaryTreeNode{
    int data;
    BinaryTreeNode *left, *right;
    
};

struct Status{
    int numOfTargetNodes;
    BinaryTreeNode *ancestor;
};

Status dfs(BinaryTreeNode *root, BinaryTreeNode *node0, BinaryTreeNode *node1){
    if(root == nullptr) return {0,nullptr};
    auto left_result = dfs(root->left,node0,node1);
    if(left_result.numOfTargetNodes == 2) return left_result;
    auto right_result = dfs(root->right,node0,node1);
    if(right_result.numOfTargetNodes == 2) return right_result;

    int numOfTargetNodes = left_result.numOfTargetNodes + right_result.numOfTargetNodes + (root == node0) + (root ==node1);
    return {numOfTargetNodes, numOfTargetNodes == 2 ? root : nullptr};
}

BinaryTreeNode* LCA(BinaryTreeNode *root, BinaryTreeNode *node0, BinaryTreeNode *node1){
    return dfs(root,node0,node1).ancestor;
}


int main(){
    BinaryTreeNode* root = new BinaryTreeNode();
    root->data = 123;
    root->left = new BinaryTreeNode();
    root->left->data = 111;
    root->left->left = new BinaryTreeNode();
    root->right = new BinaryTreeNode();
    cout << LCA(root,root->left,root->left->left)->data;

}