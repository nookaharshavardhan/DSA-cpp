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

node* reverseList(node* head) {
   node* mover = head; 
   node* back = nullptr;
   node* front = nullptr;
   while(mover){
        front = mover->next;
        mover->next = back;
        back = mover;
        mover = front;
   }
   return back;
}


node* reverseLLByRecursive(node* head){
    if(head == nullptr || head->next== nullptr){
        return head;
    }
    node* newHead = reverseLLByRecursive(head->next);
    node* last = head->next;
    last->next = head;
    head->next = nullptr;
    return newHead;
}

int main(){
    vector<int> arr= {1,2,3,4,5,6};
    node* head = convertA2LL(arr);
    head = reverseList(head);
    printLL(head);
    head = reverseLLByRecursive(head);
    printLL(head);
}