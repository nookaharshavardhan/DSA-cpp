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
    node* mover = head;
    while(mover != NULL){
        cout<<mover->data<<" ";
        mover = mover->next;
    }cout<<endl;
}

node* add1ToLL(node* head){
    if(head == nullptr) {
        return new node(1);
    }
    node* mover =  head;
    node* lastNon9 = nullptr; 

    while(mover){  //     2695799    269588
        if(mover->data != 9){
            lastNon9 = mover;
        }

        mover = mover->next;
    }
    if(!lastNon9){
        node* result = new node(1);
        result->next = head;

        mover = head;
        while(mover){
            mover->data = 0;
            mover = mover->next;
        }
        return result;
    }
    lastNon9->data += 1;
    mover = lastNon9->next;
    while(mover){
        mover->data = 0;
        mover = mover->next;
    }
    return head;
}

int main() {
    vector<int> arr= {9};
    node* head = convertA2LL(arr);
    head = add1ToLL(head);
    printLL(head);
    return 0;
}