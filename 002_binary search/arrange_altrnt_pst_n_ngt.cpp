using namespace std;
#include<vector>
#include<iostream>

vector<int> alternateNumbers(vector<int>&arr) {
    int n = arr.size();
    vector<int> temp(n);
    int j = 0, k = 1;
    for(int i = 0; i < n; i++){
        if(arr[i] > 0){
            temp[j] = arr[i];
            j+=2;
        }else{
            temp[k] = arr[i];
            k+=2;
        }
    }
    return temp;
}

     // doesnt matter if it contain equal no of signs or not
vector<int> RearrangebySign(vector<int>A, int n){
    
    // Define 2 vectors, one for storing positive 
    // and other for negative elements of the array.
    vector<int> pos;
    vector<int> neg;
    
    // Segregate the array into positives and negatives.
    for(int i=0;i<n;i++){
        
        if(A[i]>0) pos.push_back(A[i]);
        else neg.push_back(A[i]);
    }
    
    // If positives are lesser than the negatives.
    if(pos.size() < neg.size()){
        
      // First, fill array alternatively till the point 
      // where positives and negatives ar equal in number.
      for(int i=0;i<pos.size();i++){
        
        A[2*i] = pos[i];
        A[2*i+1] = neg[i];
      }
      
      // Fill the remaining negatives at the end of the array.
      int index = pos.size()*2;
      for(int i = pos.size();i<neg.size();i++){
          
          A[index] = neg[i];
          index++;
      }
    }
    
    // If negatives are lesser than the positives.
    else{
        
        // First, fill array alternatively till the point 
        // where positives and negatives ar equal in number.
        for(int i=0;i<neg.size();i++){
        
        A[2*i] = pos[i];
        A[2*i+1] = neg[i];
    }
      
      // Fill the remaining positives at the end of the array.
      int index = neg.size()*2;
      for(int i = neg.size();i<pos.size();i++){
          
          A[index] = pos[i];
          index++;
      }
    }
    return A;
      
  }
  
int main()
{
    vector<int> arr = {2, 2 , -1 , -1, 2, -1, 2 ,-1};
    vector<int> arr1 = alternateNumbers(arr);
    for(auto i : arr1){
        cout<<i<<" ";
    }
    return 0;
}