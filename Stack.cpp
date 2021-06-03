#include<stdlib.h>
#include<iostream>

using namespace std;

#define MAX 10
int size = 0;

//creating a stack
struct stack {
    int items[MAX];
    int top;
};

typedef struct stack st;

void createEmptyStack(st *s)
{
        s->top = -1;
}

//check if the stack is full
int isfull(st *s)
{
    if(s->top == MAX-1)
        return 1;
    else
        return 0;
}

//check if the stack is empty
int isempty(st *s)
{
    if(s->top == -1)
        return 1;
    else
        return 0;
}

//Add elements into stack
void push(st *s, int newitem)
{
    if(isfull(s))
    {
        printf("Stack is full");
    }
    else
    {
        s->top++;
        s->items[s->top] = newitem;
    }
    size++;
}

//Remove element from stack
void pop(st *s)
{
    if(isempty(s))
    {
        printf("\nStack is empty\n");
    }
    else
    {
        printf("Item is popped = %d", s->items[s->top]);
        s->top--;
    }
    size--;
    cout<<endl;
}

//print elements of stack
void printStack(st *s)
{
    cout<<"---------------------------------------------"<<endl;
    printf("Stack : ");
    for(int i=0; i<size; i++)
    {
        cout<< s -> items[i] << " ";
    }
    cout<<endl;
}

int main()
{
    int choice,num;
    char ch;
    st *s = (st*)malloc(sizeof(st));

    createEmptyStack(s);

    repeat:
        cout<<"----------------------------------------------"<<endl;
        cout<<"1 = Push value in stack"<<endl;
        cout<<"2 = pop value from stack"<<endl;
        cout<<"3 = Print stack"<<endl;
        cout<<"4 = Continue or exit from the stack"<<endl;
        cout<<"Enter your Choice = ";
        cin>>choice;


        switch(choice)
        {
        case 1:
            cout<<"---------------------------------------------"<<endl;
            cout<<"Enter number to push in stack = ";
            cin>>num;
            push(s,num);
            break;
        case 2:
            pop(s);
            break;
        case 3:
            printStack(s);
            break;
        case 4:
            cout<<"-----------------------------------------------"<<endl;
            cout<<"Do you want to exit from the Stack (y/n) = ";
            cin>>ch;
            if(ch=='y' ||  ch=='Y')
                exit(0);
            else
                break;
        }
        goto repeat;

}
