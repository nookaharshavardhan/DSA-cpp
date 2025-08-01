#include <iostream>
using namespace std;
#include<vector>

struct node{
    int data;
    node* next;
    node* prev;
    node(int val){      // constructor
        data = val;
        next =nullptr;
        prev = nullptr;
    }
};


node* convert_arr_to_2DLL(vector<int> arr){
    if(arr.empty())return nullptr;
    node* head = new node(arr[0]);
    node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        node* temp = new node(arr[i]);
        mover->next = temp;
        temp->prev = mover;
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


node* delete_el_in_LL(node* head,int val){
    if(head == nullptr || head->next == nullptr) return nullptr;
    node* mover = head;
    while(mover){
        if(mover->data == val) break;
        mover= mover -> next;
    }
    if(mover == nullptr)return nullptr;

    node* fst = mover->prev;
    node* scd = mover->next;

    if(fst == nullptr && scd == nullptr){
        delete mover;
        return nullptr;
    }

    else if(fst == nullptr){
        head = scd;
        scd->prev = nullptr;
        delete mover;
        return head;


    }
    else if(scd == nullptr){
        fst->next = nullptr;
        delete mover;
        return head;
    }

    fst->next = scd;
    scd->prev = fst;


    mover->next = nullptr;
    mover->prev = nullptr;
    delete mover;
    return head;
}


node* insert_el_beforeKth_node(node* head,int k,int val){
    if(head == nullptr) return nullptr;

    node* kth_node = new node(val);
    if(k == 1){
        kth_node->next = head;
        kth_node->prev = nullptr;
        head->prev = kth_node;
        head = kth_node;

        kth_node = nullptr;
        delete kth_node;

        return head;
    }

    node* mover = head;
    
    int cnt = 1;
    while(mover->next && cnt != k){
        mover = mover->next;
        cnt++;
    }
    if(mover->next == nullptr && cnt+2 == k){
        mover->next = kth_node;
        kth_node->prev = mover;
        kth_node->next = nullptr;
        return head;
    }
    mover->prev->next = kth_node;
    kth_node->prev = mover->prev;
    kth_node->next = mover;
    mover->prev = kth_node;

    return head;
}


int main()
{
    vector<int> arr{1,2,3,4,5,7};
    node* head = convert_arr_to_2DLL(arr);
    printLL(head);
    cout<<head->next->next->prev->data<<endl;


    cout<<"after deleting"<<endl;
    head = delete_el_in_LL(head,4);
    printLL(head);


    cout<<"after inserting"<<endl;
    head = insert_el_beforeKth_node(head,3,99);
    printLL(head);

    cout<<"after inserting at end"<<endl;
    head = delete_el_in_LL(head,99);
    head = insert_el_beforeKth_node(head,7,99);
    printLL(head);

    return 0;
}