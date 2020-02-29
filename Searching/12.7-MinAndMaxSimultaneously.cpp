#include <bits/stdc++.h>
using namespace std;

//min requires n-1 comp
//max requires n-1 comp
//min+max = 2n-2 comparisions
//opimize by taking pairs 
//n/2-1 +n/2-1 = 3n/2-2 comaprisions

struct MinMax{
    int min,max;
};

MinMax findMinMax(vector<int>& arr){
    pair<int,int> global_minmax = minmax(arr[0],arr[1]);
    for(int i=2;i+1<arr.size();i+=2){   
        pair<int,int> local_minmax = minmax(arr[i],arr[i+1]);
        global_minmax = {min(local_minmax.first,global_minmax.first),max(local_minmax.second,global_minmax.second)};
    }
    //handle the odd edge case
    if(arr.size()%2) global_minmax = { min(global_minmax.first, arr.back()), max(global_minmax.second,arr.back()) };
    return {global_minmax.first, global_minmax.second};
}


int main(){

    vector<int> arr({10,9,3,1,6,22});
    MinMax ans = findMinMax(arr);
    cout << "min : " << ans.min << endl;
    cout << "max : " << ans.max << endl;
    
}