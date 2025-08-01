#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>>& adj,vector<int> & color,int m,int v,int node,int col){
    for(auto adjacentNode : adj[node]){
        if(color[adjacentNode] == col)return false;
    }
    return true;
}

bool check(vector<vector<int>>& adj,vector<int> & color,const int& m,const int& v,int node){
    if(node == v)return true;
    for(int col = 1;col <= m ; col++){
        if(isSafe(adj,color,m,v,node,col)){
            color[node] = col;
            if(check(adj,color,m,v,node+1))return true;
            color[node] =  0;
        }
    }
    return false;
}

bool canColorGraph(vector<vector<int>> & edges,int m ,int v){
    vector<vector<int>> adj(v);
    for(auto it : edges){
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }
    vector<int> color(v,0);
    if(check(adj,color,m,v,0)){
        return true;
    }
    return false;
}
int main() {
    int m = 3;
    int v = 4;
    vector<vector<int>> edge = {{0, 1}, {1, 3}, {2, 3}, {3, 0}, {0, 2}};
    if(canColorGraph(edge,m,v)){
        cout<<"can colur the graph";
    }
    else cout<<"cannot color the graph"<<endl;
    return 0;
}