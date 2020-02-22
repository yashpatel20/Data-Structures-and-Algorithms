#include<bits/stdc++.h>
using namespace std;
//Check if string is well formed 
//()[] :  well , (]]) : not well
//use a stack to push all open, whenever a closed is encountered check if top is open same bracket

bool isWellFormed(string s){
    stack<char> Stack;
    for(int i=0;i<s.length();i++){
        if(s[i]=='('||s[i]=='['||s[i=='{']){
            Stack.push(s[i]);
        }else{
            if(Stack.empty()) return false;
            if(s[i]==')' && Stack.top()!='(' ||s[i]==']' && Stack.top()!='[' ||s[i]=='}' && Stack.top()!='{') return false;
        }
        Stack.pop();
    }
    return Stack.empty();
}

int main(){

}