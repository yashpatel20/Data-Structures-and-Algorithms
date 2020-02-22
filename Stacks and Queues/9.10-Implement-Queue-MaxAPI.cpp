#include <bits/stdc++.h>
using namespace std;

class Queue{
    private:
        queue<int> elements;
        deque<int> cacheMaxElements;
    public:
        bool Empty(){return elements.empty();}
        int Max(){
            if(cacheMaxElements.empty()) throw length_error("error");
            return cacheMaxElements.front();
        }

        void enqueue(int x){
            elements.push(x);
            //pop all those elements which are less than x
            while(!cacheMaxElements.empty()){
                if(cacheMaxElements.back() >=x) break;
                cacheMaxElements.pop_back();
            }
            cacheMaxElements.push_back(x);
        }

        int dequeue(){
            if(!elements.empty()) throw length_error("erroe");
            int res = elements.front();
            if(res = cacheMaxElements.front()){
                cacheMaxElements.pop_front();
            }
            elements.pop();
            return res;
        }        
};







int main(){

}