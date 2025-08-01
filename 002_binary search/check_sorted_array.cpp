using namespace std;
#include<vector>
#include<iostream>

int isSorted(int n, vector<int> arr) {
    int sorted;
    for(int i=0; i < n-1 ; i++){
        if(arr[i] <= arr[i+1]) sorted=1;
        else sorted=0;

        if(sorted==0) return sorted;
    }
    return sorted;
}

int main()
{
    vector<int> arr={12,4,5,46,67,7,4,3};
    int n=arr.size();
    isSorted(n,arr);
     
    return 0;
}