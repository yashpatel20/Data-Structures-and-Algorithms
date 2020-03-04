#include <bits/stdc++.h>
using namespace std;

//ISBN cache or Least recently used cache
//lookup, insert and delete
//When inserting, if cache is full delete the least recently used isbn entry

//Only using hash table
//Lookup : O(1) delete : O(n) insert : O(n) when size of cache is full, finding least rec used entry will take O(n) time

//Lazy garbage collection
//Amortized insert TC : O(1) as every 2n operations, deletion will take place O(n)
//drawbacks : O(n) for some lookups as n elements are left out of cache and O(n) inc in space comp

//Hashtable with queue(linked list)
//Queue keeps track of least rec used elems
//lookup updates lru parameter and moves to front of queue O(1)
//delete removes last entry of queue so O(1)
//insert as delete is O(1), insert is also O(1)

class LRUcache{
    private : 
        //isbn number is key for pair (list<int> iterator, price)
        typedef unordered_map<int, pair<list<int>::iterator,int>> Table;
        Table price_table;
        list<int> lru;
        int capacity;

    public :
        //if exists , move node to front and return  
        int LookUp(int isbn){
            if(price_table.count(isbn)){
                lru.splice(lru.begin(),lru,price_table[isbn].first);
                return price_table[isbn].second;
            }
            return -1;
        }

        //if exists then just update lru list
        //else if price_table is full, delete isbn of lru last node
        //if table not full then insert and add node to front
        void insert(int isbn, int price){
            if(price_table.count[isbn]) lru.splice(lru.begin(),lru,price_table[isbn].first);
            else {
                if(price_table.size()==capacity){
                    //delete last elem from list
                    Erase(lru.back());
                    lru.pop_back();
                }
                    lru.push_front(isbn);
                    price_table.insert({isbn,{lru.begin(),price}});
            }
        }

        bool Erase(int isbn){
            if(!price_table.count(isbn)) return false;
            lru.erase(price_table[isbn].first);
            price_table.erase(isbn);
            return true;
        }

};

int main(){

}