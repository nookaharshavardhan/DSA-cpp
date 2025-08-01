using namespace std;
#include<iostream>

string reverseWords(string s) {
    int n = s.size();
    int index = n -1;
    string ans;
    int cnt = 0;
    for(int i = n - 1; i <= 0; i--){
        if(s[i] == ' '){
            ans += s.substr(i,cnt);
            for(auto it : ans){
                cout<<it<<" ";
             }cout<<endl;
            cnt = 0;
        }
        else cnt++;
    }
    return ans;
}


int main()
{
    string s = "the sky is blue";
    string ans = reverseWords(s);
    for(auto it : ans){
       cout<<it<<" ";
    }cout<<endl;
     return 0;
}