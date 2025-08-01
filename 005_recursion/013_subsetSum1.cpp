#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generate(vector<int> & arr,vector<int>& ans,int sum,int i){
    if(i == arr.size()){
        ans.push_back(sum);
        return ;
    }
    generate(arr,ans,sum+arr[i],i+1);
    generate(arr,ans,sum,i+1);
}

vector<int> subsetSum(vector<int> & arr){
    int sum = 0;
    int i = 0;
    vector<int> ans;
    generate(arr,ans,sum,i);
    return ans;
}

int main() {
    vector<int> arr = {3,2,1};
    vector<int> ans = subsetSum(arr);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}