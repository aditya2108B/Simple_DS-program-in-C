
#include<stdio.h>
#include<string.h>
int top=-1,k;
char a[100];
void push(char k){
    top=top+1;
    a[top]=k;
}
void pop(){
    top=top-1;
}
void main(){
    char exp[100],c;// c is chareter 
    int i;
    printf("Enter the string\n");
    scanf("%s",exp);
    for(i=0;i<strlen(exp);i++){
        c=exp[i];
        if(c=='('||c=='{'||c=='['){
              push(c);
        }else {
            if(c==')' && a[top]=='('){
               pop();
            }
            else if(c=='}' && a[top]=='{'){
                pop();
            }
            else if (c==']'&& a[top]=='['){
                pop();
            }
            else if ( c==']'||c=='}' || c==')'){
                push(c);
                 break ;
            }
          else{
         continue;
          }
        }
    } 
    if(top!=-1){
        printf("string is imbalnce");
    }else{
        printf("string is Balnced");
    }
}
