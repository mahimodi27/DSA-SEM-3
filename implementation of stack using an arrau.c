#include <stdio.h>

int stack[MAX];
int top=-1;// shows that the stack is initially empty//

void push(int value)
{
    if (top==MAX-1)
    {
        printf("Stack Overflow");
    }
    else
    {
        top++
        stack[top]=value;
        printf("the value pused into the stack is %d",value);

    }
}

void pop()
{
    if(top==-1)
    {
     printf("Stack Underflow");
    
    }
    else
    {
        top--;

    }
}

void peek()
{
    if top==-1
    {
        printf("Stack is empty");
    
    }
    else 
    {
        printf("the top value of the stack is %d", stack[top]);
    
    }
}

void display()
{
    if top==-1
    {
        printf("Stack is empty");
    
    }
    else 
    {
        for(i=top,i>=0,i--)
        {
            printf("%d",stack[i]);
        }
    }
}

int main()
{
    int choice,value;
    while(1)
    {

    

    printf("\n1. Push");
    printf("\n2. Pop");
    printf("\n3. Peek");
    printf("\n4. Display");
    printf("\n5.Exit");

    printf("\n Enter your choice");
    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
        printf("Enter the value to be pushed");
        scanf("%d", &value);
        push(value);
        break;
    
        case 2:
        pop();
        break;

        case 3:
        peek();
        break;

        case 4:
        display();
        break;

        case 5:
        exit(0);

        default:
        printf("/n Invalid choice");



    }
    
}
return(0);
}

