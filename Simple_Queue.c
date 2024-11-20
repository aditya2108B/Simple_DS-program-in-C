
#include<stdio.h>
int q[100];
int size ,front=-1,rare=-1;
void enque(int element){
    if(front==-1 ||rare==-1){
        front=0;
        rare=0;
        q[rare]=element;
    }else if (rare==size-1)
    {
    printf("Queue is full\n "); 
       }
       else{
        rare=rare+1; 
        q[rare]=element;
       }
}
void dque(){
    if(front==-1){
        printf("Queue is Empty\n");
    }else if(front==rare){
        front=-1;
        rare=-1;

    }else{
        front=front+1;
    }
}
void disply(){
        if(front ==-1 || rare==-1){
printf("Queue is empty\n");
}else{
    for (int i =front;i<=rare;i++){
        printf("%d\t",q[i]);
    }
}
}
void main(){
    int ch,ele;
    printf("Enater the size of Queue : ");
    scanf("%d",&size);
    do{
         printf("\nQueue Operations:\n");
        printf("1. Insert Element in Queue (Enqueue )\n");
        printf("2. Delete Element in Queue (Dqueue)\n");
        printf("3. Display Element in Queue\n");
        printf("4. Exit\n");
        printf("Please Enter choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
            printf("\nEnter the element : ");
            scanf("%d",&ele);
            enque(ele);
            break;

            case 2:
            dque();
            break;

            case 3:
            disply();
            break;

            default :
            printf("\nplese Enter vaild choice");
            break;
        }
    }while(ch<4);
}
