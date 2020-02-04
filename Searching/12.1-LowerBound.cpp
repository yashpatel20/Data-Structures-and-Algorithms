#include <bits/stdc++.h>
using namespace std;

int lower_bound(int t, const vector<int>& A){
    int L=0, R=A.size()-1;
    int ans;
    while(L<=R){
        int M = L+(R-L)/2;
        if(A[M]>=t){
            ans=M;
            R=M-1;
        }else{
            L=M+1;
        }
    }
    return ans;

}

int upper_bound(int t, const vector<int>& A){
    int L=0, R=A.size()-1;
    int ans;
    while(L<=R){
        int M = L+(R-L)/2;
        if(A[M]>t){
            ans=M;
            R=M-1;
        }else{
            L=M+1;
        }
    }
    return ans;

}


int main(){

}