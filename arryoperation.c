#include<stdio.h>
int size;
int a[100];
// function for case 1
int insert_element(int position,int element){
    if (position<=size)
    {
        size++;
    for(int i=size-1;i>=position-1;i--){
        a[i+1]=a[i];
    }
    a[position-1]=element;
    display();

    }
    else
    {
        printf("plese enter valid position");
    }
    

}
// function for second case
int insert_last_element(int element){
    size++;
a[size-1]=element;
}
// display function for case 5 and as a part of nested function 
int display(){
    printf("\nArray after operation:\n ");
    for(int i=0;i<size;i++){
        printf("\t%d",a[i]);
    }
}
// function for case 3
int delete_element(int position){
   if (position<=size)
   {
     
    for(int i=position-1;i<size-1;i++){
        a[i]=a[i+1];
    }
   size--;
     display();
   }
   else
   {
   printf("\ninvalid position");
   }
   
}
// function for case 4
int delete_last_element(){
    size--;
    display();
}

// main function  

void main(){
    int i;
    printf("Enter array size :");
    scanf("%d",&size);
    printf("\nplese enter element in arry:\n");
    for(i=0;i<size;i++){
        scanf("%d",&a[i]);

    }
    for(int i=0;i<size;i++){
        printf("\t%d",a[i]);
    }
    int ch ;
    int p,ele ;
    printf("\nplese select a choice for array opertionn from 1-4:");
    printf("\n1.insert\n2.insert at last\n3.delete element in arry\n4.delete at last element \n5.display array:\nyou selected:\t");
    scanf("%d",&ch);
        switch (ch)    //Switch case
    {
        case 1:
        printf("selected insert :\nelement plese input: \nposition and Element\t");
        scanf("%d%d",&p,&ele);
        insert_element(p,ele);
        break;

        case 2:
        printf("selected insert element at last plese input:\nElement ");
        scanf("%d",&ele);
        insert_last_element(ele);
            display();
        break;

        case 3:
        printf("selected Delete element please input :\nposition");
        scanf("%d",&p);
        delete_element(p);
        break;

        case 4:
        printf("selected Delete last element");
        delete_last_element();
        break;

        case 5:
        display();

       
    default:
    printf("plese select proper choice");
        break;
    }
    
}

