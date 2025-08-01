using namespace std;
#include<vector>
#include<iostream>

//                       brutte force
void set_zeros(vector<vector<int>> &matrix, int n, int m) {   
	int row_sz = matrix.size();
	int column_sz = matrix[0].size();
	int k;
	vector<int>row(row_sz,0);
	vector<int>col(column_sz, 0);
	for(int i = 0; i < row_sz; i++){
		for(int j = 0; j < column_sz ; j++){
			if(matrix[i][j] == 0){
				row[i] = 1;
				col[j] = 1;
			}
		}
	}
	for(int i = 0; i < row_sz; i++){
		for(int j = 0; j < column_sz ; j++){
			if(row[i] == 1 || col[j] == 1){
				matrix[i][j] = 0;
			}
		}
	}
}
                            //BETTER
void markRow(vector<vector<int>> &matrix, int n, int m, int i) {
    // set all non-zero elements as -1 in the row i:
    for (int j = 0; j < m; j++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}


void markCol(vector<vector<int>> &matrix, int n, int m, int j) {
    // set all non-zero elements as -1 in the col j:
    for (int i = 0; i < n; i++) {
        if (matrix[i][j] != 0) {
            matrix[i][j] = -1;
        }
    }
}

vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {

    // Set -1 for rows and cols
    // that contains 0. Don't mark any 0 as -1:

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                markRow(matrix, n, m, i);
                markCol(matrix, n, m, j);
            }
        }
    }

    // Finally, mark all -1 as 0:
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == -1) {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

                // OPTIMAL
void setZeroes(vector<vector<int>>& arr) {
	int n = arr.size();
	int m = arr[0].size(); 
	int col0 = 1;

	// Traverse the arr and mark first cell 
    // of each row and column
	for(int i = 0 ; i < n ; i++){
		for(int j = 0; j < m ; j++){
			if(arr[i][j] == 0){

				//mark i-th row
				arr[i][0] = 0;

				// mark j-th colum & if it is 0th 
				// colum mark col0 as 0 else mark the respective jth colum
				if(j == 0) 
				   col0 = 0;
				else 
				   arr[0][j] =0;
			}
		}
	}	

	// Traverse and mark the matrix from (1, 1)
    // to (n - 1, m - 1)
	for(int i = 1; i < n ; i++){
		for(int j = 1; j < m ; j++){
			if(arr[i][0] == 0) arr[i][j] = 0;
			if(arr[0][j] == 0) arr[i][j] = 0;
		}
	}

	// changing the first cell cause if we cahnge
	// second cell first elements will ber changed
	if(arr[0][0] == 0){
		for(int j = 0; j < m ; j++){
			arr[0][j] = 0;
		}
	}

	
	if(col0 == 0){
		for(int i = 0; i < n; i++){
			arr[i][0] = 0;
		}
	}
}

int main()
{
    vector<vector<int>>arr = {
        {1,33,5,7,6,12},
        {18,34,9,6,8,10},
        {0,10,90,38,12,11}
    };
    int n = arr.size();
    int m = arr[0].size();
    setZeroes(arr);
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < m; j++){
            cout<<arr[i][j]<<" ";
        }cout<<endl;
    }
    return 0;
}