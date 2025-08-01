#include <iostream>
#include <stack>
using namespace std;

string convertPrefixToInfix(string prefix){
    stack<string> st;
    for(int i = prefix.size() - 1;i >= 0; i--){
        string curr = string(1,prefix[i]);
        if(st.empty() || (curr >= "a" && curr<= "z") || (curr >= "A" && curr<= "Z") || (curr >= "0" && curr<= "9")){
            st.push(curr);
        }
        else{
            string temp = string("");
            temp += "(" + st.top() + curr;
            st.pop();
            temp+= st.top() + ")";
            st.pop();
            st.push(temp);
        }
    }
    return st.top();
}

int main() {
    string  prefix = "-+ab*cd";
    string infix = convertPrefixToInfix(prefix);
    cout<<"infix string is "<<infix<<"\n";
    return 0;
}