#include<bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s) {
    string ans;
    int n = s.size();
    if(n == 0) return "";
    int index,lst_index;
    int totl_sum = 0;
    for(int i = 0; i < n; i++){
        if(totl_sum == 0 && s[i] == '(') index = i + 1;
        if(s[i] == '(') totl_sum++;
        else if(s[i] == ')')totl_sum--;
        if(totl_sum == 0 && s[i] == ')'){
            ans+= s.substr(index,i - index);
        }
    }
    return ans;
}

string removeOuterParentheses1(string s) {
    string ans;
    int n = s.size();
    if(n== 0)return "";
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            if(cnt > 0) ans += '(';
            cnt++;
        }
        else if(s[i] == ')'){
            cnt--;
            if(cnt > 0) ans += ')';
        }
    }
    return ans;
}
int main()
{
    string s = "(()())(())()(((())))";
    string ans = removeOuterParentheses1(s);
    for(auto it : ans){
        cout<<it<<" ";
    }cout<<endl;
    return 0;
}