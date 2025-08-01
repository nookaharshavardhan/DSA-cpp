using namespace std;
#include<vector>
#include<iostream>
int main()
{
    vector<int>arr={77,12,6,2,32,43,23,15,18,1};
    int n=arr.size();
    for(int j=0;j<n-1;j++)
    {
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);
            }
        }
        for(auto i:arr){
            cout<<i<<" ";
        }cout<<endl;
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
