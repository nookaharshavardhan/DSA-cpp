using namespace std;
#include<iostream>
#include<vector>

void rotateMatrix(vector<vector<int>> &arr, int n, int m)
{
    int top = 0;
    int left = 0;
    int right = m-1;
    int bottom = n-1;
    int prev;
    while(top < bottom && left < right)   // no = sign becouse we leave single
                                         //  row or col  we dont need to rotate it 
    {
        prev = arr[top+1][left];
        for(int i = left ; i <= right ; i++){
            swap(prev,arr[top][i]);
        }top++;
        for(int i = top ; i <= bottom; i++){
            swap(prev,arr[i][right]);
        }right--;
        if(top <= bottom){      // writing if satement for this two 
        // forloops  because top and right changes after first two loops
            for(int i = right; i >= left; i--){
                swap(prev, arr[bottom][i]);
            }bottom--;
        }
        if(left <= right){
            for(int i = bottom; i >= top; i--){
                swap(prev, arr[i][left]);
            }left++;
        }
    }
}

int main()
{
    vector<vector<int>>arr = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    int n = arr.size();
    int m = arr[0].size();
    rotateMatrix(arr,n,m);
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
        }
    return 0;
    return 0;
}
