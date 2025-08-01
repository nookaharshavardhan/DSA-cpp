#include <iostream>
#include <vector>
using namespace std;

void generate(vector<string>& vec,string s,int n,int right,int left){
    if(s.length() == 2*n){
        vec.push_back(s);
        return;
    }
    if(right < n) generate(vec,s+'(',n,right+1,left);

    if(left< right) generate(vec,s+')',n,right,left+1);
}


vector<string> generateParentheses(int n){
    vector<string>vec;
    generate(vec,"",n,0,0);
    return vec;
}
int main() {
    int n = 2;
    vector<string> st = generateParentheses(n);
    for(auto it: st){
        cout<<it<<endl;
    }
    return 0;
}