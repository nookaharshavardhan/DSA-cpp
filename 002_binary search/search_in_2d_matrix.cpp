using namespace std;
#include<iostream>
#include<vector>

bool search_in_array(vector<int> & arr, int k){
    int low = 0;
    int high = arr.size() -1,mid;
    while(low <= high){
        mid = (low + high)/2;
        if(arr[mid] == k) return true;
        else if(arr[mid] < k){
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return false;
}
bool search_2D_array(vector<vector<int>> & arr,int k){
    int rows = arr.size();
    int cols = arr[0].size();
    int low = 0;
    int high = rows-1,mid;
    while(low <= high){
        mid = (high + low)/2;
        if(k >= arr[mid][0] && k <= arr[mid][cols-1]){
            return search_in_array(arr[mid],k);
        }
        else if(k > arr[mid][cols-1]){
            low = mid + 1;
        }
        else if(k < arr[mid][0]) high = mid -1 ;
    }
    return false;
}



bool searching_by_2DToLinear(vector<vector<int>> & arr,int k){
    int n= arr.size();
    int m = arr[0].size();
    int low = 0;
    int high = n*m - 1,mid;
    while(low <= high){
        mid = (low + high)/2;
        if(arr[mid / m][mid % m] ==  k){
            return true;
        }
        else if(arr[mid / m][mid % m] >  k) high = mid - 1;
        else low = mid + 1;
    }
    return false;
}
int main()
{
    vector<vector<int>> arr = {{1,2,3},{4,5,6},{7,8,9}};
    int k = 2;
    if(searching_by_2DToLinear(arr,k)){
        cout<<"element is in the matrix "<<endl;
    }
    else cout<<"element id not in the matrix "<<endl;
    return 0;
}