using namespace std;
#include<vector>
#include<iostream>

void merge(vector <int> & arr ,int low, int mid , int high, vector<int> & temp){
    int left = low;
    int right = mid+1;
    int k = low;
    while( left <= mid && right <= high){
        if(arr[left] >= arr[right]){
            temp[k++]=arr[right++];
        }
        else{
            temp[k++]=arr[left++];
        }
    }
    while( left <= mid ){
        temp[k++]=arr[left++];
    }
    while( right <= high ){
        temp[k++]=arr[right++];
    }
    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i];
    }

}
void ms(vector< int > & arr, int low, int high,vector<int> &temp){
    if(low == high) return;
    int mid=(low + high) / 2;
    ms(arr, low, mid, temp);
    ms(arr, mid+1, high, temp);
    merge(arr, low, mid, high, temp);
}

void mergeSort(vector < int > & arr, int n) {
    vector<int> temp(n);
   ms(arr,0,n-1,temp);
}

int main()
{
    vector<int>  arr={12,23,23,34,45,23,12,25,34,5,6,9};
    int n = arr.size();
    mergeSort(arr , n);
    for(auto i:arr){
        cout<<i<<" ";
    }   
    return 0;
}