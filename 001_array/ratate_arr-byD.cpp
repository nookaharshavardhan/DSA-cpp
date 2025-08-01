using namespace std;
#include<vector>
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>

void vector_rotate_better(vector<int> &arr, int d, int n){
    d= d % n;
    //storing raoted elems into temp
    vector<int>temp(d);
    for(int i = 0; i < d; i++){
        temp[i] = arr[i];
    }
    //shifting
    for(int i = d; i < n ; i++){
        arr[i - d]=arr[i];
    }
    //pasting temp
    for(int i = n-d ;i < n; i++){
        arr[i]=temp[i-(n-d)];
    }
    
}
void vector_rotate_optimal(vector<int> &arr, int d, int n){
    reverse(arr.begin()+d,arr.end());
    reverse(arr.begin(),arr.begin()+d);
    reverse(arr.begin(),arr.end());
}
int main()
{
    vector<int> arr={1,2,3,4,5,6,7,8,9,10};
    int n=arr.size();
    int d=3;
    vector_rotate_optimal(arr, d, n);
    //printing
    for(auto i:arr){
        cout<<i<<" ";
    }
    return 0;
}