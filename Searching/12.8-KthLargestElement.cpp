#include <bits/stdc++.h>
using namespace std;

//Find the kth largest element in an unsorted array
//multiple ways

//Brute force : 
//sort the array and find kth 
//Time : O(nlogn)

//Using Heap
//Use a min heap of size k 
//Time : O(nlogk) n element are inserted in a heap of size k
//Space : O(k)

int findKthUsingHeap(vector<int> array, int k){
    priority_queue<int> minheap;
    //push all elements in the min heap
    for(int i : array){
        minheap.push(-i);
        if(minheap.size() > k) minheap.pop();
    }
    return abs(minheap.top());

}

//Using quickSelect or just using partition of quicSort
//Time :  average(n) worst(n*n)

int partition(vector<int>& array, int left, int right, int pivot_idx){
    int pivot_val = array[pivot_idx];
    swap(array[pivot_idx],array[right]);
    int new_pivot_idx = left;
    for(int i=left;i<right;i++){
        if(array[i] > pivot_val) swap(array[i],array[new_pivot_idx++]);
    }
    swap(array[new_pivot_idx],array[right]);
    return new_pivot_idx;
}


int findKthUsingQuicKSelect(vector<int>& array, int k){
    //parition 
    int left=0, right=array.size()-1;
    default_random_engine gen((random_device())());
    while(left<=right){
        //generate random number
        int pivot_idx = uniform_int_distribution<int>{left,right}(gen);
        int new_pivot_idx = partition(array, left, right, pivot_idx);
        if(new_pivot_idx == k-1) return array[new_pivot_idx];
        else if(new_pivot_idx > k-1) right = new_pivot_idx-1;
        else left = new_pivot_idx+1;
    }
}



int main(){
    vector<int> array({3,2,5,1,7,8,4,6,10,9});
    int k=3;
    cout << findKthUsingHeap(array,k) <<endl;
    cout << findKthUsingQuicKSelect(array,k) <<endl;

}