
#include<stdio.h>
int a[100][100];
int i, j,row,col,count=0,count1=0;
void display_before_test(){
    printf("Matrix is :\n");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
           printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
void  testmatrix(){
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if (a[i][j]==0)
            {
                count++;
            }
            else
            {
             count1++;
            }
        }
    }
}
void  display_final_after_test(){
    printf("\nNon zero element in matrix :\n");
    printf("\nRow\tColumn\tElement");
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            if(a[i][j]!=0){
           printf("\n%d\t%d\t%d\t",i+1,j+1,a[i][j]);
        }
        
    }
    }
}
void conclusion(){
    if(count>count1){
        printf("\nGiven matrix is Sparse matrix\n");
        display_before_test();
          display_final_after_test();
    }else{
        printf("\nGiven matrix is not Sparse matrix");
}
}
void main()
{
    
    printf("Enter No of Row :\t");
    scanf("%d",&row);
    printf("Enter No of Coloum :\t");
    scanf("%d",&col);
    printf("Enter %d element :\t",row*col);
    for(i=0;i<row;i++){
        for(j=0;j<col;j++){
            scanf("%d",&a[i][j]);
        }
    }
    display_before_test();
    testmatrix();
    conclusion();
     
}
