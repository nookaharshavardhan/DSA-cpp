using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>
#include<set>

int my_approach(vector<int>&arr, int n) {
   set<int> s(arr.begin(), arr.end());
   copy(s.begin(),s.end(),arr.begin());
   for(int i = 1; i <=n;i++){
       if(arr[i-1] != i) return i;
   }
   return n;
 }

int by_hashing(vector<int> &arr, int n){
   vector<int>hash(n,0);
   for(int i = 0; i < n; i++){
      hash[arr[i]]++;
   }

   for(int i = 1;i <= n ; i++){
      if(hash[i]==0) return i;
   }
}

int math(vector<int> &arr, int n){
   int m=(n*(n+1))/2;
   int sum=0;
   for(int i = 0; i<n-1 ; i++){
       sum+=arr[i];
   }
   return m-sum;
}


int XOR(vector<int> & arr, int n){
   int xor1=0,xor2=0;
   for(int i = 0; i < n-1 ;i++){
      xor1=xor1^arr[i];
      xor2=xor2^(i + 1);
   }xor2^=n;
   return xor1^xor2;
}


int main()
{
   vector<int> arr={1,3,5,2,4,7,8,9,6};
   int n=arr.size();
   int m=XOR(arr, n);  
   for(auto i : arr){
      cout<<i<<" ";
   }
   cout<<endl<<m;
}