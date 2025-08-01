#include <iostream>
#include <vector>
using namespace std;

// bool isValid(vector<string>& temp, int i, int j, int n) {
//     for(int k = 0 ;k < n;k++){
//         if(temp[k][j] == 'Q' || temp[i][k] == 'Q')return false;
//     }
//     int x = i,y = j;
//     while(x >= 0 && y >= 0) if(temp[x--][y--] == 'Q')return false;
//     x = i;
//     y = j;
//     while(x >= 0 && y < n) if(temp[x--][y++] == 'Q')return false;
//     return true;
// }

// void generate(vector<vector<string>>& ans, vector<string>& temp, int i, int j, int n, int queens) {
//     if (queens == n) {
//         ans.push_back(temp);
//         return;
//     }
//     if (i >= n || j >= n) return;
//     if (isValid(temp, i, j, n)) {
//         temp[i][j] = 'Q';
//         generate(ans, temp, i + 1, 0, n, queens + 1);
//         temp[i][j] = '.';
//     }
//     generate(ans, temp, i,j+1 , n, queens);
// }



void generate2(vector<vector<string>>& ans, vector<string>& temp, int i, int n,vector<int>& cols,vector<int>& diag1,vector<int>& diag2){
    if(i == n){
        ans.push_back(temp);
        return ;
    }
    for(int col = 0; col < n; col++){
        if(cols[col] || diag1[col + i] || diag2[i -col + n -1])
            continue ;
        temp[i][col] = 'Q';
        cols[col] = diag1[col + i] = diag2[i - col + n -1] = 1;
        generate2(ans,temp,i+1,n,cols,diag1,diag2);
        
        temp[i][col] = '.';
        cols[col] = diag1[col + i] = diag2[i - col + n -1] = 0;
    }
}

vector<vector<string>> placeNQueens(int n) {
    vector<vector<string>> ans;
    vector<string> temp(n, string(n, '.'));
    vector<int> col(n,0);
    vector<int> diag1(2*n - 1,0);
    vector<int> diag2(2*n - 1,0);
    generate2(ans,temp,0,n,col,diag1,diag2);
    return ans;
}

int main() {
    int n = 4;
    vector<vector<string>> ans = placeNQueens(n);
    int cnt = 0;
    for(auto it : ans){
        for(auto it1 : it){
            cout<<it1<<" ";
        }
        cout<<"//"<<cnt<<endl;
        cnt++;
    }

    return 0;
}