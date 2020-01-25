#include<bits/stdc++.h>
using namespace std;
struct BinaryTreeNode{
    int data;
    BinaryTreeNode *left, *right;
    
};

//same as path sum 1 
//return a vector<vector<int>> with all the pathsum == k
//backtracking / complete search
void dfs(BinaryTreeNode *root, int sum , vector<vector<int>>& res, vector<int>& temp){
    if(!root) return;
    temp.push_back(root->data);
    //leaf
    if(!(root->left) && !(root->right) && sum==root->data) res.push_back(temp);
    //non leaf
    dfs(root->left,sum-(root->data),res,temp);
    dfs(root->right,sum-(root->data),res,temp);
    temp.pop_back();
}

vector<vector<int>> pathSum2(BinaryTreeNode *root, int sum){
    vector<vector<int>> res;
    vector<int> temp;
    dfs(root, sum , res, temp);
    return res;
}


int main(){
    BinaryTreeNode* root = new BinaryTreeNode();
    root->data = 5;
    root->left = new BinaryTreeNode();
    root->left->data = 5;
    root->right = new BinaryTreeNode();
    root->right->data = 1;
    root->left->left = new BinaryTreeNode();
    root->left->left->data = 5;
    root->left->right = new BinaryTreeNode();
    root->left->right->data = 5;   

    auto v = pathSum2(root,15);
    for(auto i : v){
        for(auto j : i) cout << j << " ";
        cout << endl;
    }

}