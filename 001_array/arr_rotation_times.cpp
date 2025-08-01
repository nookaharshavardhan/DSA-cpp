using namespace std;
#include<iostream>
#include<vector>
#include<limits.h>

int findKRotation(vector<int> &arr){
    int n = arr.size();
	int low = 0, high = n-1;
	int mid = low + (high - low)/2;
	int ans = INT_MAX,index = 0;
	while(low <= high){
		//search space is already sorted
        //then arr[low] will always be
        //the minimum in that search space:
        if(arr[low] <= arr[high]){
			if(arr[low] < ans){
				ans = arr[low];
				index = low;
			}
			break;
		}
		if(arr[mid] <= arr[high]){
			if(arr[mid] < ans){
				ans = arr[mid];
				index = mid;
			}
			high = mid -1;
		}
		else{
			low = mid + 1;
		}
		mid = low + (high - low)/2;
	}
	return index; 
}


int main()
{
    vector<int> arr = {3,4,5,2};
    int n = findKRotation(arr);
    cout<<"no of turns-"<<n;
    return 0;
}