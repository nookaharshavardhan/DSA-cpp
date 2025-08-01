using namespace std;
#include<vector>
#include<iostream>
#include<algorithm>
#include<bits/stdc++.h>


void my_approach(vector<int> &arr,int n){
    for(int i = 0; i< n-1 ;i++){
        for(int j=0;j < n-1; j++){
        if(arr[j]==0){
            swap(arr[j],arr[ j+1 ]);
        }
     }
    }
}

void better_approach(vector<int> &arr, int n){
    // copying non zero elements
    int j=0;
    for(int i = 0; i < n; i++){
        if(arr[i] != 0) arr[j++]=arr[i];
    }
    //pasting zeros
    for(int i = j ;i< n; i++){
        arr[i] = 0;
    }
}



int main()
{
    vector<int> arr={0, 1 ,0 ,2 ,3 ,0 ,0 ,4 ,0 ,1, 0};
    int n=arr.size();
    
    better_approach(arr, n);
    for(auto i: arr){
        cout<<i<<" ";
    }
    return 0;
}