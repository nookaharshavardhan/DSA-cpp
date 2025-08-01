using namespace std;
#include<vector>
#include<climits>
#include<iostream>
int main()
{
    vector<int> arr={10, 10, 10};
    int n = arr.size();
    int max = INT_MIN;
    int sec_max = INT_MIN;

    for(int i=0; i < n ;i++){
        if(arr[i] > max ){
            sec_max = max;
            max = arr[i];
        } else if (arr[i] > sec_max && arr[i] != max) sec_max = arr[i];

    } 
    if(sec_max == INT_MIN){
        sec_max = -1;
    }
    cout<<sec_max<<" ";
    return 0;
}