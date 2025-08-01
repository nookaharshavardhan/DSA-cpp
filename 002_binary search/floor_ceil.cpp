using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>

vector<int> getFloorAndCeil(int x, vector<int> &arr) {
    int n =  arr.size();
    int mid, floor = -1,ceil = -1;
    int low = 0, high = n - 1;
    sort(arr.begin(), arr.end());
    while(low <= high){
        mid = low + (high - low )/2;
        if(arr[mid] == x){
            return {arr[mid], arr[mid]};
        }
        else if(arr[mid] > x){
            ceil = arr[mid];
            high = mid - 1;
        }
        else if(arr[mid] < x){
            floor = arr[mid];
            low = mid + 1;
        }
    }
    return {floor , ceil};
}


int main()
{
    vector<int> arr = {5, 6, 8, 9, 6, 5, 5, 6};
    vector<int> arr1 = getFloorAndCeil(7,arr);
    for(auto i : arr1){
        cout<<i<<" ";
    }
    return 0;
}