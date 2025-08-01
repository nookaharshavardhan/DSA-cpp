#include <iostream>
#include <stack>
using namespace std;

stack<int> reverseStack(stack<int> st){
    stack<int> temp;
    while(!st.empty()){
        temp.push(st.top());
        st.pop();
    }
    return temp;
}

void insertAtBottom(stack<int>& st , int curr){
    if(st.empty()){
        st.push(curr);
        return ;
    }
    int val = st.top();
    st.pop();
    insertAtBottom(st,curr);
    st.push(val);
}

void reverseStackRecurssion(stack<int>& st){
    if(st.empty())return ;
    int curr = st.top();
    st.pop();
    reverseStackRecurssion(st);
    insertAtBottom(st,curr);
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);

    stack<int> ans = st;
    cout<<"before reversal : ";
    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }cout<<endl;

    st = reverseStack(st);
    ans = st;
    cout<<"after normal reversal : ";
    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }cout<<endl;

    reverseStackRecurssion(st);
    ans = st;
    cout<<"after recursion reversal : "; 
    while(!ans.empty()){
        cout<<ans.top()<<" ";
        ans.pop();
    }cout<<endl;


    return 0;
}
