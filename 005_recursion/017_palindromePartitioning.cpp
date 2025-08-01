#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPalindrome(int st ,int end,const string& s){
    while(st < end){
        if(s[st++] != s[end--]){
            return false;
        }
    }
    return true;
}

void generate(vector<vector<string>> & ans,vector<string>& temp,const string& s,int i){
    if(i == s.size()){
        ans.push_back(temp);
        return;
    }
    for(int st = i; st < s.size();++st){
        if(isPalindrome(i,st,s)){
            temp.push_back(s.substr(i,st-i+1));
            generate(ans,temp,s,st+1);
            temp.pop_back();
        }
    }
}

vector<vector<string>>  partition(string s){
    vector<vector<string>> ans;
    vector<string> temp;
    int i= 0;
    generate(ans,temp,s,i);
    return ans;
}

int main() {
    string s = "aabb";
    vector<vector<string>> ans = partition(s);
    for(auto it : ans){
        for(auto it1 : it){
            cout<<it1<<" ";
        }cout<<endl;
    } 
    if(isPalindrome(0,1,s)){
        cout<<"yes it is a palindrome"<<endl;
    }
    return 0;
}