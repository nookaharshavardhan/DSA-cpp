using namespace std;
#include <iostream>
#include <vector>

int singleNonDuplicate(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i = i + 2)
    {
        if (arr[i] != arr[i + 1])
            return arr[i];
    }
    return -1;
}

int dup_elem_optimized(vector<int> &arr)
{
    int n = arr.size();
    if(n == 1) return arr[0];
    if (arr[0] != arr[1])
        return arr[0];
    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];
    int low = 1, high = n - 2, mid;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
            return arr[mid];

        // we are on left half
        if ((arr[mid] == arr[mid - 1] && mid % 2 == 1) ||
            (arr[mid] == arr[mid + 1] && mid % 2 == 0))
        {
            low = mid + 1;
        } // on right half
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5};
    int n = dup_elem_optimized(arr);
    cout << n << endl;
    return 0;
}