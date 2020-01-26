#include<bits/stdc++.h>
using namespace std;

//First way Max height is logn
//Build max_heap with all strings : O(n)
//then do k pops 
//Time : O(nlogn)

//Second Way Max height of heap is logk
//Use min_heap insert first k elements into heap
//then for every element inserted after k pop the min element
//Do for all strings, then pop out all k elements from heap
//Time : O(nlogk)

vector<string> getKLongestStrings(string s, int k){
    stringstream ss(s);
    string next_string;
    priority_queue<string,vector<string>,function<bool(string, string)>> 
        min_heap([](const string& a, const string& b){return a.size() >= b.size();});
    while(ss >> next_string){
        min_heap.push(next_string);
        if(min_heap.size() > k){
            min_heap.pop();
        }
    }
    vector<string> res;
    while(!min_heap.empty()){
        res.push_back(min_heap.top());
        min_heap.pop();
    }

    return res;
}



int main(){
    string s = "a aa aaa aaaa aaaaa aaaaaa";
    vector<string> strings = getKLongestStrings(s,3);
    for(auto s : strings) cout << s << " ";
}