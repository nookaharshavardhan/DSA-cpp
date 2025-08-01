using namespace std;
#include<vector>
#include<iostream>
int main()
{
    vector<int> arr={1,2,3,4,5,6,7};
    int n=arr.size();
    int k=3;
    int first=arr[n-1];
    for(int j = n-1; j >= 1 ;j--){
        arr[j] = arr[j-1];
        
    }
    arr[0] = first;
        
    for(auto i: arr){
        cout<<i<<" ";
    }
    return 0;
}
