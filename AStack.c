#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define MaxLength 100
typedef int ElementType;
typedef struct {
	ElementType Elements[MaxLength];
	int Top_idx;
}Stack;

void makenullStack(Stack* pS)
{
	pS->Top_idx = MaxLength;
}

int emptyStack(Stack S){
	return S.Top_idx == MaxLength;
}

int fullStack(Stack S)
{
	return S.Top_idx == 0;
}

ElementType top(Stack S)
{
	if (!emptyStack(S))
		return S.Elements[S.Top_idx];
	printf("Loi! Ngan xep rong");
	return NULL;
}

void pop(Stack* pS)
{
	if (!emptyStack(*pS))
		pS->Top_idx--;
	printf("Loi! Ngan xep rong");
}

void push(ElementType x, Stack* pS) {
	if (fullStack(*pS))
	{
		printf("Loi! Ngan xep day");
		return;
	}
	pS->Top_idx--;
	pS->Elements[pS->Top_idx] = x;
}