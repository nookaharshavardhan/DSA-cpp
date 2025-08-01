#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



void generate1(vector<vector<int>> &ans, vector<int> &arr, vector<int> &temp, int target, int st)
{
    if(target == 0){
        ans.push_back(temp);
        return ;
    }
    for(int i = st ;i< arr.size();++i){
        if(i > st && arr[i] == arr[i-1])continue;
        if(arr[i] > target)break;
        temp.push_back(arr[i]);
        generate1(ans,arr,temp,target-arr[i],i+1);
        temp.pop_back();
    }
}



vector<vector<int>> combinationsOfSumK(vector<int> &arr, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;
    int sum = 0;
    sort(arr.begin(), arr.end());
    generate1(ans,arr,temp,target,0);
    return ans;
}

int main() {
    vector<int> arr = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> ans = combinationsOfSumK(arr, target);
    for (auto it : ans)
    {
        for (auto it1 : it)
        {
            cout << it1 << " ";
        }
        cout << endl;
    }
    return 0;
}