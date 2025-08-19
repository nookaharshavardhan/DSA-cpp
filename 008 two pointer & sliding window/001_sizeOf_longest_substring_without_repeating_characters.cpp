#include <iostream>
#include <unordered_map>
using namespace std;

int find_long_subs(string s){
    int left = 0;
    int max_size=0;
    unordered_map<char,int>mpp;
    for(int right = 0; right <s.size(); ++right){
        if(mpp.find(s[right]) != mpp.end()){
            left = max(left, mpp[s[right]] + 1);
        }
        max_size = max(max_size,right - left + 1);
        mpp[s[right]] = right;
    }
    return max_size;
}

int main() {
    string  s = "abcabcbbasdfghjkl";
    int large_string = find_long_subs(s);
    cout<<large_string<<"\n";
    return 0;
}