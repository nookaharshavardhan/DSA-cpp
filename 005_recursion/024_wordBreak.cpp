#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
bool backTrack(unordered_set<string> & set,string s,int pos,unordered_map<int,bool> & mpp){
    if(pos == s.size()){
        return true;
    }
    if(mpp.count(pos))return mpp[pos];
    for(int i = pos; i < s.size();i++){
        string temp = s.substr(pos,i - pos + 1);
        if(set.count(temp) && backTrack(set,s,i+1,mpp))return mpp[pos] = true;
    }
    return mpp[pos] = false;
}

bool wordBreak(vector<string>& arr,string s){
    unordered_set<string> set(arr.begin(),arr.end());
    unordered_map<int,bool> memoize;
    return backTrack(set,s,0,memoize);
}

int main() {
    vector<string> arr = {"leet","code"};
    string s = "leetcodeleetcodecode";
    if(wordBreak(arr,s)){
        cout<<"true"<<endl;
    }
    else cout<<"false"<<endl;
    return 0;
}
