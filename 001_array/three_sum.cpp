#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<vector<int>> sum(vector<int> arr, int n, int rq_sum)
{
    vector<vector<int>> ans;
    int j;
    int k;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {

        // skiping the i if the arr has duplicates    {-2, -2, -2, 0, 0, 1, 1, 3, 6} so it skip two(-2s),two(0s),two(1s)
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        // moving 2 pointers
        j = i + 1;
        k = n - 1;

        while (j < k)
        { // keep changing till to iterators cross each other
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < rq_sum)
                j++;
            else if (sum > rq_sum)
                k--;
            else
            {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;

                // to skip the duplicates for iterators(j ,k)
                while (j < n && arr[j] == arr[j - 1])
                    j++;
                while (j < n && arr[k + 1] == arr[k])
                    k--;
            }
        }
    }
    return ans;
}

vector<vector<int>> triplet(vector<int> &arr, int n)
{
    set<vector<int>> st;

    for (int i = 0; i < n; i++)
    {
        set<int> hashset;
        for (int j = i + 1; j < n; j++)
        {
            // Calculate the 3rd element:
            int third = -(arr[i] + arr[j]);

            // Find the element in the set:
            if (hashset.find(third) != hashset.end())
            {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }

    // store the set in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

vector<vector<int>> triplet_brutte_force(int n, vector<int> &arr)
{
    set<vector<int>> st;

    // check all possible triplets:
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (arr[i] + arr[j] + arr[k] == 0)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }

    // store the set elements in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 2, 1, 0, 3, 1, -1, 2, 3, 0, -2, 1, -3, 6};
    int k = 4;
    int n = arr.size();
    vector<vector<int>> ans = triplet(arr, n);
    vector<vector<int>> ans2 = sum(arr, n, 0);

    int m = ans.size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout << " ***********" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << ans2[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
} 