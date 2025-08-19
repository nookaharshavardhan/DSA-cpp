#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int flip_n_max_consicutive_string(vector<int> arr,int k){
    int zero_cnt = 0,left = 0,max_subs = 0;
    for(int i = 0; i < arr.size() ; ++i){
        if(arr[i] == 0)zero_cnt++;
        while(zero_cnt > k){
            if(arr[left] == 0)zero_cnt--;
            left++;
        }
        max_subs = max(max_subs,i - left + 1);
    }
    return max_subs;
}


int main() {
    vector<int> arr = {1,1,1,0,0,0,1,1,1,1,0};
    int n = flip_n_max_consicutive_string(arr,2);
    cout<<n<<"\n";
    return 0;
}