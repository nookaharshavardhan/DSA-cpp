#include <iostream>
using namespace std;

struct node{
    int data;
    node* next;
    node* random;
    node(int data_){
        data = data_;
        next = nullptr;
        random = nullptr;
    }
}; 

void printLL(node* head){
    while (head != nullptr) {
        cout << "Data: " << head->data;
        if (head->random != nullptr) {
            cout << ", Random: " << head->random->data;
        } else {
            cout << ", Random: nullptr";
        }
        cout << endl;
         // Move to the next node
        head = head->next;  
    }
}

void insertNodes(node* head){
    node* mover = head ;
    node* temp = nullptr;
    while(mover){
        temp = mover->next;
        mover->next = new node(mover->data);
        mover->next->next = temp;
        mover = temp;
    }
}

void connectRandNodes(node* head){
    node* mover = head;
    while(mover){
        node* copyLL = mover->next;
        if(mover->random) copyLL->random = mover->random->next;
        else copyLL->random = nullptr;
        mover = copyLL->next;
    }
}

node* seperateNodes(node* head){
    node* dummyNode = new node(-1);
    node* mover_1 = dummyNode;
    node* mover_2 = head;
    while(mover_2){
        mover_1->next = mover_2->next;
        mover_1 = mover_1->next;
        mover_2->next = mover_1->next;
        mover_2 = mover_2->next;
    }
    return dummyNode->next;
}

node* cloneLL(node* head){
    node* temp = nullptr;
    node* mover = head;
    insertNodes(head);
    connectRandNodes(head);
    return seperateNodes(head); 
}

int main() {
    node* head = new node(7);
    head->next = new node(14);
    head->next->next = new node(21);
    head->next->next->next = new node(28);

    head->random = head->next->next;
    head->next->random = head;
    head->next->next->random = head->next->next->next;
    head->next->next->next->random = head->next;

    cout << "Original Linked List with Random Pointers:" << endl;
    printLL(head);

    node* clonedList = cloneLL(head);

    cout << "\nCloned Linked List with Random Pointers:" << endl;
    printLL(clonedList);

    return 0;
}