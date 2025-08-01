using namespace std;
#include<vector>
#include<iostream>
void recursive_insertion_sort(vector<int> &arr,int n){
    if(n == 1) return;
    int sz=arr.size();
    int j=sz-n+1;
    while( j >0 && arr[j]<arr[j-1])
    {
        swap(arr[j],arr[j-1]);
        j--;
    }
    recursive_insertion_sort(arr,n-1);
}
int main()
{                    //0   1   2  3   4  5   6
    vector<int>arr = {77, 12, 3, 24, 32, 12, 1,2,34,5,46,57,678,7,8,89,0}; 
    int n = arr.size();
    recursive_insertion_sort(arr,n);
    for(auto i :arr)
    {
        cout<<i<<" ";
    }
    return 0;
}