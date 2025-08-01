using namespace std;
#include<vector>
#include<iostream>
int main()
{
    vector<int>arr={13,11,32,23,14,7,2};
    int n=arr.size();
    //to select elements in index
    for(int i=0;i<n;i++)
    {
        int j=i;
        // to arrange the element
        while(j>0 && arr[j-1]>arr[j])
        {
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }

    return 0;
}