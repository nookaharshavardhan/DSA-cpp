using namespace std;
#include<iostream>

int pascal_triangle_recursion(int row, int column){
    if(column == 0 || column == row){
        return 1;
    }
    int n = pascal_triangle_recursion(row - 1, column);
    int m = pascal_triangle_recursion(row - 1, column -1);
    return n+m;
}


int pscl_trngl_singl_num(int row, int col){
    int res = 1;
    for(int i = 0; i < col ; i++){
        res = res * (row - i);
        res = res / (i+1); //   10 c 3 = 10 /1    *  9/2  *   8/3
        }                 //   no need to use float cause it will gt multiplies correctly              
    return res;
}


int pscl_trngl_reqired_row(int row){
    int res = 1;
    cout<<res<<" ";
    for(int i = 0; i < row ; i++){
        res = res * (row - i);
        res = res / (i+1);   //   10 c 3 = 10 /1    *  9/2  *   8/3
        cout<<res<<" ";     //   no need to use float cause it will gt multiplies correctly                 
    }cout<<endl;
    return res;
}


void pscl_triangle(int row){
   
    for(int i = 0; i <row; i++){
        int res = 1;
        cout<<res<<" ";
        for(int j = 1; j <=i; j++){
            res = res * (i - j + 1);
            res = res / (j);
            cout<<res<<" ";
        }cout<<endl;
    }
}
int main()
{   
    // int m = pascal_triangle_recursion(10, 6);
    // int n = pscl_trngl_singl_num(10, 6);
    // int z = pscl_trngl_reqired_row(6);
    // cout<<m<<" "<<n<<endl;
    pscl_triangle(3);
    return 0;
}