using namespace std;
#include<iostream>
#include<vector>
#include<algorithm>

int possible(vector<int> &arr,int &pages){
    int cnt = 1;
    int pages_student = 0;
    for(int i = 0 ; i < arr.size() ; i++){
        if(pages_student + arr[i] <= pages){
            pages_student += arr[i];
        }
        else{
            cnt++;
            pages_student = arr[i];
        }
    }
    return cnt;
}




int findPages(vector<int>& arr, int n, int m) {
    int sum = 0;
    for(int i = 0; i < arr.size(); i++){
        sum += arr[i];
    }
    int low = *max_element(arr.begin(),arr.end());
    int high = sum;
    int mid = low + (high - low)/2;
    int ans;
    while(low <= high){
        if(possible(arr, mid) <= m){
            ans = mid;
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
        mid = low + (high - low)/2;
    }
    return ans;
}

int main(){
    vector<int> arr = {12,34,10,25};
    int books = arr.size();
    int students = 2;
    cout<<findPages(arr,books,students);
}