#include <bits/stdc++.h>
using namespace std;

//O(n) time complexity for build_heap : https://stackoverflow.com/questions/9755721/how-can-building-a-heap-be-on-time-complexity
//parent = (i-1)/2
//left  = 2*i+1
//right = 2*i+1

//sift down : O(logn)
void sift_down(vector<int>& arr, int i, int n){
    //get left and right 
    int left = arr[2*i+1];
    int right = arr[2*i+2];
    //check largest index and perform sift up
    int largest = i;
    if(left < n && arr[left] > arr[largest]) largest = left;
    if(right < n && arr[right] > arr[largest]) largest = right;
    if(largest!=i){
        swap(arr[i],arr[largest]);
        sift_down(arr, largest, n);
    }
}

//sift up : O(logn)
void sift_up(vector<int>& arr, int i, int n){
    //get parent 
    int parent = (i-1)/2;
    if(arr[i] > arr[parent] && parent < n){
        swap(arr[i],arr[parent]);
        sift_up(arr,parent,n);
    }
}

//build_heap with sift_down : O(n)
void build_heap(vector<int>& arr, int i, int n){
    for(int i=(n-2)/2; i>=0; i--) build_heap(arr,i,n);
}

//insert / push() : O(log n)
void insert(vector<int>& arr,int element){
    arr.push_back(element);
    swap(arr[0],arr[arr.size()-1]);
    //sift_down
    sift_down(arr, 0, arr.size());
}

//delete_max / pop() : O(log n)
void delete_max(vector<int>& arr, int n){
    swap(arr[0],arr[arr.size()-1]);
    n--;
    sift_down(arr, 0, n);
}


void heapSort(){
    
}


int main(){

    
}