#include <iostream>
#include <stack>
using namespace std;

bool isCorrectAlt(char c,char alt){
    if(c =='(' && alt == ')')return true;
    if(c =='{' && alt == '}')return true;
    if(c =='[' && alt == ']')return true;
    return false;
}
bool recursive(const string& s,stack<int> &stk,int i){
    if(i == s.length()){
        return stk.empty();
    }
    char current = s[i];
    if(current == '('||current == '{'||current == '['){
        stk.push(current);
        return recursive(s,stk,i+1);
    }
    else{
        if(stk.empty() || !isCorrectAlt(stk.top(),current)){
            return false;
        }
        stk.pop();
        return recursive(s,stk,i+1);
    }
}

bool isValid(string s){
    stack<int> stk;
    return recursive(s,stk,0);
}

int main() {
    string s = "([)]";
    string s1 = "([{}])";
    string s2 = "([]{})";
    if(isValid(s)){
        cout<<s<<" is valid"<<endl;
    }
    else cout<<s<<" is not valid"<<endl;
    if(isValid(s1)){
        cout<<s1<<" is valid"<<endl;
    }
    if(isValid(s2)){
        cout<<s2<<" is valid"<<endl;
    }
    return 0;
}