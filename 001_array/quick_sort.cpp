using namespace std;
#include<vector>
#include<iostream>
int partitian(vector<int> &arr, int low, int high){
    
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j){
        while( arr[i] <= pivot && i <= high-1) i++;

        while( arr[j] > pivot && j >= low+1) j--;

        if( i < j){
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[low], arr[j]);
    return j;
}

void quicksort(vector<int> &arr,int low,int high){
    if(low < high){
        int pIndex=partitian(arr, low, high);
        quicksort(arr, low, pIndex-1);
        quicksort(arr , pIndex+1, high);
    }
}

int main()
{
    vector<int>arr={2,3,4,5,23,21,12,15,16,9,1};
    int n = arr.size();
    quicksort(arr, 0, n-1);
    for(auto i:arr){
        cout<<i<<" ";
    }
    return 0;
}