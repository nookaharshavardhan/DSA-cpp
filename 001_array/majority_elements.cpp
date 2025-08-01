using namespace std;
#include<iostream>
#include<set>
#include<vector>

vector<int> majority(vector<int> arr, int n){
    int el1, el2;
    int cnt1 = 0;
    int cnt2 = 0;
    for(auto num : arr){
        if(num == el1){
            cnt1++;
        }
        else if(num == el2){
            cnt2++;
        }
        else if(cnt1 == 0){
            cnt1 = 1;
            el1 = num;
        }
        else if(cnt2 == 0){
            cnt2 = 1;
            el2 = num;
        }
        else{
            cnt1 --;
            cnt2--;
        }
    }
    cnt1 = 0;
    cnt2 = 0;
    for(auto num : arr){
        if(el1 == num ) cnt1++;
        else if(el2 == num )cnt2++;
    }
    vector<int> temp;
    if(cnt1 > n/3) temp.push_back(el1);
    if(cnt2 > n/3) temp.push_back(el2);
    return temp;
}

int main()
{
    vector<int> arr = {2, 1, 1, 0, 1, 1, 0, 2, 1, 1, 0, 0, 0};
    int n = arr.size();
    vector<int> res =  majority(arr, n);
    for(auto i : res){
        cout<<i<<" "; 
    }
    return 0;
}
