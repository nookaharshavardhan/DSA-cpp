using namespace std;
#include<vector>
#include<iostream>
int main()
{
    vector<int>arr={77,23,12,34,56,11,1};
    int n=arr.size();
    for(int i=0;i<n-1;i++)
    {

        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[i])
            {
                swap(arr[j],arr[i]);
            }
            
        }
    } 
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}