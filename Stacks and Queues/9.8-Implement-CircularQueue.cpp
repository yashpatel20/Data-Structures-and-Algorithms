#include <bits/stdc++.h>
using namespace std;

//circular queue


class Queue{
    private:
        size_t head =0, tail=0, numOfElements=0;
        vector<int> entries;

    public:
        //constructor
        //Note : understand modern c++
        explicit Queue(size_t capacity) : entries(capacity) {}

        void enqueue(int x){
            //check if we need to resize
            if(numOfElements == entries.size()){
                rotate(entries.begin(),entries.begin()+head, entries.end());
                head =0; tail=numOfElements;
                entries.resize(entries.size()*2);
            }
            entries[tail] = x;
            tail = (tail+1)%entries.size();
            ++numOfElements;
        }

        int dequeue(){
            if(!numOfElements) throw length_error("Error");
            numOfElements--;
            int ret = entries[head];
            head = (head+1)%entries.size();
            return ret;
        }

        size_t size(){return numOfElements;}
};

int main(){

}