#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> find_next_greatest_element(const vector<int>& arr){
    stack<int>st;
    vector<int> ans(arr.size(),-1);
    for(int i = arr.size() - 1;i >= 0; --i){
        if(arr[i] < st.top()){
            ans[i] = st.top();
            if(st.empty()){
                ans[i] = -1;
            }
            st.push(arr[i]);
        }
        else{
            while(st.top() <= arr[i]){
                st.pop();
                
            }
            if(st.empty()){
                    ans[i] = -1;
            }
            else
                ans[i] = st.top();
            st.push(arr[i]);
        }
    }
    return ans;
}

int main() {
    vector<int> arr = {3,10,4,2,1,2,6,1,7,2,9};
    vector<int> next_greatest_elements = find_next_greatest_element(arr);
    for(auto it: next_greatest_elements){
        cout<<it<<" ";
    }cout<<"\n";
    return 0;
}




/*
{3,10,4,2,1,2,6,1,7,2,9}

i        stack     ans

9        9          -1
2        9,2        9,-1
7        9,7        9,9,-1
1        9,7,1      7,9,9,-1
6        9,7,6      7,7,9,9,-1
2        9,7,6,2    6,7,7,9,9,-1
1        9,7,6,2,1  2,6,7,7,9,9,-1
2        9,7,6,2    6,2,6,7,7,9,9,-1
4        9,7,6,4    6,6,2,6,7,7,9,9,-1
10       10         -1,6,6,2,6,7,7,9,9,-1
3        10,3       10,-1,6,6,2,6,7,7,9,9,-1
*/