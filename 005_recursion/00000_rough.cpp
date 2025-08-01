#include <iostream>
#include <stack>
using namespace std;

void sort_stack(stack<int>& st){
    
}

int main() {
    stack<int> st;
    st.push(1);
    st.push(7);
    st.push(3);
    st.push(5);
    st.push(6);
    st.push(4);
    st.push(2);
    sort_stack(st);
    for(int i =0; i < st.size();i++){
        cout<<st.top();
        st.pop();
    }
}

  
