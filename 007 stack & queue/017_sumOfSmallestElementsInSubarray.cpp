#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> find_prev_min_elem_of_indices(const vector<int>& arr){
    int n = arr.size();
    stack<int> st;
    vector<int> ans(n,-1);     // -1 cause it should be smallest among first  i - (pse[i]) elements means i + 1 elements;
    for(int i = 0; i < n;i++){
        while(!st.empty() && arr[st.top()] > arr[i]){          // not >= cause of edge cases like {1,1};
            st.pop();
        }
        if(!st.empty()){
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}

vector<int> find_next_min_elem_of_indices(const vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n,n);      // n cause it should be smallest element till the end of array means (nse[i] - i)->it gives size till end from i     
    stack<int> st;
    for(int i = arr.size() - 1;i >= 0; --i){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        if(!st.empty()){
            ans[i] = st.top();
        }
        st.push(i);
    }
    return ans;
}
int find_sum_of_smallest_elements_in_subarray(const vector<int>& arr){
    int mod = 10e+7;
    vector<int> pse = find_prev_min_elem_of_indices(arr);
    vector<int> nse = find_next_min_elem_of_indices(arr);
    int sum = 0;
    for(int i = 0; i < arr.size(); ++i){
        int left = i - pse[i];
        int right = nse[i] - i;
        int temp = (((1LL*left*arr[i])%mod)*right)%mod;
        sum = (sum + temp)%mod;
    }
    return sum;
}

int main() {
    vector<int> arr = {3,1,2,4};
    int sum_of_smallest_elements_in_subarray = find_sum_of_smallest_elements_in_subarray(arr);
    cout<<sum_of_smallest_elements_in_subarray<<"\n";
    return 0;
}                                                      // 1   4   6   7   3   7   8   1
                                                      //  13  3   2   2   12  2   1   13


/*

[1] -> 1  
[4] -> 4  
[6] -> 6  
[7] -> 7  
[3] -> 3  
[7] -> 7  
[8] -> 8  
[1] -> 1

[1, 4] -> 1  
[4, 6] -> 4  
[6, 7] -> 6  
[7, 3] -> 3  
[3, 7] -> 3  
[7, 8] -> 7  
[8, 1] -> 1  

[1, 4, 6] -> 1  
[4, 6, 7] -> 4  
[6, 7, 3] -> 3  
[7, 3, 7] -> 3  
[3, 7, 8] -> 3  
[7, 8, 1] -> 1

[1, 4, 6, 7] -> 1  
[4, 6, 7, 3] -> 3  
[6, 7, 3, 7] -> 3  
[7, 3, 7, 8] -> 3  
[3, 7, 8, 1] -> 1  

[1, 4, 6, 7, 3] -> 1  
[4, 6, 7, 3, 7] -> 3  
[6, 7, 3, 7, 8] -> 3  
[7, 3, 7, 8, 1] -> 1  

[1, 4, 6, 7, 3, 7] -> 1  
[4, 6, 7, 3, 7, 8] -> 3  
[6, 7, 3, 7, 8, 1] -> 1  

[1, 4, 6, 7, 3, 7, 8] -> 1  
[4, 6, 7, 3, 7, 8, 1] -> 1  

[1, 4, 6, 7, 3, 7, 8, 1] -> 1

*/