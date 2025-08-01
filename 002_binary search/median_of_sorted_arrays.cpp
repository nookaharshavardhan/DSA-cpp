using namespace std;
#include<iostream>
#include<vector>

double naive_approach(vector<int>& arr1, vector<int> & arr2){
    int n = arr1.size();
    int m = arr2.size();
    int left = 0,right = 0;
    vector<int>temp;
    while(left < n && right < m){
        if(arr1[left] > arr2[right]){
            temp.push_back(arr2[right]);
            right++;
        }
        else{
            temp.push_back(arr1[left]);
            left++;
        }
    }
    while(left < n){
        temp.push_back(arr1[left]);
        left++;
    }
    while(right < m){
        temp.push_back(arr2[right]);
        right++;
    }
    int sz = temp.size();
    if(sz % 2 == 1) return (double)temp[sz / 2];
    double x = ((double)(temp[(sz/2) - 1]) + (double)(temp[sz/2]))/2;
    if(x < 0 ) return 0;
    return x; 
}

double better_approach(vector<int> & arr1,vector<int> & arr2){
    int n = arr1.size();
    int m = arr2.size();
    if(n == 0) {
        if(m % 2 == 1) return (double)arr2[m/2];
        return (double)(arr2[m/2]+arr2[(m/2)-1])/2.0;
    }
    if(m == 0) {
        if(n % 2 == 1) return (double)arr1[n/2];
        return (double)((arr1[n/2]+arr1[(n/2)-1])/2.0);
    }
    double ind2 = (n + m) / 2;
    double ind1 = (n+m)/2 -1;
    int ind1el = -1,ind2el = -1;
    int i = 0,j = 0;
    int cnt = 0;
    int point;
    while(i < n && j < m){
        if(arr1[i] <= arr2[j]){
            if(cnt == ind1) ind1el = arr1[i];
            if(cnt == ind2) ind2el = arr1[i];
            cnt++;
            i++;
        }
        else{
            if(cnt == ind1) ind1el = arr2[j];
            if(cnt == ind2) ind2el = arr2[j];
            cnt++;
            j++;
        }
        if (ind1el != -1 && ind2el != -1) break;
    }
    while(i < n && (ind1el == -1 || ind2el == -1)){
        if(cnt == ind1) ind1el = arr1[i];
        if(cnt == ind2) ind2el = arr1[i];
        cnt++;
        i++;
    }
    while(j < m && (ind1el == -1 || ind2el == -1)){
        if(cnt == ind1) ind1el = arr2[j];
        if(cnt == ind2) ind2el = arr2[j];
        cnt++;
        j++;
    }
    if((n+m)%2 == 0) return (double)(((double)(ind1el+ind2el))/2.0);
    return ind2el;
}

double expected_approach(vector<int> & arr1,vector<int> &arr2){
    int n = arr1.size();
    int m = arr2.size();
    if(m > n) return expected_approach(arr2,arr1);
    int low = 0;
    int high = n;
    int half_elements = (n + m + 1)/2;
    int l1,l2,r1,r2;
    while(low <= high){
        int mid1 = (low + high)/2;
        int mid2 = half_elements - mid1;
        if(mid1 < n) r1 = arr2[mid1];
        if(mid2 < m) r2 = arr2[mid2];
        if(mid1 - 1 >= 0) l1 = arr1[mid1 - 1];
        if(mid2 - 1 >= 0) l2 = arr1[mid2 - 1];
        if(l1 <= r2 && l2 <= r1){
            if((n+m) % 2 == 1) return (double)(max(l1,l2) + min(r1,r2))/2.0;
            return max(l1,l2);
        }
        else if(l1 > r2){
            low = mid1 + 1;
        }
        else high = mid1 -1; 
    }
    return 0;
}
int main()
{
    vector<int> arr1 = {1,3,5,7,10,11,13,14};
    vector<int> arr2 = {2,3,6};
    double median = better_approach(arr1,arr2);
    cout<<median<<endl;
    return 0;
}