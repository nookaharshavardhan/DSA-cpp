using namespace std;
#include<vector>
#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>

int pairWithMaxSum(vector<int> &arr) {
    int n = arr.size();
    int smallest = arr[0];
    int sec_smallest = arr[0];
    int max_score = INT_MIN;
    for(int i = 1; i < n ; i++){
        smallest = arr[i];
        sec_smallest = INT_MAX;
        for(int j = i ; j < n; j++){
            if(arr[j] < smallest) {
                sec_smallest = smallest;
                smallest = arr[j];
            }
            if(arr[j] < sec_smallest && arr[j] != smallest) sec_smallest = arr[j];
            max_score = max(max_score, smallest + sec_smallest);
        }
    }
    return max_score;
}


int main()
{
    vector<int> arr = {4, 3, 1, 5, 6};
    int n = arr.size();
    int m = pairWithMaxSum(arr);
    cout<<m<<" ";
    return 0;
}