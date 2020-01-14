#include <bits/stdc++.h>
using namespace std;
//queue can be implemented using two stacks
//enq stack and deq stack
//whenever deq is empty pop from enq and push to deq


class Queue{
    private: 
        stack<int> enq,deq;
    public:
        void enqueue(int x){
            enq.push(x);
        }
        int dequeue(){
            if(deq.empty()){
                //pop all elemets from enq;
                while(!enq.empty()){
                    int x = enq.top();
                    deq.push(x);
                    enq.pop();
                }
            }
            if(deq.empty()) throw length_error("error");
            int ret = deq.top();
            deq.pop();
            return ret;
        }
};


int main(){
    
}