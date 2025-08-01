#include <iostream>
#include <vector>
#include <unordered_set>
#include <utility>
using namespace std;

struct node{
    int data;
    node* next;

    node(int data1){
        data = data1;
        next = nullptr;
    }
};

node* convertA2LL(vector<int>arr){
    if(arr.empty())return nullptr;
    node* head = new node(arr[0]);
    node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        node* temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}


void printLL(node* head){
    if(head == nullptr) cout<<"the LL is empty";
    node* mover = head;
    while(mover != NULL){
        cout<<mover->data<<" ";
        mover = mover->next;
    }cout<<endl;
}

vector<pair<int,int>> findPairsOfSum(node* head,int key){
    vector<pair<int,int>> arr;
    node* mover  = head;
    unordered_set<int> s;
    while(mover){
        int req = key- mover->data;
        if(s.find(req) != s.end()){
            pair<int,int> temp(req,mover->data);
            arr.push_back(temp);
        } 
        s.insert(mover->data);
        mover = mover->next;
    }

    return arr;
}

int main() {
    vector<int> arr= {0,1,2,3,4,5,6,7,8,9,10};
    node* head = convertA2LL(arr);
    printLL(head);
    vector<pair<int,int>> ans = findPairsOfSum(head,10);
    for(auto i : ans){
        cout<<i.first<<" "<<i.second<<endl;
    }
    
    return 0;
}