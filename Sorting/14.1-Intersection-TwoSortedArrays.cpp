#include <bits/stdc++.h>
using namespace std;
//intersection of two sorted arrays
vector<int> IntersectionTwoSortedArrays(vector<int> v1, vector<int> v2){
    int i = 0, j=0;
    vector<int> res;
    while(i < v1.size() and j < v2.size()){
        if(v1[i] == v2[j] and ((i==0) || v1[i] != v1[i-1] or v2[i] != v2[i-1])){
            res.push_back(v1[i]);
            i++; j++;
        }else if(v1[i] < v2[j]) i++;
        else j++; 
    }
    return res;

}

int main(){
    auto nums = IntersectionTwoSortedArrays({2,3,3,5,5,6,7,8,12},{5,5,6,8,8,9,10,10});
    for(int i : nums) cout << i << " ";

}