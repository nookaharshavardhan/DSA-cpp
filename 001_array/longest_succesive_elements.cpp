using namespace std;
#include<vector>
#include<limits.h>
#include<algorithm>
#include<iostream>
#include<unordered_set>


int longestSuccessiveElements_better(vector<int>&arr) {
    int count = 0;
    int max_count = 0;
    int n = arr.size();
    int last_num = INT_MIN;
    sort(arr.begin(), arr.end());
    for(int i = 0; i < n; i++){
        if(arr[i]-1 == last_num){
            count++;
        }
        else if(arr[i] != last_num) count = 1;
        max_count = max(max_count, count);
        last_num = arr[i];
    }
    return max_count;
}

int longestSuccessiveElements(vector<int>&a) {  //optimized
    int n = a.size();
    if (n == 0) return 0;

    int longest = 1;
    unordered_set<int> st;
    //put all the array elements into set:
    for (int i = 0; i < n; i++) {
        st.insert(a[i]);
    }

    //Find the longest sequence:
    for (auto it : st) {
        //if 'it' is a starting number:
        if (st.find(it - 1) == st.end()) {
            //find consecutive numbers:
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;

}


int main()
{
    vector<int> arr = {1,2,3,5,6,2,2,4,7,9,0,6,4,3,5,8,8,7,2,3,7,8};
    int n = longestSuccessiveElements(arr);
    cout<<n<<endl;
     
    return 0;
}