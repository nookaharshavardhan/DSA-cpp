#include<vector>
#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
using namespace std;
void sort(vector<int> & arr, int low, int mid, int high){
    int i = low;
    int j = mid + 1;
    vector<int> temp;
    while(i <= mid && j <= high){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else {
            temp.push_back(arr[j]);
            j++;
        }
    }
    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j <= high){
        temp.push_back(arr[j]);
        j++;
    }
    for(int k = low; k <= high; k++){
        arr[k] = temp[k - low];
    }


}
void MS(vector<int> &arr, int low, int high){
    if(low == high) return ;
    int mid = (low + high)/2;
    MS(arr, low , mid);
    MS(arr,mid + 1, high);
    sort(arr , low, mid, high);
}
vector<int> via_merge_sort(vector<int> arr , int n){

    MS(arr, 0, n - 1);
    return arr;
}

vector<int> better_approach(vector<int> arr, int n){
    vector<int> arr1(n);
    int c_0=0, c_1 = 0, c_2 =0;
    for(int i = 0; i < n ; i++){
        if(arr[i] == 0) c_0++;
        else if(arr[i] ==1) c_1++;
        else c_2++;
    }
    
    for(int i = 0; i < n ; i++){
        if(i < c_0 ){
            arr1[i] = 0;
        }
        else if(i < (c_0 + c_1)){
            arr1[i] = 1;
        }
        else arr1[i] = 2;
    }
    return arr1;
}


vector<int> optimal(vector<int> arr, int n){
    int low = 0;
    int mid = 0;
    int high = n - 1;
    for(int i = 0;i < n; i++){
        if(arr[mid] == 0){
            swap(arr[mid], arr[low]);
            mid++;
            low++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
    return arr;
}

int main()
{                  // 0  1 2  3  4   5  6  7  8  9  10 11
    vector<int> arr={1, 0, 1, 2, 1 , 2, 0, 0, 1, 2, 2, 1};
    int n = arr.size();
    vector<int> result= optimal(arr, n);

    for(auto i : result){
        cout<<i<<" ";
    }
    return 0;
}