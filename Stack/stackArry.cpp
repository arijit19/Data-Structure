#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
    struct Stack* stack = createStack(10);
 
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);
 
    printf("%d popped from stack\n", pop(stack));
 
    printf("Top item is %d\n", peek(stack));
 
    return 0;
}