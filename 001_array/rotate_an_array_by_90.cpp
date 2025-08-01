using namespace std;
#include<vector>
#include<iostream>
#include<algorithm>
                    // OPTIAML
void rotate_vector_optimal(vector<vector<int>> &arr, int n){
    for(int i = 0 ; i < n-1; i++){          // we are just swaping upper triangle
        for(int j = i+1; j < n; j++){
            swap(arr[i][j], arr[j][i]);
        }
    }
    for(int i = 0; i < n; i++){
        reverse(arr[i].begin(), arr[i].end());
    }

}
                    // BRUTE FORCE 
void rotate_vector_better(vector<vector<int>> &arr, int n){
    vector<vector<int>> temp(arr);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n ; j++){
                arr[j][i] = temp[n-i-1][j];
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
    int n =arr.size();
    rotate_vector_optimal(arr, n);
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 0; j < arr[0].size(); j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
        }
    return 0;
}