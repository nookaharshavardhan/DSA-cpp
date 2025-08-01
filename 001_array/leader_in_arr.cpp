// Problem Statement: Given an array, print all the elements which 
// are leaders. A Leader is an element that is greater than all of the
//  elements on its right side in the array.
using namespace std;
#include <vector>
#include <iostream>

vector<int> superiorElements(vector<int> &arr)
{
    int n = arr.size();
    int max_elem = arr[n - 1];
    vector<int> ans;
    ans.push_back(arr[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > max_elem)
            ans.push_back(arr[i]);
        if (arr[i] > max_elem)
            max_elem = arr[i];
    }
    return ans;
}

int main()
{
    vector<int> arr = {2, 3, 4, 5, 3, 2, 4, 5, 7, 9, 2, 3, 4, 6, 5};
    vector<int> arr1 = superiorElements(arr);
    for (auto i : arr1)
    {
        cout << i << " ";
    }
    return 0;
}