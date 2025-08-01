using namespace std;
#include <iostream>
#include <vector>
bool searchRotated(vector<int> &arr, int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        // if mid points the target
        if (arr[mid] == x)
            return true;

        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low++;
            high--; // for dups
            continue;
        }

        // if left part is sorted:
        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= x && x <= arr[mid])
            {
                // element exists:
                high = mid - 1;
            }
            else
            {
                // element does not exist:
                low = mid + 1;
            }
        }
        else
        { // if right part is sorted:
            if (arr[mid] <= x && x <= arr[high])
            {
                // element exists:
                low = mid + 1;
            }
            else
            {
                // element does not exist:
                high = mid - 1;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> arr = {3, 1, 2, 3, 3, 3};
    int n = arr.size();
    bool x = searchRotated(arr, n, 2);
    cout << x;
    return 0;
}