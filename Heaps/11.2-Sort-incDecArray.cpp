#include<bits/stdc++.h>
using namespace std;

//split inc and dec arrays and store all in a 2d array with all vectors increasing
//then run mergeKsortedArr()
//time : O(nlogk)  

struct IteratorCurrEnd{
    //opertor overloading for comapare min_heap
    bool operator>(const IteratorCurrEnd& that)const{
        return *curr > *that.curr;
    }

    vector<int>::iterator curr;
    vector<int>::iterator end;
    
};


vector<int> mergeKSortedArrs(vector<vector<int>>& sorted_arrays){
    priority_queue<IteratorCurrEnd,vector<IteratorCurrEnd>,greater<>> min_heap;
    //add first elements of every sorted arr
    //auto& take it as reference or by value will cause problems
    for(auto& sorted_arr : sorted_arrays){
        if(!sorted_arr.empty()) min_heap.push(IteratorCurrEnd{sorted_arr.begin(),sorted_arr.end()});
    }

    vector<int> result;
    while(!min_heap.empty()){
        auto smallest_array = min_heap.top();
        min_heap.pop();
        //push the next element from that array
        if(smallest_array.curr!=smallest_array.end){
            result.push_back(*smallest_array.curr);
            min_heap.push(IteratorCurrEnd{next(smallest_array.curr),smallest_array.end});
        }
    }
    return result;
}


vector<int> sortKIncDecArr(vector<int>& A){
    vector<vector<int>> v;
    for(int i=0;i<A.size();){
        vector<int> temp;
        if(A[i]){
            while(A[i+1]>A[i] && i+1<A.size()){
                temp.push_back(A[i]);
                i++;
            }
        }else{
            while(A[i]>=A[i+1]&&i+1<A.size()){
                temp.push_back(A[i]);
                i++;
            }
            reverse(temp.begin(),temp.end());
        }
        v.push_back(temp);
    }
    return mergeKSortedArrs(v);
}


int main(){
    vector<int> v{1,10,20,}

}