using namespace std;
#include<vector>
#include<iostream>
bool my_approach(vector<int> &arr, int n, int x){
   
    for(int i = 0;i < n; i++){
        if(arr[i] == x) return true;
    }
    return false;
}
int main()
{
    vector<int> arr={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n=arr.size();
    int x=5;
    bool present=my_approach(arr, n, x);
    cout<<present<<" ";
    return 0;
}