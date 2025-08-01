#include <iostream>
#include <stack>
using namespace std;

string convertPostfixToInfix(string postfix){
    stack<string> st;
    for(int i = 0; i < postfix.size() ;++i){
        string curr = string(1,postfix[i]);
        if(st.empty() || (curr >= "a" && curr <= "z") || (curr >= "A" && curr<= "Z") || (curr >= "0" && curr<= "9")){
            st.push(curr);
        }
        else{
            string temp = st.top(); st.pop();
            string temp1 = "("+st.top() +curr+ temp+ ")"; st.pop();
            st.push(temp1);
        }
    }
    return st.top();
}

int main() {
    string postfix = "abcd^e-fgh*+^*+i-";
    string infix = convertPostfixToInfix(postfix);
    cout<<infix<<"\n";
    return 0;
}