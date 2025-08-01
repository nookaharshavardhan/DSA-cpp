#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

void generate(vector<string>& ans,string& temp,const string digits,int i,const unordered_map<char,string>& mp){
    if(temp.length() == digits.length()){
        ans.push_back(temp);
        return ;
    }
    string current = mp.at(digits[i]);
    for(int st =0; st < current.length(); st++){
        temp.push_back(current[st]);
        generate(ans,temp,digits,i+1,mp);
        temp.pop_back();
    }
}

vector<string> letterCombinationsOfPhone(string digits){
    vector<string> ans;
    string temp;
    unordered_map<char,string> mp = {
        {'2', "abc"}, {'3', "def"},
        {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"},
        {'8', "tuv"}, {'9', "wxyz"}
    };
    generate(ans,temp,digits,0,mp);
    return ans;
}

int main() {
    string digits = "23";
    vector<string> ans = letterCombinationsOfPhone(digits);
    for(auto it : ans){
        for(auto it1 : it){
            cout<<it1<<" ";
        }cout<<endl;
    }
    return 0;
}
