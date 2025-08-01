using namespace std;
#include<vector>
#include<iostream>
int main()
{
    vector<int> arr={2,34,5,23,12,23,17,18,2,1,7,9};
    vector<int> arr1;
    int n=arr.size();
    int max=arr[0];
    int sec_max=arr[0];
    int least=arr[0];
    int sec_least=arr[0];

    for(int i = 1; i < n; i++){
        if(arr[i] > max)  max = arr[i];
        if(arr[i] < least) least = arr[i];
    }
    for(int i = 1; i < n ;i++){
        if(arr[i] > sec_max && sec_max != max) sec_max = arr[i];
        if(arr[i] < sec_least && sec_least != least) sec_least = arr[i]; 
    }
    arr1.push_back(sec_max);
    arr1.push_back(sec_least); 
    
    for(auto i: arr1)
    {
        cout<<i<<" ";
    }
}