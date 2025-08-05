#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

string remove_k_elements(const string& num,int k){
    if(k == 0)return num;
    if(k == num.size())return "0";
    stack<char> st;
    for(int i = 0; i < num.size(); ++i){
        while( !st.empty() && st.top() > num[i]  && k > 0){
           st.pop();
           k--;
        }
        st.push(num[i]);
    }
    while(!st.empty() && k > 0){
        st.pop();
        k--;
    }

    string ans = string("");
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    while(!ans.empty() && ans.back() == '0')ans.pop_back();
    if(ans.empty())return "0";
    reverse(ans.begin(),ans.end());
    return ans;
}

int main() {
    string num = "002001";
    int k = 1;
    string num_after_rmv = remove_k_elements(num,k);
    cout<<num_after_rmv<<"\n";
    return 0;
}