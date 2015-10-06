#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <ctype.h>

struct StackNode
{
	int data;
	struct StackNode* nextPtr;
};

int isEmpty(struct StackNode* stack)
{
	if(!stack)
		return 1;
	return 0; 
}

void push(struct StackNode** refStack, int data)
{
	struct StackNode* stack = (struct StackNode*) malloc(sizeof(struct StackNode));
	stack->data = data;
	stack->nextPtr = *refStack;
	*refStack = stack;
	printf("%d Pushed to Stack\n", data );
	return;
}

int pop(struct StackNode** refStack)
{
	if(isEmpty(*refStack))
		return -1;
	struct StackNode *temp = *refStack;
	*refStack= (*refStack)->nextPtr;
	int popped = temp->data;
	free(temp);
	return popped;
}

int peek(struct StackNode* stack)
{
	if(isEmpty(stack))
		return -1;
	return (stack)->data;
}

int main()
{
	char buf[64];
    struct StackNode* stack = NULL; //InitStack();
    printf("Enter the following to execute your operation\n1. Push value into stack.\n2. Pop value from stack.\n3. Peek the top value\n4. Quit.\n");
    while(true)
    {
    	printf("Enter your choice\n");
    	fgets( buf, sizeof(buf), stdin);
    	int n;
        int end = 0; // use to note end of scanning and catch trailing junk
        if (sscanf( buf, " %d %n", &n, &end) != 1 || buf[end] != '\0') 
        {
            printf("must enter integer\n");
            break;
        }
    	switch(n)
    	{
    		case 1:
    		printf("Enter a value to push\n");
    		int val;
    		scanf("%d",&val);
    		push(&stack,val);
            while((getchar())!='\n');
    		break;
    		case 2:
            int p;
            p = pop(&stack);
    		if(p!=-1)
    			printf("%d Popped from stack\n", p);
    		else
    			printf("Empty Stack\n");
    		break;
    		case 3:
    		if(peek(stack)!=-1)
    			printf("Top item is %d\n", peek(stack));
    		else
    			printf("Empty Stack\n");
    		break;
            case 4:
            break;
    		default:
    		printf("Please enter a corrent choice\n");
            break;

    	}
        if(n==4)
            break;
    }
 
    return 0;
}