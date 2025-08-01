using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>

class Solution {
public:
    bool possible(const vector<int>&arr,const int &k,const int &mid ){
        int sum = 0;
        int cnt = 0;
        for(int i = 0; i < arr.size(); i++){
            if((sum+arr[i]) <= mid){
                sum += arr[i];
            }
            else{
                cnt++;
                sum = arr[i];
            }
        }
        return cnt+1 <= k;
    }
    int splitArray(vector<int>& arr, int k) {
       int low = *max_element(arr.begin(),arr.end());
       int high = accumulate(arr.begin(),arr.end() ,0);
        int ans;
       while(low <= high){
        int mid = low + (high - low)/2;
        if(possible(arr,k,mid)){
            high = mid - 1;
            ans = mid;
        }
        else{
            low = mid + 1;
        }
       }
        return low;
    }
};

int main(){
    vector<int> arr = {12,34,223,23,232,323,23,3,23};
    
}