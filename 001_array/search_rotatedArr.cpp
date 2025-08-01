using namespace std;
#include<iostream>
#include<vector>

int search(vector<int>& arr, int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if mid points the target
        if (arr[mid] == x) return mid;

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= x && x <= arr[mid]) {
                //element exists:
                high = mid - 1;
            }
            else {
                //element does not exist:
                low = mid + 1;
            }
        }
        else { //if right part is sorted:
            if (arr[mid] <= x && x <= arr[high]) {
                //element exists:
                low = mid + 1;
            }
            else {
                //element does not exist:
                high = mid - 1;
            }
        }
    }
    return -1;
}


int main()
{
    vector<int> arr = {6,7,8,9,0,4,5};
    int n = arr.size();
    int index = search(arr, n, 8);
    cout<<index<<endl;
    return 0;
}