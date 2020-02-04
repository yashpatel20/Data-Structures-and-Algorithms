#include <bits/stdc++.h>
using namespace std;

int bsearch(int t, const vector<int>& A){
    int L=0, R=A.size()-1;
    while(L<=R){
        int M = L+(R-L)/2;
        if(A[M] == t) return M;
        else if(A[M]>t) R=M-1;
        else L=M+1;
    }

    return -1;

}


int main(){

}