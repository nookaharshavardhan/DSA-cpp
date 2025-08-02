#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int count_blocks_of_water(const vector<int>& height){
    int maxleft = 0;
    int maxright = 0;
    int left = 0,right = height.size() - 1;
    int ans=0;
    while(left < right){
        if(height[left] <= height[right]){
            if(height[left] <= maxleft) ans += maxleft - height[left];
            else maxleft = height[left];
            left++;
        }
        else{
            if(height[right] <= maxright) ans += maxright - height[right];
            else maxright = height[right];
            right--;
        }
    }
    return ans;
}

int main() {
    vector<int> heights = {0,1,0,2,1,0,1,3,2,1,2,1};
    int blocks_of_water = count_blocks_of_water(heights);
    cout<<blocks_of_water<<"\n";
    return 0;
}