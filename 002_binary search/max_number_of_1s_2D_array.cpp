using namespace std;
#include<bits/stdc++.h>

int search_max_number_of_1s_rpeated(vector<vector<int>> & arr){
    int cols = arr[0].size();
    int mid;
    int ans;
    int max_ones = INT_MIN;
    for(int i = 0; i < arr.size();i++){
        int low = 0;
        int high = cols - 1;
        while(low <= high){
            mid = (low + high )/2;
            if(arr[i][mid] == 0) low = mid + 1;
            else high = mid - 1;
        }
        if(cols -mid > max_ones){
            ans = i;
            max_ones = cols - mid;
        }
    }
    return ans;
}


int main()
{
    vector<vector<int>>arr = {{0,1,1},{0,0,1},{0,0,0}};
    int x = search_max_number_of_1s_rpeated(arr);
    cout<<x<<endl;
    return 0;
}