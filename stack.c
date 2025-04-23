//Make the Stack
//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning (disable : 4996)
typedef struct stack
{
	int* arr;	// array
	int max;	// capacity
	int top;	// pointer
}stack;

void createStack(stack* p, int x);
void pushStack(stack* p, int x);
int popStack(stack* p);
int sizeStack(stack* p);
int isEmpty(stack* p);
int peakStack(stack* p);

int main()
{
	int N, swc, value = 0;
	scanf("%d", &N);
	char* order = calloc(N, sizeof(char));
	char* dummy = calloc(N, sizeof(char));
	stack stk;
	createStack(&stk, N);
	

	for (int i = 0; i < N; i++)
	{
		scanf("%s", order);
		int length = strlen(order);
		for (int j = 0; j < length; j++)
		{
			if (order[i] == " ")
				break;
			
		}
		char* ptr = strtok(order, " ", &value);
		printf("%s", ptr);

		
	}

	return 0;
}

void createStack(stack* p, int x)
{
	p->arr = calloc(x, sizeof(int));
	p->max = x;
	p->top = -1;
}

void pushStack(stack* p, int x)
{
	if ((p->top) >= (p->max - 1))
		return;
	p->arr[++(p->top)] = x;
}

int popStack(stack* p)
{
	if (p->top <= -1)
		return -1;
	return p->arr[(p->top)--];
}

int sizeStack(stack* p)
{
	return (p->top) + 1;
}

int isEmpty(stack* p)
{
	if (p->top <= -1)
		return 1;
	return 0;
}

int peakStack(stack* p)
{
	if (p->top <= -1)
		return -1;
	return p->arr[p->top];
}
