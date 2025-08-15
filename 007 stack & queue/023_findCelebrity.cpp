#include <iostream>
#include <vector>
using namespace std;

int celebrity(vector<vector<int> >& mat) {
    int cand = 0;
    for(int i = 0; i < mat[0].size();++i){
        if(mat[cand][i] == 1)cand = i;
    }
    for(int i = 0; i < mat[0].size() ; ++i){
        if(cand != i && (mat[cand][i] == 1 || mat[i][cand] == 0))return -1;
    }
    return cand;
}

int main() {
    vector<vector<int>> mat = {{0,1,1,0},{0,0,0,0},{0,1,0,0},{1,1,0,0}};
    int celeb = celebrity(mat);
    cout<<celeb<<"\n";
    return 0;
}