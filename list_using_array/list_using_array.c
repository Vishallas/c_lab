#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include<curses.h>
// function definition

void create(); // creates a list
void display(); // displays a list
int insert(); // inserts to a list
int _del(); // deletes a element in a list
void find(); // finds a element in a list

//global variables

int list[25]; // empty array of size 25
int n; // count of elements in array


void main(){
    int ch;
    system("clear");
    printf("\n\t\t\t\tLIST USING ARRAY");
    printf("\n\t\t\t\t**** ***** *****");
    do{
        printf("\n\n MAIN MENU");
        printf("\n1. CREATE\n2. INSERT\n3. DELETE\n4. FIND\n5. DELETE\n6.EXIT");
        printf("\nENTER YOUR CHOICE");
        scanf("%d",&ch);
        switch(ch){
      
            //to create a list 
            case 1:
                printf("\nEnter the number of elements : ");
                scanf("%d",&n);
                create();
                display();
                break;
             
            // inserts to a list
            case 2:
                n = insert();
                display();
                break;
            
            // deletes a element in a list
            case 3:
                n = _del();
                display();
                break;
            
            // finds a element in a list
            case 4:
                find();
                break;
            
            // displays a list
            case 5:
                display();
                break;
            
            // exits the code
            case 6:
                exit(0);
                break;
        }
    }while(ch<=6);
}

void create(){
    int i = 0;
    printf("\nList to be created ");
    for(;i<n;i++){
        printf("element no. %d : ",i+1);
        scanf("%d",&list[i]);
    }    
}

int insert(){
    int i, ele, pos;
    printf("\nEnter the number and position ");
    scanf("%d\n",&ele);
    scanf("%d",&pos);
    if(n == 25){
        printf("/nlist is full");
        return n;
    }else if(n == 0){
        printf("\nList has to be created first");
        return 0;
    }else if(pos == n+1){
        list[pos] = ele;
        n+=1;
        return n;
    }else{
        for(i=n;i>=pos;i--){
            list[i+1] = list[i];
        }
        list[pos] = ele;
        n+=1;
        return n; 
    }   
}

int _del(){
    int i ,pos;
    printf("Enter the position to be deleted : ");
    scanf("%d",&pos);
    for(i = pos;i<=n;i++){
        list[i] = list[i+1];
        n--;
    }
    return n;
}
void find(){
    int i, find;
    printf("\nEnter the data to be searched : ");
    scanf("%d",&find);
    if(n==0){
        printf("\nThe element %d is positioned at %d.\n",find,i);
    }else{
        printf("\nElement is not found");
    }
}
void display(){
    if(n == 0){
        printf("The list is empty, create a list.");
    }else{
        for(int i = 0;i<n;i++){
            printf("%d",list[i]);
        }
    }
}
    


  

