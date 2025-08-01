using namespace std;
#include<iostream>

bool rotateString(string s, string t){
    int n = s.size();
    int rt_st_ind;
    if(n != t.size())return false;
    bool match;
    for(int rt_st_ind = 0; rt_st_ind < n;rt_st_ind++){
        if(t[rt_st_ind] == s[0]){
            match = true;
            for(int i = 0 ; i <n ;i++){
                int rotated_index = (rt_st_ind + i) % n;
                if(s[i] != t[rotated_index]) match = false;
            }
        }
        if(match) return true;
    }
    return false;
}


int main()
{
    string s = "defdefdefabcabc";
    string t = "defdefabcabcdef";
    if(rotateString(s,t)) cout<<"true";
    else cout<<"false";
    return 0;
}