using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>



bool check_possibility(vector<int> &arr, int dist,int n,int cows){
    int last_stall = arr[0];
    int cntCows = 1;
    for(int i = 1 ; i < n; i++){
        if(arr[i] - last_stall >= dist){
            cntCows++;
            last_stall = arr[i];
        }
        if(cntCows >= cows) return true;
    }
    return false;
}






int distance_of_stalls(vector<int> &arr,int cows,int n){
    sort(arr.begin(),arr.end());
    int low = 1;
    int high = arr[n - 1] - arr[0];
    int mid = low + (high - low)/2;
    while(low <= high){
        if(check_possibility(arr,mid,n,cows)){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
        mid = low + (high - low)/2;
    }
    return high;
}





int main()
{
    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
    int cows = 6;
    int n = arr.size();
    cout<<distance_of_stalls(arr,cows,n);
    return 0;
}