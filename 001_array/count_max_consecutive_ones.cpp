using namespace std;
#include<vector>
#include<iostream>

int count_max_consecutive(vector<int> arr, int n){
    int max_count=0;
    int temp=0;
    for(int i= 0; i < n; i++){
        if(arr[i] == 1){
            temp++;
        }
        else{
            temp=0;
        }
        max_count=max(max_count, temp);
    }
    return max_count;
}
int main()
{
    vector<int> arr={1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0 , 1, 1, 0, };
    int n=arr.size();
    int count = count_max_consecutive(arr, n);
    cout<<count<<" ";
    return 0;
}