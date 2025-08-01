#include <iostream>
#include <vector>
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

node* rotateLL(node* head , int k){
    node* tempHead = head;
    node* mover = head;
    node* newHead = nullptr;
    node* lastNode = nullptr;
    int size = 1;        
    int cnt = 1;
    while(mover->next){              // find size;
        mover = mover->next;
        size++;
    }
    k = k % size;
    if(k == 0 )return head;
    lastNode = mover;
    mover = head;
    while(mover && cnt < size - k){
        mover = mover->next;
        cnt++;
    }
    newHead = mover->next;
    mover->next = nullptr;
    lastNode->next = head;
    return newHead;
}

int main() {
    vector<int> arr= {1,2};
    node* head = convertA2LL(arr);
    printLL(head);
    head = rotateLL(head,2);
    printLL(head);
    return 0;
}