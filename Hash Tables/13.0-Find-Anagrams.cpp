#include <bits/stdc++.h>
using namespace std;

//Given a vector of strings, find all the anagrams
//Anagrams same words after sorting
//Use hashmap to keep track of repeating strings
//TC : O(nmlogm) SC : O(n)

vector<vector<string>> findAnagrams(const vector<string>& anagrams){
    vector<vector<string>> result;
    //insert everything into unordered map
    unordered_map<string,vector<string>> hashMap;
    for(const string& str : anagrams){
        //sort the string then insert
        string sorted_str(str);
        sort(sorted_str.begin(),sorted_str.end());
        hashMap[sorted_str].push_back(str);
    }

    //iterate over hashMap and insert all strings with count >1
    //when you iterate over hashmap use first , second
    for(auto map : hashMap){
        if(map.second.size() > 1) result.push_back(map.second);
    }

    return result;

}

int main(){
    vector<string> anagrams({"debitcard","elvis","silent","badcredit","lives","freedom","listen","levis","money"});
    auto arr = findAnagrams(anagrams);
    for(auto i:arr){
        for(auto j:i) cout << j << " ";
        cout << endl;
    }



}