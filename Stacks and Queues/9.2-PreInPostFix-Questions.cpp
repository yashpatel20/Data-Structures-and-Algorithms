#include <bits/stdc++.h>
using namespace std;

//Postfix or prefix are used to compute as they are faster than infix
//infix A op B
//prefix op A B
//postfix A B op

//Evaluate RPN expressions 
//postfix :  "3,4,+,2,*,1,+"

int evalPostfix(string s){
    //splice the string with getline then use stack, push operands and pop and evaluate whenever we get a operator
    stack<int> Stack;
    stringstream ss(s);
    string token;
    while(getline(ss,token,',')){
        if(token =="+" || token =="-" || token="*" || token=="/"){
            //pop two operands
            int A = Stack.top(); Stack.pop();
            int B = Stack.top(); Stack.pop();
            switch (token.front())
            {
            case '+': Stack.push(A+B);
                break;
            case '-': Stack.push(A-B);
                break;
            case '*': Stack.push(A*B);
                break;
            case '/': Stack.push(A/B);
                break;
            }
        }else{ //token is a number 
            Stack.push(stoi(token));
        }

    }

    return Stack.top();

}
//preffix : 

int evalPrefix(string s){
    //evaluate from the back 
    //first operand is B
    //second operand is A

    stack<int> Stack;
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i=='/']){
            int B = Stack.top(); Stack.pop();
            int A = Stack.top(); Stack.pop();
            switch (s[i])
            {
            case '+': Stack.push(A+B);
                break;
            case '-': Stack.push(A-B);
                break;
            case '*': Stack.push(A*B);
                break;
            case '/': Stack.push(A/B);
                break;
            }

            
        }
        else{//number
            Stack.push(s[i]-'a');
        }
    }

    return Stack.top();

}
//Convert infix to postfix












int main(){


    
}