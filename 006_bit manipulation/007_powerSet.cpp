#include <iostream>
#include <vector>
using namespace std;


vector<vector<int>> power_Set(vector<int> arr,int nofSubsets){
    vector<vector<int>> ans;
    for(int i = 1; i<=nofSubsets;i++){
        vector<int> temp;
        int cnt = 0;
        while(cnt < arr.size()){
            if(( (i >> cnt)& 1) == 1){
                temp.push_back(arr[cnt]);
            }
            cnt++;
        }
        ans.push_back(temp);
    }
    return ans;
}

int main() {
    vector<int> arr = {1,2,3};
    int n=arr.size();
    int nofSubsets = 1<<n;
    vector<vector<int>> powerSet = power_Set(arr,nofSubsets);
    for(auto it : powerSet){
        for(auto it1 : it){
            cout<<it1<<" ";
        }cout<<endl;
    }

    return 0;
}