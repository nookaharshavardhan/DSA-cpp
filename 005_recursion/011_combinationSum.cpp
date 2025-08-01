#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

void generate(vector<vector<int>> &ans, vector<int> arr, vector<int> temp, int sum, int k, int i)
{
    if (sum == k)
    {
        ans.push_back(temp);
        return;
    }
    if (sum > k || i == arr.size())
    {
        return;
    }
    temp.push_back(arr[i]);
    // generate(ans,arr,temp,sum+arr[i],k,i+1);
    generate(ans, arr, temp, sum + arr[i], k, i);
    temp.pop_back();
    generate(ans, arr, temp, sum, k, i + 1);
}

// generate(ans,arr,temp,sum+arr[i],k,i+1);
// generate(ans,arr,temp,sum+arr[i],k,i);        instead of three we can just use 2
// temp.pop_back();
// generate(ans,arr,temp,sum,k,i+1);



// more optimized version, it is efficient by pruning
void generate1(vector<vector<int>> &ans, vector<int> &arr, vector<int> &temp, int target, int st)
{
    if(target == 0){
        ans.push_back(temp);
        return ;
    }
    for(int i = st ;i< arr.size();++i){
        if(arr[i] > target)break;
        temp.push_back(arr[i]);
        generate1(ans,arr,temp,target-arr[i],i);
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
    // generate(ans, arr, temp, sum, target, 0);
    return ans;
}


int main()
{
    vector<int> arr = {2, 3, 6, 7 , 1};
    int target = 7;
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