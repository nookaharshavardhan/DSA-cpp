#include <iostream>
#include <vector>
using namespace std;


bool generate(vector<vector<char>>& board, string s,int i ,int j,vector<vector<bool>>& visited,int index){
    if(index == s.size())return true;
    if(i >= board.size() || j >= board[0].size() || i < 0 || j < 0 || visited[i][j] || board[i][j] != s[index]){
        return false;
    }
    visited[i][j] = true;

    bool find = generate(board,s,i,j+1,visited,index+1) ||
        generate(board,s,i+1,j,visited,index+1) ||
        generate(board,s,i,j-1,visited,index+1) ||
        generate(board,s,i-1,j,visited,index+1);
    visited[i][j] = false;
    return find;
}

bool exist(vector<vector<char>>& board, string s) {
    int n = board.size();
    int m = board[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for(int x = 0; x < n;x++){
        for(int y = 0; y < m;y++){
            if(generate(board,s,x,y,visited,0)){
                return true;
            }
        }
    }
    return false;
}

int main() {
    vector<vector<char>> arr = {
        { 'A', 'B', 'C', 'E' },
        { 'S', 'F', 'C', 'S' },
        { 'A', 'D', 'E', 'E' }
    };
    string s = "ABCESCEE";
    if(exist(arr,s)){
        cout<<"does"<<endl;
    }
    else cout<<"not"<<endl;
    return 0;
}