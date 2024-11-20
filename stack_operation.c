#include<stdio.h>
int s[100],size,top=-1;
void push(int a){
  if(top==size-1){
  printf("stack is overflow");
}
else{
top++;
s[top]=a;
}
}

void display(){
  if(top!=-1){
    int temp=top;
   while(temp>-1){
    printf("%d\n",s[temp]);
    temp--;
   }
}else{
  printf("stack is underflow");
}
}
void pop(){
    top--;
}
void main(){
  printf("enter the stack size :");
  scanf("%d",&size);
   int ch;
 do{ printf("enter the choice");
  printf("\n1.push\n2.pop\n3.Display\n4.stop\nyour choice : ");
 
  scanf("%d",&ch);
  switch(ch){
    case 1:
    printf("enter the element to be pushed : ");
    int p;
    scanf("%d",&p);
    push(p);
    break;

    case 2:
    pop();
    break;
    
    case 3:
    display();
    break;

    default:
    printf("\nenter valid choice");
    break;
  }
 }while (ch<4);
 
}