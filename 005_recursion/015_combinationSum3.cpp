#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generate(vector<vector<int>> & ans,vector<int>& temp,int target,int len,int i,int sum){
    if(temp.size() == len){
        if(sum == target) ans.push_back(temp);
        return;
    }
    for(int st = i; st < 10 ; st++){
        if(sum + st > target) break;
        temp.push_back(st);
        generate(ans,temp,target,len,st+1,sum+st);  
        temp.pop_back();
    }
}

vector<vector<int>> combinationSum3(int target,int len){
    vector<vector<int>> ans;
    vector<int> temp;
    int i = 1;
    int sum = 0;
    generate(ans,temp,target,len,i,sum);
    return ans;
}

int main() {
    int target = 9;
    int len = 3;
    vector<vector<int>> ans = combinationSum3(target,len);
    for(auto it : ans){
        for(auto it1 : it){
            cout<<it1<<" ";
        }cout<<endl;
    }
    return 0;
}