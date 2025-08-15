#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> find_max_sliding_window(vector<int> arr,int k){
    deque<int> dq;
    vector<int> ans;
    for(int i = 0 ; i < arr.size(); ++i){
        if(!dq.empty() && dq.front() <= i - k)dq.pop_front();
        while(!dq.empty() && arr[dq.back()] < arr[i])dq.pop_back();
        dq.push_back(i);
        if(i >= k-1)ans.push_back(arr[dq.front()]);
    }
    return ans;
}

int main() {
    vector<int> arr = {4,0,-1,3,5,3,6,8};
    int wind_size = 3;
    vector<int> ans = find_max_sliding_window(arr,wind_size);
    for(auto it: ans){
        cout<<it<<" ";
    }cout<<endl;
    return 0;
}