using namespace std;
#include <iostream>
#include <vector>
#include <algorithm>

void swap_great_num(vector<long long> &arr1, vector<long long> &arr2, int i, int j)
{
    if(arr1[i] > arr2[j]){
        swap(arr1[i], arr2[j]);
    }
}
void shell_sort(vector<long long> &arr1, vector<long long> &arr2)
{                // its just like insertion sort but in his we bring smallest numbers 
    //              closer to satarting point by skipping no of swap to to tavel (imagine if we have 
    //               our elem in last index and we need it in out first inder in insertion sort
    //               we bring elem by one one step but in shell sort we skip elem by bringing the elem more closer)
    int n = arr1.size();
    int m = arr2.size();
    int len = m + n;
    int gap = (len) / 2 + (len) % 2;
    int left, right;
    while (gap > 0)
    {
        left = 0;
        right = left + gap;
        while (right < len)
        {
            // left pointer in arr1 and right pointer in arr2
            if (left < n && right >= n)
            {
                swap_great_num(arr1, arr2, left, right - n);
            }
            // both pointers in arr1
            else if (left < n && right < n)
            {
                swap_great_num(arr1, arr1, left, right);
            }
            // both pointers in arr2
            else
            {
                swap_great_num(arr2, arr2, left - n, right - n);
            }
            left++;
            right++;
        }
        if(gap == 1)break;
        gap = (gap / 2) + (gap % 2);
    }
}

void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &arr1, vector<long long> &arr2)
{
    int n = arr1.size() - arr2.size(); // Size of the non-zero part of arr1
    int sz = arr1.size();              // Total size of arr1 (including 0s)
    int m = arr2.size();               // Size of arr2

    // Initialize pointers
    int left = n - 1; // Pointer to the last non-zero element in arr1
    int right = 0;    // Pointer to the first element in arr2

    // Swap elements until all smaller elements are in arr1 and larger elements are in arr2
    // while (left >= 0 && right < m) {
    //     if (arr1[left] > arr2[right]) {
    //         swap(arr1[left], arr2[right]);
    //         left--, right++;
    //     } else {
    //         break; // Stop if arr1[left] <= arr2[right]
    //     }
    // }

    // // Sort the non-zero part of arr1 and the entire arr2
    // sort(arr1.begin(), arr1.begin() + n); // Fix: Sort only the non-zero part of arr1
    // sort(arr2.begin(), arr2.end());      // Fix: Sort arr2
    for (auto i : arr1)
    {
        cout << i << " ";
    }
    cout << endl;

    // Copy elements from arr2 to arr1
    for (int i = sz - m; i < sz; i++)
    {
        arr1[i] = arr2[i - (sz - m)]; // Fix: Correct index calculation for arr2
    }

    sort(arr1.begin(), arr1.end());
}

int main()
{
    vector<long long> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0, 0};
    vector<long long> arr2 = {1, 2, 3, 4, 5, 6, 7};
    int n = arr1.size();
    int m = arr2.size();
    shell_sort(arr1, arr2);
    for (auto i : arr1)
    {
        cout << i << " ";
    }
    return 0;
}
