#include <bits/stdc++.h>
using namespace std;

//square root

int SquareRoot(int X){
    int L=1, R=X;
    int ans;
    while(L<=R){
        int M = L+(R-L)/2;
        if(M<= X/M){
            ans=M;
            L=M+1;
        }else{
            R=M-1;
        }
    }
    return ans;
}


//pow(x,y)

int pow(){

}


int main(){
    cout << searchSquareRoot(16)<< endl;
}