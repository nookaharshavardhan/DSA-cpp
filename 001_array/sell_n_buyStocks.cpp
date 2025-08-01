using namespace std;
#include<vector>
#include<iostream>


int maxProfit(vector<int>& arr){
    int maxi = 0;
    int min;
    min  = arr[0];
    int n = arr.size();
    for(int i =1; i < n; i++){
        if(arr[i] < min) min = arr[i];
        if(arr[i] - min > maxi) maxi = arr[i] - min;
    }
    return maxi;
}

          // brute force
int maxProfit_1(vector<int>& arr) {
        int maxi = 0;
        int min;
        int n = arr.size();
        for(int i = 0; i < n ; i++){
            for(int j = i + 1 ; j < n; j++){
              if(arr[j] - arr[i] > maxi) maxi = arr[j] -arr[i];  
            }
        }
        if(maxi < 0) return 0;
        return maxi; 
    }
int main()
{
    vector<int> arr = {7,1,5,3,6,4};
    int n = maxProfit(arr);
    cout<<n<<endl;
    return 0;
}