#include<bits/stdc++.h>
using namespace std;
struct BinaryTreeNode{
    int data;
    BinaryTreeNode *left, *right, *parent;
    
};

//1. find depth of node 0 and node 1, use parent pointers so space complexity is constant
//2. get diff of depth and make it so the iter with bigger depth is brought to the same level as the other iter
//3. Iterate using parents until both iterators are equal

int depth(BinaryTreeNode* node){
    int depth = 0;
    while(node->parent){
        depth++;
        node = node->parent;
    }
}

BinaryTreeNode* LCA_parentPointers(BinaryTreeNode* root, BinaryTreeNode* node0, BinaryTreeNode* node1){
    auto iter0 = node0, iter1 = node1;
    int node0_depth = depth(node0), node1_depth = depth(node1);
    int diff = abs(node0_depth - node1_depth);
    if(node1_depth>node0_depth) swap(iter0,iter1);
    while(diff--){
        iter0 = iter0->parent;
    }
    //now both iter at same level
    while(iter0!=iter1){
        iter0 = iter0->parent;
        iter1 = iter1->parent;
    }

    return iter0;


}



int main(){
    
}