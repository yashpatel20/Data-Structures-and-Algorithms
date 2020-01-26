#include <bits/stdc++.h>
using namespace std;

//use a min heap
//push all the first elements of the arrays in
//pop and push the next element from that same array
//hence keep track curr and end iterators
//use end to check if the array does not have any elements remaining to push
//use opertor overloading
//time : o(nlogk)

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


int main(){
    vector<vector<int>> v{{1,4,10},{2,3,6},{8,11,20}};
    auto arr = mergeKSortedArrs(v);
    for(auto i:arr) cout << i <<" ";

}