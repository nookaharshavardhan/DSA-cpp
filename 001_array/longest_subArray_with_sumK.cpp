using namespace std;
#include<vector>
#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
vector<int> solution_0(vector<int> arr, int n, int k){
    vector<int> temp;
    vector<int> long_arr;
    int sum;
    int z;
    for(int i = 0;i < n; i++){
        sum = 0;
        z = i;
        temp.clear(); // if we put it last , it will get cleared even if the lon sub arr is in last iteration
        while(z < n && sum + arr[z] <= k){
            sum += arr[z];
            temp.push_back(arr[z]);
            z++;
        }
        if(temp.size() > long_arr.size() && sum == k){
            long_arr=temp;
        }
        
    } 
    return long_arr;
}

int solution_1(vector<int> arr, int n , int k){
    int len = 0;
    for (int i = 0; i < n; i++) { // starting index
        for (int j = i; j < n; j++) { // ending index
            // add all the elements of
            // subarray = a[i...j]:
            long long s = 0;
            for (int K = i; K <= j; K++) {
                s +=arr [K];
            }

            if (s == k) len = max(len, j - i + 1);
        }
    }
    return len;
}

int optimal_without_negative(vector<int> arr, int n , int k){        //doesn't work with negative casue the j cant move right wards
    int sum = 0;                               //for ex {10 5 2 7 1 -10} this is given i will give {5,2,7,1} as sub_arr not entire arr
    int max_len=0;                            //cause the j moved previously right side
    int i = 0, j = 0;
    while(i < n){
        sum += arr[i];

        while(j <= i && sum > k){
            sum -= arr[j];
            j++;
        }
        if(sum == k) max_len = max(max_len, i - j + 1);
        
        i++; 
       
    }
    
    return max_len;
}


int optimal_with_negative(vector<int> arr, int n, int k){
    int max_len=0;
    long long sum = 0;
    long long rem = 0;
    map<int, int> mpp;
    for(int i = 0; i < n; i++){
        sum +=arr[i];
        if( sum == k) max_len = max(max_len, i + 1);
        rem = sum - k;
        if(mpp.find(rem) != mpp.end()){
            max_len = max(max_len, i - mpp[rem]);
        }
        if(mpp.find(sum) == mpp.end())mpp[sum] = i; // adding all sums at last and only only when the sum is not present , to counter zeros in arr
    }
    return max_len;
}
int main()
{
    vector<int> arr={1,2,3,4,1,1,1,5,0,1,2,0,0,0,0,0,2,3,2,0,1,1,3};
    int n = arr.size();
    int k=4;
    int long_subArr_len=optimal_with_negative(arr, n, k);
    vector<int> sub_arr=solution_0(arr, n ,k);
    cout<<long_subArr_len<<endl;
    for(auto i : sub_arr){
        cout<<i<<" ";
    }
    return 0;
}