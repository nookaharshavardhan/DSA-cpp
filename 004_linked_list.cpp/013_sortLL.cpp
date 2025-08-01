using namespace std;
#include<iostream>
#include<vector>

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

node* middleNode(node* head) {
    if(head->next == nullptr || head == nullptr) return head;
    node* fast = head->next;
    node* slow = head;
    while(fast != nullptr && fast ->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

node* mergeLL(node* left ,node* right){
    node* tempHead = new node(-1);
    node* temp = tempHead;
    while(left != nullptr && right != nullptr){
        if(left->data < right->data){
            temp->next = left;
            left = left->next;
        }
        else{
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
    }
    if(left != nullptr){
        temp->next = left;
    }
    else{
        temp->next = right;
    }
    return tempHead->next;
}

node* sortLL(node* head){
    if (head == nullptr || head->next == nullptr) {
        return head;
    }

    node* mid = middleNode(head);
    node* left = head;
    node* right = mid->next;
    mid->next = nullptr;

    left = sortLL(left);
    right = sortLL(right);

    return mergeLL(left,right);
}

int main() {
    vector<int> arr= {3,6,4,8,5,6,9,2,2,1,1,10};
    node* head = convertA2LL(arr);
    printLL(head);
    head = sortLL(head);
    printLL(head);
    return 0;
}