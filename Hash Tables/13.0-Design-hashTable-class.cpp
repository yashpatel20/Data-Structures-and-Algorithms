#include <bits/stdc++.h>
using namespace std;

//understand how to create a class with a custom hash function

struct ContactList{
    vector<string> names;
    //overload == for resolving collisions when hashed
    bool operator==(const ContactList& that ) const{
        return unordered_set<string>(names.begin(),names.end()) == unordered_set<string>(that.names.begin(),that.names.end());
    }

};

//custom hash function
//overloded operator()
struct HashContactList{
    size_t operator()(const ContactList& contacts) const {
        size_t hashcode = 0;
        //generating hash for all unique strings
        for(const string& name : unordered_set<string>(contacts.names.begin(),contacts.names.end())){
            hashcode ^= hash<string>{}(name);
        }
        return hashcode;
    }
};

vector<ContactList> MergeContacts(const vector<ContactList>& contacts){
    unordered_set<ContactList,HashContactList> unique_contacts(contacts.begin(),contacts.end());
    return {unique_contacts.begin(),unique_contacts.end()};
}



int main(){

}