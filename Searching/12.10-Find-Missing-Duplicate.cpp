#include <bits/stdc++.h>
using namespace std;

//Find missing number in an array of size n with elements from [0,n]
//XOR is commutative and associative 
//When a number is XORed with itself it is 0

int findMissing(vector<int> nums){
    int result=0, counter=0;
    for(int i=0;i<nums.size();i++){
        result^=counter^nums[i];
        counter++;
    }
    return counter^result;
}

//Find missing and duplicate numbers
//Harder variant of above problem
//Given an array of n integers b/w 0 and n-1
//Exactly one element appears twice, implying exactly one number between 0 and n-1 is missing

//Brute Force 1 : use a hash table to keep track of duplicae, for missing iterate over the hashmap and find the missing
//Time and Space : O(n)

//Brute Force 2 : sort then iterate, find duplicate and missing
//Time : O(nlogn) Space : O(1)


pair<int,int> findDuplicateAndMissing(vector<int> nums){
    return {};
}

int main(){
    cout << findMissing({3,0,1}) << endl;

    cout << findDuplicateAndMissing({}) << endl;



}