#include <bits/stdc++.h>
using namespace std;

//brute way push O(1) pop O(n)
//cache the max at every push, O(1) time O(n) space
class Stack1{
    private:
        struct ElementWithCachedMax{
            int element,max;
        };
        stack<ElementWithCachedMax> ss;

    public:
        bool Empty(){return ss.empty();}
        int Max(){
            if(!Empty()) return ss.top().max;
            else throw length_error("Error");
        }
        void push(int x){
            ss.push(ElementWithCachedMax{x,max(x,Empty()?x:Max())});
        }
        int pop(){
            if(Empty()) throw length_error("Error");
            int pop_element = ss.top().element;
            ss.pop();
            return pop_element;
        }

};

//use another stack to store max, improve the best case space complexity
class Stack2{
    private:
        stack<int> elements;
        stack<pair<int,int>> maxElements;
    public:
        bool Empty(){return elements.empty();}
        int Max(){
            if(Empty()) throw length_error("Error");
            return maxElements.top().first;
        }
        void push(int x){
            elements.push(x);
            if(maxElements.empty()){
                maxElements.push(make_pair(x,1));
            }else{
                if(x>Max()) maxElements.push(make_pair(x,1));
                else if(x==Max()) maxElements.top().second++;
            }
        }
        int pop(){
            if(Empty()) throw length_error("error");
            int pop_element = elements.top();
            elements.pop();
            if(pop_element == Max()){
                int& maxFreq = maxElements.top().second;
                maxFreq--;
                if(maxFreq==0) maxElements.pop();
            }
            return pop_element;
        }
};

int main(){
    
    
}