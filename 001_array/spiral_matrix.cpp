using namespace std;
#include<vector>
#include<iostream>

vector<int> spiralOrder(vector<vector<int>>& arr) {
    vector<int>temp;
    int n = arr.size();
    int m = arr[0].size();
    int top = 0;
    int left = 0;
    int right = m-1;
    int bottom = n-1;

    while(top <= bottom && left <= right)
    {
        for(int i = left ; i <= right ; i++){
            temp.push_back(arr[top][i]);
        }top++;

        for(int i = top ; i <= bottom; i++){
            temp.push_back(arr[i][right]);
        }right--;

        if(top <= bottom){      // writing if satement for this two 
        // forloops  because top and right changes after first two loops
            for(int i = right; i >= left; i--){
                temp.push_back(arr[bottom][i]);
            }bottom--;
        }

        if(left <= right){
            for(int i = bottom; i >= top; i--){
                temp.push_back(arr[i][left]);
            }left++;
        }
    }
    return temp;

}


int main()
{
    vector<vector<int>> arr = {
        {1,2,3,4,5,6,7},
        {8,9,10,11,12,13,14},
        {15,16,17,18,19,20,21}
    };
    vector<int> ans = spiralOrder(arr);
     for(auto i : ans){
        cout<<i<<" ";
     }
    return 0;
}