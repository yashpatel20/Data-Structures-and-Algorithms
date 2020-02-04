#include <bits/stdc++.h>
using namespace std;

//Q : search a sorted array for entry equal to its index A[i] = i
//only need to search one element
//search for 0 in the arr A[i]-i

int search(const vector<int>& A){
    int L=0, R=A.size()-1;
    while(L<=R){
        int M = L+(R-L)/2;
        if(A[M] == M){
            return M;
        }else if(A[M] > M) R=M-1;
        else L=M+1;
    }
    return -1;
}


int  main(){
    cout << search({-2,0,2,6,7,9}) << endl;

}