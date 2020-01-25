#include<bits/stdc++.h>
using namespace std;
struct BinaryTreeNode{
    int data;
    BinaryTreeNode *left, *right;
    int size;    
};
//Find k smallest element in a bst can be done using iterative inorder
BinaryTreeNode* inOrder(BinaryTreeNode *root, int k){
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
            if(k--) return curr;
            //right
            curr = curr->right;
        }
    }

}

//O(n) vs O(h)
//useful when n >> h

//better best case
//assume each node stores the number of nodes in the subtree rooted at that node
//O(h) time complexity
BinaryTreeNode* kthNode(BinaryTreeNode *root, int k){
    auto iter = root;
    while(!iter){
        int left_size = iter->left ? iter->left->size : 0;
        if(left_size+1<k){ //must be in right subtree
            //if in right subtract left_size from k
            k-=left_size;
            iter = iter->right;
        }else if(left_size == k-1){ //root is the kth element
            return root;
        }else{ //left_size > k then left
            iter = iter->left;
        }
    }
    return nullptr;
}

int main(){
    
}