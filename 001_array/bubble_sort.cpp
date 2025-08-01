using namespace std;
#include<vector>
#include<iostream>
int main()
{
    vector<int>arr={77,34,23,12,45,1};
    int n=arr.size();
    for(int i=n-1;i>0;i--)
    {
        for(int j=0;j<=i-1;j++)
        {
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
            
        }
    } 
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}