#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


void generate(vector<int>& arr,vector<vector<int>>& ans,vector<int>& temp,int i){
    ans.push_back(temp);
    for(int st = i; st<arr.size();++st){
        if(st > i && arr[st] == arr[st - 1]) continue;
        temp.push_back(arr[st]);
        generate(arr,ans,temp,st+1);
        temp.pop_back();
    }
}


vector<vector<int>> subsetSum(vector<int>& arr){
    vector<vector<int>> ans;
    vector<int> temp;
    int i = 0;
    sort(arr.begin(),arr.end());
    generate(arr,ans,temp,i);
    return ans;
}

int main() {
    vector<int> arr = {1,2,2};
    vector<vector<int>>ans = subsetSum(arr);
    for (auto it : ans)
    {
        for(auto it1 : it)
            cout<<it1<<" ";
        cout<<endl;
    }
    return 0;
}