using namespace std;
#include<vector>
#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>


string sol_1(vector<int> arr, int n, int k){       // using hash
    map< int, int> mpp;
    int req_num;
    int sum = 0;
    for(int i = 0; i < 5 ; i++){
        req_num = k - sum;
        if(mpp.find(req_num) != mpp.end()){
            return "YES";
        } 
        mpp[arr[i]]++;
    }
    return "NO";
}



string sol_2(vector<int> arr, int n, int k){        //using two pointer method
    sort(arr.begin(), arr.end());
    int i = 0, j = n-1;
    int sum = 0;
    while(i < j){
        sum = arr[i] + arr[j];
        if(sum == k) return "YES";
        else if(sum < k) i++;
        else j--;
    }
    return "NO";
}


int main()
{
    vector<int> arr={1,2,3,4,5,6,7,8,92,3,41,1};
    int n= arr.size();
    int k = 5;
    string arr1 = sol_2(arr, n , k);
    cout<<arr1<<" ";
    return 0;
}