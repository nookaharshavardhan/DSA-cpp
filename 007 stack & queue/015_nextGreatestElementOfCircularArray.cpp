#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> find_next_greatest_element(const vector<int>& arr){
    stack<int> st;
    vector<int> ans(arr.size(),-1);
    for(int i = arr.size() - 1;i >= 0 ; --i){
        st.push(arr[i]);
    }
    for(int i = arr.size() - 1;i >= 0 ; --i){
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i] = st.top();
        }
        st.push(arr[i]);
    }
    return ans;
}


int main() {
    vector<int> arr ={5, 1, 2, 3, 4};
    vector<int> ans = find_next_greatest_element(arr);
    for(auto it : ans){
        cout<<it<<" ";
    }
    cout<<endl;
    return 0;
}