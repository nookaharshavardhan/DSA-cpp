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
}

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


node* segregateNodes(node* head){
    node* mover = head;
    node* fast = head;
    node* slow = head;
    int cnt= 0;
    
    return head;
}
int main() {
    vector<int> arr= {1,2,3,4,5,6,7,8};
    node* head = convertA2LL(arr);
    printLL(head);
    head = segregateNodes(head);
    cout<<"After segregateNodes : ";
    printLL(head);
    return 0;
}