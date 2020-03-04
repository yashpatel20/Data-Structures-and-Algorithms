#include <bits/stdc++.h>
using namespace std;
//determine if it is possible to write a letter using magazine
//use a hash table to store letter
//iterate over magazine and check for letter
//if hashtable is empty then possible, else not possible

//TC : O(n+m) SC : O(n)

bool IsLetterConstructibleFromMagazine(const string& letter, const string& magazine){
    unordered_map<char,int> hashmap;
    for(auto c : letter) hashmap[c]++;
    for(auto c : magazine){
        //find c in hashmap of letter
        if(hashmap.count(c)){
            hashmap[c]--;
            //check if 0
            if(hashmap[c]==0) hashmap.erase(c);
            //check is hashmap is empty
            if(hashmap.empty()) break;
        } 
    }
    
    return hashmap.empty();
}


int main(){
    cout << IsLetterConstructibleFromMagazine("aabcd","abcd") <<  endl;
}