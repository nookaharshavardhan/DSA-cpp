#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

vector<int> left_tall_rect(const vector<int>&arr){
    stack<int> st;
    vector<int> left(arr.size(),0);
    for(int i = 0; i < arr.size() ; i++){
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        if(!st.empty()) left[i] = st.top() + 1;
        st.push(i);
    }
    return left;
}
vector<int> right_tall_rect(const vector<int>&arr){
    int n = arr.size();
    stack<int>st;
    vector<int> right(n ,n -1);
    for(int i = n - 1;i >= 0; --i){
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        if(!st.empty()) right[i] = right[i] = st.top() - 1;
        st.push(i);
    }
    return right;
}
int find_area_of_largest_rect(const vector<int>& arr){
    int area = INT_MIN;
    vector<int>left = left_tall_rect(arr);
    vector<int>right = right_tall_rect(arr);
    for(int i = 0;i < arr.size();++i){
        area = max(area,(right[i] - left[i] + 1)*arr[i]);
    }
    return area;
}

int main() {
    vector<int> arr ={2,1,5,6,2,3};
    int area_of_largest_rect = find_area_of_largest_rect(arr);
    cout<<area_of_largest_rect<<"\n";
    return 0;
}