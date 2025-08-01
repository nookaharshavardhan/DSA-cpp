#include <iostream>
#include <stack>
#include<algorithm>
using namespace std;

int precedence(const char c){
    if(c == '^')return 3;
    else if(c== '*' || c== '/')return 2;
    else if (c== '+' || c == '-')return 1;
    return -1;
}

string convert_infix_to_prefix(const string& infix){
    string prefix = string("");
    stack<char>st;
    for(int i = infix.size() - 1;i >= 0;i--){
        char curr = infix[i];
        cout<<"current is : "<<curr<<"\n";
        if( (curr >= 'a' && curr <= 'z') || (curr >= 'A' && curr <= 'Z') ){
            prefix += curr;
        }
        else if(curr == ')')st.push(curr);
        else if(curr == '('){
            while(st.top() != ')'){
                prefix += st.top();
                st.pop();
            }
            st.pop();
        }
        else{
            while(!st.empty() && precedence(curr) < precedence(st.top())){
                prefix += st.top();
                st.pop();
            }
            st.push(curr);
        }
    }
    while(!st.empty()){
        prefix += st.top();
        st.pop();
    }
    reverse(prefix.begin(),prefix.end());
    return prefix;
}

int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";      //- + a * b ^ - ^ c d e + f * g h i
    string prefix = convert_infix_to_prefix(infix);
    cout<<prefix<<endl;
    return 0;
}