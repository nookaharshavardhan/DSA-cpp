using namespace std;
#include<vector>
#include<iostream>
#include<algorithm>
int main()
{
    vector<int> arr={1,2,3,4,5,1,1,2,2,1,2,3,4,5,7,8,11};
    int n=arr.size();
    int x;
    for(int i=0;i< n ;i++)
	{
        while(x>1){
        x=count(arr.begin(),arr.end(),arr[i]);
        if(x>1) arr.erase(arr.begin() + i);
        }
        cout<<x<<" ";
	}cout<<endl;
    for(auto i : arr){
        cout<<i<<" ";
    }cout<<endl;
    cout<<arr.size()<<" ";
    

    return 0;
}