#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> find_asteroids_after_collision(const vector<int>& asteroids){
    vector<int> ans;
    for(int i = 0 ; i < asteroids.size() ; ++i){
        if(asteroids[i] >0 )ans.push_back(asteroids[i]);
        else{
            while(!ans.empty() && ans.back() > 0 &&  ans.back() < abs(asteroids[i])) ans.pop_back();
            if(!ans.empty() && ans.back() ==  abs(asteroids[i])) ans.pop_back();
            else if(ans.empty() || ans.back() < 0) ans.push_back(asteroids[i]);
        }
    }
    return ans;
}

int main() {
    vector<int> asteroids ={10,15,-5,-5,-5};
    vector<int> asteroids_after_collision = find_asteroids_after_collision(asteroids);
    for(auto it : asteroids_after_collision){
        cout<<it<<" ";
    }cout<<"\n";
    return 0;
}