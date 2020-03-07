#include <bits/stdc++.h>
using namespace std;
//<<Yash,Patel>,<Samip, Jani>,<Yash,Shah>,<Smit, Shah>> => <<Yash, Patel>,<Samip, Jani>,<Smit, Shah>>

//Method 1 : Use a set for first names, then iterate over it to get uniques
//Time : O(n) Space : O(n)

//Method 2 :  sort then run uniqu, unique only runs on consecutive thats why sort 
//Time : O(nlogn) Space : O(1)

struct Name{
    string firstName;
    string lastName;
};

void removeDuplicates(vector<Name>& arr){
    sort(arr.begin(),arr.end(),[](Name& a , Name& b){return a.firstName < b.firstName;});
    for(auto i : arr) for(string s : i) cout << s << " ";
    cout << endl;
    auto it = unique(arr.begin(),arr.end(),[](Name& a, Name& b){return a.firstName = b.firstName;});
    arr.resize(distance(arr.begin(), it));
}

int main(){
    vector<vector<string>> arr({Name({"Yash", "Patel"}),Name({"Smit", "Jani"}),Name({"Yash", "Shah"}),Name({"Samip", "Solanki"})});
    removeDuplicates(arr);
    for(auto i : arr) cout << i.firstName << " " << i.lastName <<endl;




}