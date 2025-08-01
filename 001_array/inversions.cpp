using namespace std;
#include<iostream>
#include<vector>

int merge(vector<int> &arr , int low, int mid, int high){
    int count = 0;
    int i = low;
    int j = mid + 1;
    vector<int> temp;
    while(i <= mid && j <= high){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }
        else{
            temp.push_back(arr[j]);
            j++;
            count += (mid - i + 1);
        }
    }
    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }
    while(j <= high){
        temp.push_back(arr[j]);
        j++;
    }
    for(int k = low; k <= high; k++){
        arr[k] = temp[k - low];
    }
    return count;
}

int ms(vector<int> &arr, int low, int high){
    int count = 0;
    if(low == high )return count;
    int mid = (low + high )/2;   
    count += ms(arr, low, mid);
    count += ms(arr, mid + 1, high);
    count += merge(arr, low, mid ,high);
    return count;
}
int mergesort(vector<int> &arr , int n){
    int count = ms(arr, 0, n-1);
    return count;
}
int main()
{                    // 0  1 2 3  4 5 6 7  8  9
    vector<int> arr = {1, 20, 6, 4, 5};
    int n = arr.size();
    int ans = mergesort(arr, n);
    for (auto it : arr)
    {
        cout<<it<<" ";
    }cout<<endl;
    cout<<ans<<endl;
    return 0;
}