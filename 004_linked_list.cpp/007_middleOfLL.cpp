#include<iostream>
#include<vector>
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


node* middleOf(node* head){
    if(head->next == nullptr) return head;
    node* mover = head;
    node* mid = head;
    bool cnt = 1;
    while(mover){
        if(cnt % 2 == 0){          // if even
           mid = mid->next;
           cnt = 1;
        }  
        else{      //if odd
            cnt = 0;
        }
        mover = mover->next;
    }
    return mid;
}

node* middleNode(node* head) {
    if(head->next == nullptr || head == nullptr) return head;
    node* fast = head;
    node* slow = head;
    while(fast != nullptr && fast ->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main(){
    vector<int> arr = {1,2,3,4,5,6,7};
    node* head = convertA2LL(arr);
    printLL(head);

    node* mid = middleNode(head);
    cout<<mid->data<<" ";
}

