#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
    int data;
    struct node* link;
};

struct node *first=NULL,*last=NULL,*cur;

void push(char ele);
void display();
void create(char ele);
void pop();
void expression(char ele);
void infixtopostfix();
char check();

char ele;

void main(){
    int n=0;
    first=last=NULL;
    printf("Enter the Expression ");
    while((ele=getc(stdin))!='\n'){
        if(first==NULL)
            create(ele);
        else
            expression(ele);
    }
    printf("The entered expression is ");
    display();
    
    
}

void infixtopostfix(){
 cur = first;
 while(cur!=NULL){
    char c = check();
    switch(c){
        case '+':
        case '-':
            if(c != '('
        case '*':
        case '/':
        case '^':
        case '(':
        case ')':
    }
 }
}

void expression(char ele){
    cur = (struct node*)malloc(sizeof(struct node));
    cur->data = ele;
    last->link =cur;
    cur->link = NULL;
    last=cur;
}

void create(char ele){
    cur = (struct node*)malloc(sizeof(struct node));
    cur->data = ele;
    cur->link = NULL;
    first=last=cur;
}
void push(char ele){
    cur = (struct node*)malloc(sizeof(struct node));
    cur->data=ele;
    cur->link = first;
    first=cur;
    
}

void pop(){
    cur = first;
    printf("The element deleted is %c.\n",cur->data); 
    first=first->link;
    cur->link = NULL;
    free(cur);
}

void display(){
    cur = first;
    while(cur!=NULL){
        printf("%c ",cur->data);
        cur = cur->link;
    }
    printf("\n");
}
char check(){
    cur = first;
    return cur->data;
}

