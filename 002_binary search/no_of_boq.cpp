using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>


bool check_boq(vector<int> & arr, int day,int m, int k){
    int count = 0;
    int maxi = 0;
    int no_boq;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] <= day){
            count++;
        }
        else{
            no_boq += count/k;
            count = 0;
        }
    }
    if(no_boq >= k) return true;
    return false;
}

int minDays(vector<int>& arr, int m, int k) {
    int n = arr.size();
    if(n < m*k) return -1;
    int low = 0;
    int high = *max_element(arr.begin(),arr.end());
    int mid = low + (high - low)/2;
    while(low <= high){
        if(check_boq(arr, mid, m, k)){
            int result = mid;
            high = mid - 1;
        }
        else low = mid + 1;
        mid = low + (high - low)/2;
    }
    return mid;
}
int main()
{
     
    return 0;
}