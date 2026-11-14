#include <stdio.h>
#include <ctype.h>
#define MAX 100

int stack[MAX];
int top=-1;

void push(int x)
{
    stack[++top] = x;

}

int pop()
{
    return stack[top--];

}

int main()
{
    char postfix[MAX], x;
    int i, a,b, result;



printf("Enter the postfix expression");
fgets(postfix, MAX, stdin);

for(i=0; postfix[i]!='\0'; i++)
{
    x= postfix[i];

    if (isdigit(x))
    {
        push (x -'0');
    }

    else if ( x=='-' || x=='+' || x=='*' || x=='/')
    {
        b= pop();
        a= pop();

        switch(x)
        {
            case '+':
            result = a+b;
            break;
            

            case '-':
            result = a-b;
            break;

             case '*':
            result = a*b;
            break;

             case '/':
            result = a/b;
            break;

          
        }
        push(result);

    } 
}

    printf(" the result is %d", pop());
    return 0;

}