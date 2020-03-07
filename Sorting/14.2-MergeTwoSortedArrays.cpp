#include <bits/stdc++.h>
using namespace std;

void MergeTwoSortedArrays(vector<int>& v1, int m, vector<int>& v2, int n){
    int a = m-1, b = n-1;
    int total = v1.size()-1;
    for(int i = total ; i>=0; i--){
        if(v1[a] >= v2[b]) v1[i] = v1[a--];
        else v1[i] = v2[b--];
    }
}


int main(){
    vector<int> v1({5,13,17,-1,-1,-1,-1});
    vector<int> v2({3,7,11,19});
    MergeTwoSortedArrays(v1,3,v2,4);
    for(int i : v1) cout << i << " ";

}
