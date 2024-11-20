
#include<stdio.h>
int q[100],front=-1,rear=-1;
int size;

void display(){// Display Function
if(front==-1||rear==-1){
printf("\nQueue is Empty");
}
else{
int i=front;
while(i!=rear){
printf("%d\t",q[i]);
i =(i+1)%size;
}
printf("%d\t",q[rear]);
}
}

void enque(int element){// insert function 
if(rear==-1||front==-1){
rear =0;
front=0;
q[rear]=element;
}else if(front ==(rear+1)%size){
printf("\nQueue if Full");
}
else{
rear=(rear+1)%size;
q[rear]=element;
}
}
void dqueue(){// delete function
if(front ==-1|| rear==-1){
printf("Queue is empty");
}
else if (front==rear){
front=-1;
rear=-1;
}
else{
front =(front+1)%size;
}
}


void main(){// main function
int i,ch,ele;
printf("\nEnter the size of circular Queue : ");
scanf("%d",&size);
do{
printf("\nEnter the choice ");
printf("\n1.Enque  Operation (Insert)\n2.Dqueue operation (Delete)\n3.Display Operation\n4.Exit\n you Selected : ");
scanf("%d",&ch);
switch(ch){
case 1:
printf("\nEnter the Element which is to be insert in circular Queue : ");
scanf("%d",&ele);
enque(ele);
break;

case 2:
dqueue();
break;

case 3:
display();
break;

default :
printf("Plese Enter valid choice \n");
break;
}
}while(ch<4);
}
