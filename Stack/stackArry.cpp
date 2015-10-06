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
	char siz[64];
	
	char inp[64];
	
	int nSiz;
    int end = 0; // use to note end of scanning and catch trailing junk
    int flag =0 ;

    while(flag!=1)
    {
    	printf("Enter the size of stack\n");
    	fgets( siz, sizeof(siz), stdin);
    	if (sscanf( siz, " %d %n", &nSiz, &end) != 1 || siz[end] != '\0') 
    	{
        	printf("Must enter integer\n");
    	}
    	else
    		flag = 1;
    }
    struct Stack* stack = createStack(nSiz);
    printf("Enter the following to execute your operation\n1. Push value into stack.\n2. Pop value from stack.\n3. Peek the top value\n4. Quit.\n");
    while(true)
    {
    	printf("Enter your choice\n");
    	fgets( inp, sizeof(inp), stdin);
		int nInp;
    	int endInp = 0; // use to note end of scanning and catch trailing junk
    	if (sscanf( inp, " %d %n", &nInp, &endInp) != 1 || inp[endInp] != '\0') 
    	{
    	    printf("Enter number b/w 1-4..!! :)..\n");
    	    break;
    	}
    	switch(nInp)
    	{
    		case 1:
    		printf("Enter a value to push\n");
    		int val;
    		scanf("%d",&val);
    		push(stack,val);
    		while((getchar())!='\n');
    		break;
    		case 2:
    		printf("%d Popped from stack\n", pop(stack));
    		break;
    		case 3:
    		printf("Top item is %d\n", peek(stack));
    		break;
    		case 4:
    		break;
    		default:
    		printf("Please enter a corrent choice\n");

    	}
    	if(nInp==4)
            break;
    }
 
    return 0;
}