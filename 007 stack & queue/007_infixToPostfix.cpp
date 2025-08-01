#include <iostream>
#include <stack>
using namespace std;

int precedence(const char c){
    if(c == '^')return 3;
    else if(c== '*' || c== '/')return 2;
    else if (c== '+' || c == '-')return 1;
    return -1;
}


string convert_infix_to_postfix(const string& infix){
    stack<char> st;
    string postfix = string("");
    for(int i = 0; i < infix.size();i++){

        char curr = infix[i];
        if(curr == ' '){
            continue;
        }
        if((curr >= 'a' && curr <= 'z') || (curr >= 'A' && curr <= 'Z')){
            postfix += curr;
        }
        else if(curr == '('){
            st.push(curr);              //pushing it here instead of line 41 is case in '(' has low precedence
        }
        else if(curr == ')'){                                                     //a+b*(c^d-e)^(f+g*h)-i
            while(st.top() != '('){
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        
        else{
            while(!st.empty() && precedence(curr) <= precedence(st.top())){
                postfix += st.top();
                st.pop();
            }
            st.push(curr);
        }
    }
    while(!st.empty()){
        postfix += st.top();
        st.pop();
    }
    return postfix;
}

int main() {
    string infix = "a    + b -  c";
    string postfix = convert_infix_to_postfix(infix);
    cout<<postfix<<"\n";
    return 0;
}