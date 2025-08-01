using namespace std;
#include<vector>
#include<iostream>

void merge(vector<int> &arr,int low ,int mid ,int high){
    int left = low;
    int right = mid+1;
    vector<int>temp;
    while(left <= mid && right <= high)
    {
        if(arr[left] >= arr[right]){
            temp.push_back(arr[right]);
            right++;
        }
        else {
            temp.push_back(arr[left]);
            left++;
        }
    }
    while(left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low; i <= high; i++)
    {
        arr[i]=temp[i-low];
    }
    for(auto i:temp){
        cout<<i<<" ";
    }cout<<endl;
    for(auto i: arr){
        cout<<i << " ";
    }cout<<endl;
}


void ms(vector<int> &arr, int low, int high){
    if(low == high) return;
    int mid = (low + high) / 2;
    ms(arr, low, mid);
    ms(arr, mid+1, high);
    merge(arr, low, mid, high);
}

void mergesort(vector<int> &arr, int n){
    ms(arr, 0, n);
}



int main()
{
    vector<int>arr = {3,11,9,6,1,4,5,1,2,3,8};
    int n = arr.size();
    mergesort( arr, (n-1));
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}