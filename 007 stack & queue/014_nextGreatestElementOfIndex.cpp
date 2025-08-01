#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;
vector<int> find_next_greatest_element(const vector<int>& arr,const vector<int>& nums){
    stack<int> st;
    unordered_map<int,int> mpp;
    vector<int> ans;
    for(int i = arr.size()-1;i >= 0;--i){
        while(!st.empty() && st.top() <= arr[i]){
            st.pop();
        }
        if(st.empty()){
            mpp[arr[i]] = -1;
        }
        else{
            mpp[arr[i]] = st.top();
        }
        st.push(arr[i]);
    }
    for(auto it: nums){
        if(mpp.find(it) != mpp.end()){
            ans.push_back(mpp[it]);
        }
        else{
            ans.push_back(-1);
        }
    }
    return ans;
}

int main(){
    vector<int> arr = {3,10,4,2,1,2,6,1,7,2,9};
    vector<int> nums = {3,4,7};
    vector<int> ans = find_next_greatest_element(arr,nums);
    for(auto it : ans){
        cout<<it<<" ";
    }cout<<"\n";
    return 0;
}