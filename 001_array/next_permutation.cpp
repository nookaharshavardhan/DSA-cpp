using namespace std;
#include<vector>
#include<iostream>
#include<algorithm>


void nextPermutation(vector<int>& arr) {
    int n = arr.size();
    int break_index = -1;
    if(n <= 1){
        return;
    }
    for(int i = n-2;i >= 0; i--){
        if(arr[i] < arr[i + 1]){
            break_index = i;
            break;
        }
    }
    if(break_index == -1) {
        reverse(arr.begin(), arr.end());
        return;
    }
    for(int i = n-1 ; i > break_index; i--){
        if(arr[i] > arr[break_index]) {
            swap(arr[break_index], arr[i]);
            break;
        }
    }

    reverse(arr.begin() + break_index + 1, arr.end());
}

int main()
{
    vector<int> arr = {1, 4 , 9 ,2};
    int n = arr.size();
    nextPermutation(arr);
    for(auto i : arr){
        cout<<i<<" ";
    }
    return 0;
}