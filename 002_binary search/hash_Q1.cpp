using namespace std;
#include<vector>
#include<iostream>
int main()
{
    vector<int>arr={1,2,3,7,2,3,8,3};
    int n=arr.size();
    vector<int>hashh(n,0);
    for(int i=0;i<n;i++)
    {
        hashh[arr[i]-1]++;
    }
    for(auto i :hashh){
        cout<<i<<" ";
    }
    
}
   
