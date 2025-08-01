using namespace std;
#include<bits/stdc++.h>

double place_stations(vector<int> & arr,int k ,int n){
    int sections[n-1] = {0};
    priority_queue<pair<long double,int>> que;
    for(int i = 0; i < n-1; i++){
        que.push({arr[i+1] - arr[i],i});
    }
    for(int i = 0; i < k;i++){
        int largest_dist_section = que.top().second;
        sections[que.top().second]++;
        que.push({(arr[largest_dist_section+1] - arr[largest_dist_section])/(long double)(sections[largest_dist_section]+1),largest_dist_section});
        que.pop();
    }
    return round(que.top().first*100.0)/100.0;
}


int  count_stastions_can_be_palced(vector<int> & arr, int & k, int &n,double & dist){
    int cnt = 0;
    for(int i = 0; i < n - 1; i++){
        int no_of_stations_can_be_placed = (arr[i+1]- arr[i] )/ dist;
        if(arr[i+1]- arr[i] == no_of_stations_can_be_placed*dist){
            no_of_stations_can_be_placed--;
        }
        cnt += no_of_stations_can_be_placed;
    }
    return cnt;
}

long double optimised_shit(vector<int> & arr, int k,int n){
    long double low = 0;
    long double high=0;
    for(int i = 0 ; i < n-1; i++){
        high = max(( long double)arr[i + 1] - arr[i], high);
    }
    while(high - low > 1e-6){
        double mid = (low + high )/2.0;
        int cnt = count_stastions_can_be_palced(arr,k,n,mid);
        if(cnt > k){
            low = mid;
        }
        else high = mid;
    }
    return high;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = arr.size();
    int no_of_stations_to_place = 9;
    long double ans = place_stations(arr,no_of_stations_to_place,n);
    long double anss= optimised_shit(arr, no_of_stations_to_place,n);
    cout<<ans<<" "<<anss<<endl;
    return 0;
}