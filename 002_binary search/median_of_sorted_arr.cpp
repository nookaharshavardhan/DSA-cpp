using namespace std;
#include<iostream>
#include<vector>

double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size();
    int m = arr2.size();
    int left = 0,right = 0;
    vector<int>temp;
    while(left < n && right < m){
        if(arr1[left] > arr2[right]){
            temp.push_back(arr2[right]);
            right++;
        }
        else{
            temp.push_back(arr1[left]);
            left++;
        }
    }
    while(left < n){
        temp.push_back(arr1[left]);
        left++;
    }
    while(right < m){
        temp.push_back(arr2[right]);
        right++;
    }
    for(auto it : temp){
        cout<<it<<" ";
    }cout<<endl;
    int sz = temp.size();
    cout<<(temp[sz/2]-1) << endl;
    cout<<((double)(temp[sz/2]-1) + (double)(temp[sz/2]))<<endl;
    if(sz % 2 == 1) return (double)temp[sz / 2];
    double x = ((double)(temp[sz/2]-1) + (double)(temp[sz/2]))/2;
    if(x < 0 ) return 0;
    return x;
}

int main()
{
    vector<int> arr1 = {2 , 2, 4, 4};
    vector<int> arr2 = {2 , 2, 4, 4};
    cout<<findMedianSortedArrays(arr1,arr2);
    return 0;
}