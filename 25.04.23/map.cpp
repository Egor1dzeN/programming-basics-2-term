#include <iostream>
#include<map>

using namespace std;
int find_value(map<int,int>& mp, int key){
    map<int,int>::iterator a;
    for(a = mp.begin(); a!=mp.end();++a){
        if(a->first == key){
            return a->second;
        }
    }
    return -1;
}
void test(){
    map<int,int> mp;
    mp[0] = 10;
    mp[1] = 11;
    mp[2] = 12;
    cout<<"Enter key: ";
    int key;
    cin>>key;
    int result = find_value(mp,key);
    if(result == -1)
        cout<<"not found value";
    else
        cout<<"value = "<<result;
}
int main() {
    test();
    return 0;
}
