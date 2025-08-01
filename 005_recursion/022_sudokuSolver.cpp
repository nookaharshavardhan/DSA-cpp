#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<char>>& sudoku,int i,int j,int k){
    for(int x = 0 ; x < 9;x++){
        if(sudoku[i][x] == k)return false;
        if(sudoku[x][j] == k)return false;

        int boxRow = 3 * (i / 3) + x / 3;
        int boxCol = 3 * (j / 3) + x % 3;
        if (sudoku[boxRow][boxCol] == k)
            return false;
    }
    return true;
}

bool generate(vector<vector<char>>& sudoku,int i,int j){
    if(i == 9)
        return true;
    if(j == 9)
        return generate(sudoku,i+1,0);
    if(sudoku[i][j] != '.') return generate(sudoku,i,j+1);
    for(char k = '1' ; k <= '9';k++){
        if(isSafe(sudoku,i,j,k)){
            sudoku[i][j] = k;
            if(generate(sudoku,i,j+1)) return true;
            sudoku[i][j] = '.';
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>>& sudoku){
    generate(sudoku,0,0);
}

int main()
{
    vector<vector<char>> sudoku = { { '5', '3', '.', '.', '7', '.', '.', '.', '.' }, { '6', '.', '.', '1', '9', '5', '.', '.', '.' }, { '.', '9', '8', '.', '.', '.', '.', '6', '.' }, { '8', '.', '.', '.', '6', '.', '.', '.', '3' }, { '4', '.', '.', '8', '.', '3', '.', '.', '1' }, { '7', '.', '.', '.', '2', '.', '.', '.', '6' }, { '.', '6', '.', '.', '.', '.', '2', '8', '.' }, { '.', '.', '.', '4', '1', '9', '.', '.', '5' }, { '.', '.', '.', '.', '8', '.', '.', '7', '9' } };
    cout<<"before filling"<<endl;
    for(auto it : sudoku){
        for(auto it1 : it){
            cout<<it1<<' ';
        }cout<<endl;
    }
    solveSudoku(sudoku);
    cout<<"after solving"<<endl;
    for(auto it : sudoku){
        for(auto it1 : it){
            cout<<it1<<' ';
        }cout<<endl;
    }
}