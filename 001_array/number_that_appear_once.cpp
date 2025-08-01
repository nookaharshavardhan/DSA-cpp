using namespace std;
#include<vector>
#include<iostream>
#include<bits/stdc++.h>

int brute_force(vector<int> &arr, int n){
    int a=0;
    for(int i = 0; i < n; i++){
        a = count(arr.begin(), arr.end(), arr[i]);
        if(a == 1) return arr[i];
    }
}

int use_hashing(vector<int> &arr, int n){
        map< int, int > mpp;
        for(int i = 0; i < n ;i++){
            mpp[arr[i]]++;
        }
        for(const auto &i : mpp){
            if(i.second == 1) return i.first;
        }
        return -1;
}


int xor_function(vector<int> arr, int n){
    int xorr=0;
    for(int i = 0; i < n; i++){
        xorr^=arr[i];
    }
    return xorr;
}

int main()
{
    vector<int> arr={1, 1, 2 ,2 , 3, 3, 4, 4, 5};
    int n = arr.size();
    int m=xor_function(arr, n);
    cout<<m<<" ";
    return 0;
}