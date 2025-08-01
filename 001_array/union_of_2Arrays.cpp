#include<vector>
#include<iostream>
#include<set>
using namespace std;

vector<int> my_approach(vector<int> arr1, vector<int>arr2, int n, int m){
    set<int> s;
    for(int i = 0;i < n ;i++) s.insert(arr1[i]);
    for(int i = 0;i < m ;i++) s.insert(arr2[i]);
    vector<int> fnl_arr(s.begin(), s.end());
    return fnl_arr;
}

vector<int> optimal_approach(vector<int> arr1,vector<int>arr2, int n, int m){
    int i=0;
    int j=0;
    vector<int> u_nion;
    while(i < n && j < m){
        if(arr1[i] <= arr2[j] ){
            if(u_nion.size() == 0 || arr1[i] != u_nion.back()){   // Case 1 and 2
                u_nion.push_back(arr1[i]);
            }
            i++;
        }
        else{                                                      // Case 3
            if(u_nion.size() == 0 || arr2[j] != u_nion.back()){
                u_nion.push_back(arr2[j]);
            }
            j++;
        }
    }
    while(i < n){                                                   // if elems are leftover in arr1
       if(arr1[i] != u_nion.back()){
           u_nion.push_back(arr1[i]);
         } 
       i++;
    }
    while(j < m){                                                    // if elems are leftover in arr2
        if(arr2[j] != u_nion.back()){
            u_nion.push_back(arr2[j]);
        } 
        j++; 
    }
    return u_nion;

}
int main()
{
    vector<int> arr1={1,2,4,6};
    vector<int> arr2={2,4,5,6,7};

    int n=arr1.size();
    int m=arr2.size();

    vector<int> fnl=optimal_approach(arr1, arr2, n, m);

    
    for(auto i :fnl){
        cout<<i<<" ";
    }
    
    return 0;
}