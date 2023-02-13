#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
struct node{
    int data;
    struct node* link;
};

struct node *first=NULL,*last=NULL,*cur;

void push(struct node *first,char ele);
void display();
void create(struct node *first,char ele);
void pop();
void expression(char
void infixtopostfix();

char ele;

void no(){
     do{
        int n=0;
        printf("1.push\n2.pop\n3.display\n");
        printf("Enter the choice : ");
        scanf("%d",&n);
        switch(n){
            case 1:
                printf("\nEnter the element to be inserted : ");
                scanf("\n%c",&ele);
                if(first==NULL)
                    create(first,ele);
                else
                    push(first,ele);
                break;
            case 2:
                if(first!=NULL)
                    pop();
                break;
            case 3:
                display();
                break;
            default:
                //exit(0);
                printf("kolaru\n");
       }
    }while(0);
}

void main(){
    int n=0;
    first=last=NULL;
    
    
    infixtopostfix();
    
}

void infixtopostfix(){
    printf("Enter the Expression ");
    while((ele=getc(stdin))!='\n'){
        if(first==NULL)
            createqueue(ele);
        else
            pushqueue(ele);
    }
    printf("The entered expression is ");
    display();
}

void expression(char ele){
    cur = (struct node*)malloc(sizeof(struct node));
    cur->data = ele;
    last->link =cur;
    cur->link = NULL;
    last=cur;
}

void create(struct node *first,char ele){
    cur = (struct node*)malloc(sizeof(struct node));
    cur->data = ele;
    cur->link = NULL;
    first=last=cur;
}
void push(struct node *first,char ele){
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

