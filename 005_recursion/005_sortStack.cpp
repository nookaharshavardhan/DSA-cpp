#include <iostream>
#include<stack>
using namespace std;

stack<int> sortStack(stack<int> st){
    stack<int> temp;
    while(!st.empty()){
        int current = st.top();
        st.pop();

        while(!temp.empty() && temp.top() > current){
            st.push(temp.top());
            temp.pop();
        }
        temp.push(current);
    }
    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }
    return st;
}

void insertIndex(stack<int>& st,int curr){
    if(st.empty() || st.top() >= curr){
        st.push(curr);
        return ;
    }
    int val = st.top();
    st.pop();
    insertIndex(st,curr);
    st.push(val);
}

void sortStackRecurssion(stack<int>& st){
    if(st.empty())return ;
    int curr = st.top();
    st.pop();
    sortStackRecurssion(st);
    insertIndex(st,curr);
}

int main() {
    stack<int> st;
    st.push(3);
    st.push(2);
    st.push(4);
    st.push(1);
    st.push(5);
    st.push(4);
    st.push(6);
    stack<int> ans = sortStack(st);
    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }cout<<endl;
    stack<int> st1;
    st1.push(3);
    st1.push(2);
    st1.push(4);
    st1.push(1);
    st1.push(5);
    st1.push(4);
    st1.push(6);
    sortStackRecurssion(st1);
    while(!st1.empty()){
        cout<<st1.top()<<" ";
        st1.pop();
    }cout<<endl;
    return 0;
}