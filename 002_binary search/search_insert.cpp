using namespace std;
#include <iostream>
#include <vector>
int searchInsert(vector<int> &arr, int m)
{
    int low = 0, high = arr.size() - 1;
    int mid, ans;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == m)
            return mid;
        else if (arr[mid] > m)
        {
            ans = mid ;   // if it is greater than target then taek its place
            high = mid - 1;    // should have merged >=  but i have GK
        }
        else
        {
            ans = mid + 1;
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{                   // 0  1  2  3  4
    vector<int> arr = {1, 2, 4, 5, 8};
    int x = searchInsert(arr, 7);
    cout << x << " ";
    return 0;
}