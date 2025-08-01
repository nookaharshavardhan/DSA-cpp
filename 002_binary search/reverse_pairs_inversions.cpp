using namespace std;
#include<iostream>
#include<vector>

void merge(vector<int> &arr , int low, int mid, int high){
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
}

int cnt(vector<int> &arr, int low, int mid, int high){
    int j = mid +1;
    int count = 0;
    for(int i = low; i <= mid; i++){
        while(j <= high && arr[i] > 2 * arr[j]){
            j++;
        }
        count += j - (mid+1);
    }
    return count;
}

int ms(vector<int> &arr, int low, int high){
    int count = 0;
    if(low == high )return count;
    int mid = (low + high )/2;   
    ms(arr, low, mid);
    ms(arr, mid + 1, high);
    count += cnt(arr,low, mid , high);
    merge(arr, low, mid ,high);
    return count;
}


int team(vector <int> & arr, int n)
{
    int count = ms(arr, 0, n-1);
    return count;
}


int main()
{
    vector<int> arr = {4, 1, 2, 3, 1};
    int n = arr.size();
    int count = ms(arr, 0, n-1);
    cout<<count<<" ";
    return 0;
}