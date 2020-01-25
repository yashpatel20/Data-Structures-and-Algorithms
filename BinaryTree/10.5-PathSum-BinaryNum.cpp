#include<bits/stdc++.h>
using namespace std;
struct BinaryTreeNode{
    int data;
    BinaryTreeNode *left, *right;
    
};

//actual solution
int dfs(BinaryTreeNode* root, int path_sum){
    if(root==nullptr) return 0;
    path_sum = path_sum*2 + root->data;
    //leaf 
    if(root->left == nullptr && root->right == nullptr) return path_sum;
    //non leaf
    return dfs(root->left, path_sum)  + dfs(root->right,path_sum);
}


int PathSum_BinaryNum(BinaryTreeNode* root){
    return dfs(root, 0);
}

//experimental backtracking solution

void backtrack(BinaryTreeNode* root,vector<vector<int>>& res, vector<int>& partial_res){
    if(root==nullptr) return;
    partial_res.push_back(root->data);
    //leaf node
    if(root->left == nullptr && root->right == nullptr) res.push_back(partial_res);
    backtrack(root->left, res, partial_res);
    backtrack(root->right, res, partial_res);
    partial_res.pop_back();
}


int PathSum_BinaryNum_Backtracking(BinaryTreeNode* root){
    vector<vector<int>>  res;
    vector<int> partial_res;
    backtrack(root, res, partial_res);
    int sum=0;
    for(auto v : res){
        int partial_sum = 0;
        for(auto i : v) partial_sum = partial_sum*2 + i;
        sum+=partial_sum;

    }
    return sum;
}

int main(){
    BinaryTreeNode* root = new BinaryTreeNode();
    root->data = 1;
    root->left = new BinaryTreeNode();
    root->left->data = 0;
    root->right = new BinaryTreeNode();
    root->right->data = 1;
    root->left->left = new BinaryTreeNode();
    root->left->left->data = 1;
    root->left->right = new BinaryTreeNode();
    root->left->right->data = 0;

    cout << PathSum_BinaryNum(root) << endl;
    cout << PathSum_BinaryNum_Backtracking(root) << endl;

    
}