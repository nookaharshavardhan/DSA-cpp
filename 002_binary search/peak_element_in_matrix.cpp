using namespace std;
#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
#include<bits/stdc++.h>

int find_max(vector<vector<int>> & arr,int col){
    int index;
    int large = INT_MIN;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i][col] > large){
            large = arr[i][col];
            index = i;
        }
    }
    return index;
}
vector<int> peak_element(vector<vector<int>> & arr){
    int rows = arr.size();
    int cols = arr[0].size();
    int low = 0;
    int high = cols - 1;
    int mid;
    int index;
    while(low <= high){
        mid =( low + high)/2;
        index = find_max(arr,mid);
        int right = mid + 1 < cols ? arr[index][mid + 1] : -1;
        int left = mid -1  >= 0 ? arr[index][mid - 1]: -1;
        if(arr[index][mid] > left && arr[index][mid] > right){
            return {index,mid};
        }
        else if(arr[index][mid] < left) high = mid -1;
        else low = mid + 1;
    }
    return {-1,-1};
}

int main()
{
    vector<vector<int>> arr = {
        {10, 20, 15},
        {21, 3, 14},
        { 7, 16, 32}
    };
    vector<int> ans = peak_element(arr);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}