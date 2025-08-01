#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generate(vector<vector<int>>& ans, vector<int> arr,vector<int> temp,int i,int sum,int k){
    if(i == arr.size()){
        if(sum == k)ans.push_back(temp);
        return;
    }
    temp.push_back(arr[i]);
    generate(ans,arr,temp,i+1,sum+arr[i],k);
    temp.pop_back();
    generate(ans,arr,temp,i+1,sum,k);
}

vector<vector<int>> subsequenceOfSumK(vector<int> arr,int k){
    vector<vector<int>> ans;
    vector<int> temp;
    generate(ans,arr,temp,0,0,k);
    return ans;
}

int main() {
    vector<int> arr = {10,1,2,7,6,5};      // to make it work for duplicates sort and check if prev elem is same or not
    vector<vector<int>> ans = subsequenceOfSumK(arr,8);
    for(auto it : ans){
        for(auto it1 : it){
            cout<<it1<<" ";
        }cout<<endl;
    }
    return 0;
}