#include<bits/stdc++.h>
using namespace std;
template <typename T>
struct BinaryTreeNode{
    T data;
    unique_ptr<BinaryTreeNode<T>> left, right;
};

//Preorder traversal
void preOrder(const unique_ptr<BinaryTreeNode<int>>& root){
    if(root){
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(const unique_ptr<BinaryTreeNode<int>>& root){
    if(root){
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

void postOrder(const unique_ptr<BinaryTreeNode<int>>& root){
    if(root){
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }
}

//unique ptr error
//logic is fine
void bfs(const unique_ptr<BinaryTreeNode<int>>& root){
    if(root == NULL) return;
    queue<unique_ptr<BinaryTreeNode<int>>> q;
    q.push(root);
    while(!q.empty()){
        unique_ptr<BinaryTreeNode<int>> node = q.front();q.pop();
        cout << node->data << " ";
        if(node->left!=NULL) q.push(node->left);
        if(node->right!=NULL) q.push(node->right);
    }
}


int main(){
    unique_ptr<BinaryTreeNode<int>> root = make_unique<BinaryTreeNode<int>>();
    root->data = 2;
    root->left = make_unique<BinaryTreeNode<int>>();
    root->left->data = 1;
    root->right = make_unique<BinaryTreeNode<int>>();
    root->right->data =3;
    preOrder(root);
    cout <<endl;
    inOrder(root);
    cout <<endl;
    postOrder(root);
    cout <<endl;
    bfs(root);
}