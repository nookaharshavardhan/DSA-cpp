#include<stdio.h>


void insert(int arr[],int val,int index){
    printf("%d",index);
    if(index < 0 || index >= 10){
        printf("invalid positoin\n");
        return ;
    }
    arr[index] = val;
}

 void delete_(int arr[],int val,int ind){
    if(ind == 10- 1)arr[ind] = 0;
    if(ind < 0 || ind >= 10){
        printf("invalid positoin\n");
        return ;
    }
    for(int i = ind; i < 10;++i){
        arr[ind] = arr[ind + 1];
    }
}

void search(int arr[],int val){
    for(int i =0 ;i < 10; ++i){
        if(arr[i] == val){
            printf("element found at index %d \n",i);
            return ;
        }
    }
    printf("element not found\n");
}

void print(int arr[]){
    for(int i = 0; i < 10;++i){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main(){
    int val, ind,choice;
    int arr[10] = {0};
    while(1){
        printf("\n--select one of the following--\n");
        printf("1.insert\n");
        printf("2.delete\n");
        printf("3.search\n");
        printf("4.display\n");
        printf("5.exit\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("give the value of element you want to indert\n");
            scanf("%d",&val);
            printf("give the index\n");
            scanf("%d",&ind);
            insert(arr,val,ind);
            break;
        case 2:
            printf("give the element to delete \n");
            scanf("%d",&val);
            printf("give the index\n");
            scanf("%d",&ind);
            delete_(arr,val,ind);
            break;
        case 3:
            printf("element you want to search\n");
            scanf("%d",&val);
            search(arr,val);
            break;
        case 4:
            print(arr);
            break;
        case 5:
            return 0;
        default:
            break;
        }
    }
}