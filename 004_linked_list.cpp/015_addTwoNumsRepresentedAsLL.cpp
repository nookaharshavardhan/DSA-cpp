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

node* addTwoNumsRepresentedAsLL(node* head1,node* head2){   
    node* result = new node(-1);
    node* res = result;
    int borrow = 0;
    while(head1 || head2 || borrow){
        int sum = 0;

        if(head1){
            sum += head1->data;
            head1 = head1->next;
        }
        if(head2){
            sum += head2->data;
            head2 = head2->next;
        }

        sum += borrow;
        borrow = sum /10;
        res->next = new node(sum % 10);
        res = res->next;
    }
    return result->next;
}

int main() {
    vector<int> arr1= {2,4,3};
    vector<int> arr2= {5,6,4};
    node* head1 = convertA2LL(arr1);
    node* head2 = convertA2LL(arr2);

    node* result = addTwoNumsRepresentedAsLL(head1,head2);
    printLL(result); 
    return 0;
}