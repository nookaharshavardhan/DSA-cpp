using namespace std;
#include<vector>
#include<iostream>
void recursive_bubble_sort(vector<int> &arr, int n){
    if(n == 1)return;
    int i = 0;
    int didswap=0;
    for(int i = 0 ;i <= n-2 ;i++)
    {
        if(arr[i] >= arr[i+1])
        {
            swap(arr[i], arr[i+1]);
            didswap = 1;
        }
       
    }
    if(didswap == 0) return;
    recursive_bubble_sort( arr, n-1);
}
int main()
{
    vector<int>arr={ 77, 12, 2, 15, 32, 6, 14, 34, 1};
    int n = arr.size();
    recursive_bubble_sort( arr, n);
    for(auto i:arr)
    {
        cout<<i<<" ";
    }
    return 0;
}