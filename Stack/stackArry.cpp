#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

#define ISUNSIGNED(a) (a>=0 && ~a>=0) 

struct Stack
{
	unsigned capacity;
	int top;
	int* array;
};

struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->capacity = capacity;
	stack->top = -1;
	stack->array = (int*) malloc(sizeof(int));
	return stack;
}

bool isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}

bool isFull(struct Stack* stack)
{
	return stack->top == stack->capacity;
}

void push(struct Stack* stack, int item)
{
	if(isFull(stack))
	{
		printf("Stack Overflow!!\n" );
		return;
	}

	stack->array[++stack->top] = item;
	printf("%d Pushed to Stack..\n", item );
}

int pop(struct Stack* stack)
{
	if (isEmpty(stack))
	{
		printf("Stack Empty\n");
		return INT_MIN;
	}
	return stack->array[stack->top--];
}

int peek(struct Stack* stack)
{
	if (isEmpty(stack))
	{
		printf("Stack Empty!!\n");
		return INT_MIN;
	}
	return stack->array[stack->top];
}

int main()
{
	unsigned val;
	int ch;
	printf("Enter the size of stack\n");
	scanf("%d",&val);
	if(!ISUNSIGNED(val))
    	{
    		printf("Enter a integer value..!! :)..\n");
    		return -1;
    	}
    struct Stack* stack = createStack(val);
    printf("Enter the following to execute your operation\n1. Push value into stack.\n2. Pop value from stack.\n3. Peek the top value\n");
    while(true)
    {
    	printf("Enter your choice\n");
    	scanf("%d", &ch);
    	if(!isdigit(ch))
    	{
    		printf("Enter number b/w 1-3..!! :)..\n");
    		return -1;
    	}
    	switch(ch)
    	{
    		case 1:
    		printf("Enter a value to push\n");
    		int val;
    		scanf("%d",&val);
    		push(stack,val);
    		break;
    		case 2:
    		printf("%d Popped from stack\n", pop(stack));
    		break;
    		case 3:
    		printf("Top item is %d\n", peek(stack));
    		break;
    		default:
    		printf("Please enter a corrent choice\n");

    	}
    }
 
    return 0;
}