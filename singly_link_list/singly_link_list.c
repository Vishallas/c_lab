#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};

void create();
void insert();
void delete();
void display();

struct node *first = NULL,*last = NULL, *next,*prev,*cur;

void create(){
    cur = (struct node*)malloc(sizeof(struct node));
    printf("Enter the data for new list : ");
    scanf("%d",&cur->data);
    cur->link=NULL;
    first=last=cur;
}

void insert(){
    int pos,c = 1;
    if(first != NULL){
        cur = (struct node*)malloc(sizeof(struct node));
        printf("Enter the position to insert : ");
        scanf("%d",&pos);
        printf("Enter the data : ");
        scanf("%d",&cur->data);
        if(pos == 1 && first!=NULL){
            cur->link=first;
            first = cur;
        }
        else{
            next = first;
            while(c<pos){
                prev = next;
                next = prev->link;
                c++;
            }
            if(prev == NULL){
                printf("\n\nInvalid position \n");
            }
            else{
                cur->link=prev->link;
                prev->link=cur;
            }
        }
        display();
    }
}

void display(){ 
    if(first!=NULL){
        cur = first;
        while(cur!=NULL){
            printf("%d ",cur->data);
            cur=cur->link;
        }
        printf("\n");
    }
}

void delete(){
    int pos,c = 1;
    if(first != NULL){
        
        printf("Enter the position to delete : ");
        scanf("%d",&pos);
        
        if(pos == 1 && first->link==NULL){
            printf("The deleted element is %d.\n",first->data);
            free(first);
        }
        else{
                prev = first;
                if(pos == 1){
                pos = 2;
            }
            while(c<pos-2){
                prev = prev->link;
                c++;
            }
            next = prev->link;
            prev->link = next->link;
            printf("The deleted element is %d.\n",next->data);
            free(next);
        }
        display();
    }
}

void main(){
    int ch;
    system("clear");
    printf("\n\t\t\t\tSINGLY LINKED LIST");
    printf("\n\t\t\t\t**** ***** *****");
    do{
        printf("\n\n MAIN MENU");
        printf("\n1. CREATE\n2. INSERT\n3. DELETE\n4. DISPLAY\n5.EXIT");
        printf("\nENTER YOUR CHOICE");
        scanf("%d",&ch);
        switch(ch){
      
            //to create a list 
            case 1:
                create();
                display();
                break;
             
            // inserts to a list
            case 2:
                insert();
                break;
            
            // deletes a element in a list
            case 3:
                delete();
                break;
            
            // displays a list
            case 4:
                display();
                break;
            
            //exits
            case 5:
                exit(0);
        }
    }while(ch<=5);
}
