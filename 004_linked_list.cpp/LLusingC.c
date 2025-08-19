#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct node{
    int data;
    struct node* next;
};
struct node* convertArr2LL(int arr[],const int n){
    struct node* head = (struct node*)malloc(sizeof(struct node));
    struct node* cursor = head;
    for (int i = 0; i < n; ++i) {
        cursor->data = arr[i];
        if (i < n - 1) {
            cursor->next = (struct node*)malloc(sizeof(struct node));
            cursor = cursor->next;
        } else {
            cursor->next = NULL;
        }
    }
    return head;
}
void printLL(struct node* head){
    struct node* cursor = head;
    while(cursor != NULL){
        printf("%d ",cursor->data);
        cursor = cursor->next;
    }printf("\n");
}
void push_back(struct node * head,const int n){
    struct node* cursor = head;
    while(cursor->next != NULL){
        cursor = cursor->next;
    }
    cursor->next = (struct node*)malloc(sizeof(struct node));
    cursor->next->data = n;
    cursor->next->next = NULL;
}
void insert_front(struct node** head,const int val){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = *head;
    (*head) = new_node;
}
void insert(struct node** head,const int index,const int val){
    if((*head) == NULL){
        (*head) = (struct node*)malloc(sizeof(struct node));
        (*head)->data = val;
        (*head)->next = NULL;
        return ;
    }
    if(index == 0){
        insert_front(head,val);
        return ;
    }
    struct node* cursor = (*head);
    int i = 0;
    while(i < index - 1){
        cursor = cursor->next;
        i++;
    }
    if(cursor->next == NULL){
        push_back((*head),val);
        return ;
    }
    struct node* breakge = cursor->next;
    cursor->next = (struct node*)malloc(sizeof(struct node));
    cursor = cursor->next;
    cursor->data = val;
    cursor->next = breakge;
}
bool search(struct node* head , const int val){
    struct node* cursor = head;
    while(cursor != NULL){
        if(cursor->data == val)return true;
        cursor = cursor->next;
    }
    return false;
}
void delete_node(struct node* head,const int val){
    struct node* cursor = head;
    while(cursor->next->data != val){  
        cursor = cursor->next;
    }
    cursor->next = cursor->next->next;
}
int main(){
    struct node* head = NULL;
    int choice,val,ind,size;
    while(1){
        printf("\n--- List Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. turn array to LL\n");
        printf("6. push ar back\n");
        printf("7. push at front\n");
        printf("8. Exit\n");
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("enter the index and value of elements\n");
                scanf("%d %d",&ind,&val);
                insert(&head,ind,val);
                break;
            case 2:
                printf("enter the element that need to be deleted \n");
                scanf("%d",&val);
                delete_node(head,val);
                break;
            case 3:
                printf("give the value you want to search\n");
                scanf("%d",&val);
                if(search(head,val))printf("elemet exists in LL\n");
                else printf("elemet does not exists in LL\n");
                break;
            case 4:
                printLL(head);
                break;
            case 5:{
                printf("give the size of array \n");
                scanf("%d",&size);
                int arr[size];
                for(int i = 0; i < size;i++){
                    printf("enter index %d element " ,i);
                    scanf("%d",&arr[i]);
                }
                head = convertArr2LL(arr,size);
                break;
            }
            case 6:
                printf("give the element to push at back\n");
                scanf("%d",&val);
                push_back(head,val);
            case 7:
                printf("give the element to push at front\n");
                scanf("%d",&val);
                insert_front(&head,val);
            case 8:
                return 0;
            default:
                printf("give listed choices\n");
        }
    }
    return 0;
}