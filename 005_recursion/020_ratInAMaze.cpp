#include <iostream>
#include <vector>
using namespace std;

void generate(vector<vector<int>>&  maze,vector<string>&  ans,string& temp,vector<vector<int>>& visited,int i,int j,int n){
    if(i == n-1 && j == n-1){
        ans.push_back(temp);
        return ;
    }

    string direction = "DRLU";
    vector<int> d1 = {1,0,0,-1};
    vector<int> d2 = {0,1,-1,0};
    for(int k = 0; k < 4;k++){
        int ni = i + d1[k];
        int nj = j + d2[k];

        if(ni >= 0 && nj >= 0 && ni < n && nj < n && visited[i][j] == 0 && maze[i][j] == 1){
            visited[i][j] = 1;
            temp.push_back(direction[k]);
            generate(maze,ans,temp,visited,ni,nj,n);
            visited[i][j] = 0;
            temp.pop_back();
        }
    }
}

vector<string> ratInMaze(vector<vector<int>>& maze,int n) {
    vector<string> ans;
    string temp;
    int i = 0,j = 0;
    vector<vector<int>> visited(n,vector<int>(n,0));
    generate(maze,ans,temp,visited,i,j,n);
    return ans;
}

int main() {
    vector<vector<int>> maze = {{1, 0, 0, 0} , {1, 1, 0, 1} , {1, 1, 0, 0},{0, 1, 1, 1}};
    int n = maze.size();
    vector<string> ans = ratInMaze(maze,n);
    for(auto it: ans){
        cout<<it<<" ";
    }cout<<endl;
    return 0;
}