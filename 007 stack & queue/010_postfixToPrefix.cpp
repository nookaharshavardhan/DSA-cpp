#include <iostream>
#include <stack>
using namespace std;

string convertPostfixToPrefix(string postfix){
    stack<string> st;
    for(int i = 0; i < postfix.size() ;++i){
        string curr = string(1,postfix[i]);
        if(st.empty() || (curr >= "a" && curr<= "z") || (curr >= "A" && curr<= "Z") || (curr >= "0" && curr<= "9")){
            st.push(curr);
        }
        else{
            string temp = st.top(); st.pop();
            string temp1 = curr + st.top() + temp; st.pop();
            st.push(temp1);
        }
    }
    return st.top();
}


int main() {
    string postfix = "abcd^e-fgh*+^*+i-";  //a+b*(c^d-e)^(f+g*h)-i         -+a*b^-^cde+f*ghi 
    string prefix = convertPostfixToPrefix(postfix);
    cout<<prefix<<"\n";
    return 0;
}