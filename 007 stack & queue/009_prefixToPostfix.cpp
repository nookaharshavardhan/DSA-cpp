#include <iostream>
#include <stack>
using namespace std;

void convertPrefixToPostfix(const string& prefix,string& postfix){
    stack<string>st;
    for(int i = prefix.size()-1;i>= 0;--i){
        string curr = string(1,prefix[i]);
        if(curr >= "a" && curr <= "z"){
            st.push(curr);
        }
        else{
            postfix = st.top();
            st.pop();
            postfix += st.top() + curr;
            st.pop();
            st.push(postfix);
        }
    }
    postfix = st.top();
}

int main() {
    string prefix= "-+a*b^-^cde+f*ghi";      // otpt :abcd^e-fgh*+^*+i-
    string postfix = string("");
    convertPrefixToPostfix(prefix,postfix);
    cout<<postfix<<"\n";
    return 0;
}