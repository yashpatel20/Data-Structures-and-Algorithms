#include <bits/stdc++.h>
using namespace std;

//Check if string is a palindrome

//two pointers method 
//TC : O(n) SC : O(1)

bool checkPalindrome(const string& s){
    int i=0, j=s.size()-1;
    while(i<j){
        if(s[i++]!=s[j--]) return false;
    }
    return true;
}


int main(){
    cout << checkPalindrome("racecar");
}