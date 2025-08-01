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

node* findStartPoint(node* head){
    node* fast = head;
    node* slow = head;
    while(fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return fast;
        }
    }
    return nullptr;
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8};
    node* head = convertA2LL(arr);
    printLL(head);
    return 0;
}