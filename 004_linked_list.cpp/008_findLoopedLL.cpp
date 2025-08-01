#include <iostream>
#include <vector>

using namespace std;

struct node{
    int data;
    node* next;
    node(int data_){
        data = data_;
        next = nullptr;
    }
};


node* convertA2LL(vector<int>arr){
    if(arr.empty()) return nullptr;
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
    node* mover = head;
    while(mover != NULL){
        cout<<mover->data<<" ";
        mover = mover->next;
    }cout<<endl;
}

bool findLoopedLL(node* head) {
    if(head->next == nullptr || head == nullptr) return false;
    node* mover = head;
    node* mid = head;
    while(mover != nullptr && mover ->next != nullptr){
        mid = mid->next;
        mover = mover->next->next;
        if(mover == mid) return true;
    }
    return false;
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8};
    node* head = convertA2LL(arr);
    printLL(head);
    if(findLoopedLL(head))cout<<"it is looped"<<endl;
    else cout<<"not looped"<<endl;
    return 0;
}