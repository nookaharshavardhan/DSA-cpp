using namespace std;
#include<iostream>
#include<vector>

string process_string(string str){
    string ans = "^";
    for(int i = 0; i < str.size(); i++){
        ans += "#";
        ans += string(1,str[i]);
    }
    ans += "#$";
    return ans;
}

string longestPalindrome(string str) {
    int mirror = -1;
    int c = 0;
    int r = 0;
    int i = 0;
    int largest_pal_centre = 0;
    int largest_pal_len = 0;
    string str1 = process_string(str);
    int n = str1.size();
    vector<int> p(n,0);
    for(i = 1 ; i < n - 1;i++){
        mirror = 2 * c - i;
        if(i < r){
            p[i] = min(p[mirror],r-i);
        }
        while( str1[i + p[i]+1] == str1[i -p[i]-1]){
            p[i]++;
        }
        
        if(p[i] > largest_pal_len){
            largest_pal_len = p[i];
            largest_pal_centre = i;
        }

        if(i + p[i] > r){
            c = i;
            r = i + p[i];
        }
    }
    int start = (largest_pal_centre - largest_pal_len)/2;
    int end = start + largest_pal_len;
    return str.substr(start,largest_pal_len);  
}


int main()
{
    string s = "12332112344321678";
    string ans = longestPalindrome(s);
    cout<<ans<<endl;
    return 0;
}

