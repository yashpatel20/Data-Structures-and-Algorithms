#include <bits/stdc++.h>
using namespace std;

//cyclically sorted array : take a sorted array and rotate it <378, 478, 550, 631, 103, 203, 220, 234, 279, 368>
//Two questions 

//Search the pivot element or the smallest element in the array
//comapre middle with the last element

int searchPivot(const vector<int>& A){
    int L=0, R=A.size()-1;
    int ans;
    while(L<=R){
        int M = L+(R-L)/2;
        if(A[M] <= A[A.size()-1]){
            ans=M;
            R=M-1;
        }else{
            L=M+1;
        }
    }
    return ans;

}

//search pivot with duplicates

int searchPivotDuplicates(vector<int> A){
    int L=0, R=A.size()-1;
    int ans;
    while(L<=R){
        int M = L+(R-L)/2;
        if(A[M]<A[A.size()-1]){
            ans=M;
            R=M-1;
        }else if(A[M]==A[A.size()-1]) A.pop_back();
        else L=M+1;
    }
    return ans;

}

//search for a target in a rotated array
//<378, 478, 550, 631, 103, 203, 220, 234, 279, 368>



int main(){
    cout << searchPivotDuplicates(vector<int>{10,10, 1, 2 ,10}) << endl;

}