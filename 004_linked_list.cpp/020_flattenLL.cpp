#include <iostream>
#include <vector>
using namespace std;


struct node{
    int data;
    node* next;
    node* child;
    node(int data1){
        data = data1;
        next = nullptr;
        child = nullptr;
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

node* convertA2LLchild(vector<int>arr){
    if(arr.empty())return nullptr;
    node* head = new node(arr[0]);
    node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        node* temp = new node(arr[i]);
        mover->child = temp;
        mover = temp;
    }
    return head;
}



void printLL(node* head){
    if(head == nullptr) {
        cout << "the LL is empty";
        return;
    }

    node* mover = head;
    while(mover != nullptr){
        node* mover2 = mover;
        while(mover2){
            cout << mover2->data << " ";
            mover2 = mover2->child;
        }
        cout << endl;
        mover = mover->next;
    }
    cout << endl;
}

void printLLnormal(node* head){
    if(head == nullptr) cout<<"the LL is empty";
    node* mover = head;
    while(mover != NULL){
        cout<<mover->data<<" ";
        mover = mover->next;
    }cout<<endl;
}


// void printLL(node* head){
//     if(head == nullptr) cout<<"the LL is empty";
//     node* mover = head;
//     while(mover != NULL){
//         cout<<mover->data<<" ";
//         mover = mover->next;
//     }cout<<endl;
// }



node* flattenLL(node* head){
    node* mover = head;
    node* mover2 = head;
    node* temp = nullptr;
    node* tempNext = nullptr;
    while(mover){
        mover2 = mover;
        tempNext = mover->next;
        while(mover2->child){
            temp = mover2;
            mover2 =mover2->child;
            temp->next = mover2;
            temp->child = nullptr;
        }
        mover2->next = tempNext;
        mover = mover->next;
    }
    return head;
}


node* mergeLL(node* a,node* b){
    node* dummynode =  new node(-1);
    node* res = dummynode;

    while(a && b){
        if(a->data < b->data){
            res->child = a;
            res = res->child;
            a = a->child;
        }
        else{
            res->child = b;
            res = res->child;
            b = b->child;
        }
        
        res->next = nullptr;
    }

    if(a)res->child = a;
    if(b)res->child = b;

    if(dummynode->child){
        dummynode->child->next = NULL;
    }

    return dummynode->child;
}



node* flattenLLSort(node* head){
    if(head == nullptr || head->next == nullptr){
        return head;
    }

    node* mhead = flattenLLSort(head->next); 

    return mergeLL(head,mhead);
}

int main() {
    vector<int> arr= {11,8,16,5,12,13,7,4,6};
    node* head = convertA2LL(arr);
    printLL(head);

    node* head2 = convertA2LLchild({1,15,14,6,3,2}); //flattening the LL
    head->child = head2;
    head = flattenLL(head);
    cout<<"after flat"<<endl;
    printLL(head);
    
    node* head3 = convertA2LL({11,8,16});     // flattening the ll and also sorting it
    node* head4 = convertA2LLchild({1,2,3,6,14,15});
    head3->child = head4;
    head3->next->child = new  node(99);
    head3->next->next->child = new  node(21);
    printLL(head3);
    head3 = flattenLLSort(head3);
    cout<<"afters flat and sort"<<endl;
    printLL(head3); 
    return 0;
}