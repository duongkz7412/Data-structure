#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>


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

int emptyStack(Stack S)
{
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

void push(ElementType x, Stack* pS){
	if (fullStack(*pS))
	{
		printf("Loi! Ngan xep day");
		return;
	}
	pS->Top_idx--;
	pS->Elements[pS->Top_idx] = x;
}

void xoa(Stack* pS) {
	if (pS->Top_idx == MaxLength)
		return;
	pS->Top_idx++;
}

void khoitao(Stack* pS)
{
	pS->Top_idx = MaxLength;

}

void them(int x, Stack* pS) {
	if (pS->Top_idx == 0)
		return;
	pS->Top_idx--;
	pS->Elements[pS->Top_idx] = x;

}

int ktRong(Stack S) {
	return S.Top_idx == MaxLength;

}

int ktDay(Stack S) {
	return S.Top_idx == 0;
}

void hienthi(Stack* pS)
{
	for (int i = pS->Top_idx; i < MaxLength; i++)
		printf("%d ", pS->Elements[i]);
}

int giatriDinh(Stack S)
{
	return S.Elements[S.Top_idx];
}

void doiNhiPhan(int n, Stack* pS)
{
	khoitao(pS);
	while (n != 0)
	{
		them(n % 2, pS);
		n /= 2;
	}
}

void readStack( Stack* pS)
{
	makenullStack(pS);
	int n;
	scanf_s("%d", &n);
	int x;
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &x);
		push(x, pS);
	}
}

void printStack(Stack* pS)
{
	while (!emptyStack(*pS))
	{
		printf("%d ", top(*pS));
		pop(pS);
	}
	printf("\n");
}

float tinhGiatri(char* chuoi)
{
	Stack S;
	makenullStack(&S);
	int length = strlen(chuoi);

	for (int i = 0; i < length; i++)
	{
		if (chuoi[i] >= 48 && chuoi[i] <= 57)
			push((int)(chuoi[i] - 48), &S);
		else if (chuoi[i] == '+')
		{
			float a = top(S);
			pop(&S);
			float b = top(S);
			pop(&S);
			push(a + b, &S);
		}
		else if (chuoi[i] == '-')
		{
			float a = top(S);
			pop(&S);
			float b = top(S);
			pop(&S);
			push(b - a, &S);
		}
		else if (chuoi[i] == '*')
		{
			float a = top(S);
			pop(&S);
			float b = top(S);
			pop(&S);
			push(a * b, &S);
		}
		else if (chuoi[i] == '/')
		{
			float a = top(S);
			pop(&S);
			float b = top(S);
			pop(&S);
			push(b / a, &S);
		}
	}
	return top(S);
}

int mucUutien(char op) {
	if (op == '+' || op == '-')
		return 1;
	else if (op == '*' || op == '/')
		return 2;
}
int isNumber(char c){
	return (c >= '0' && c <= '9');
}
int isAb(char c){
	return (c >= 'a' && c <= 'z');
}
void pushChar(char c, char* s){
	s[strlen(s) + 1] = '\0';
	s[strlen(s)] = c;
}
int isOP(char c){
	return (c == '+' || c == '-' || c == '*' || c == '/');
}
void chuyenHauto(char* trungto, char* hauto){
	hauto[0] = '\0';
	Stack S;
	makenullStack(&S);
	for (int i = 0; i < strlen(trungto); i++){
		if (trungto[i] == ' '){
		}
		else if (isNumber(trungto[i]) || isAb(trungto[i]))
			pushChar(trungto[i], hauto);
		else if (trungto[i] == '(')
			push('(', &S);
		else if (trungto[i] == ')'){
			while (top(S) != '('){
				pushChar(top(S), hauto);
				pop(&S);
			}
			pop(&S);
		}
		else if (isOP(trungto[i])){
			while (!emptyStack(S) && top(S) != '(' && mucUutien(trungto[i]) <= mucUutien(top(S))){
				pushChar(top(S), hauto);
				pop(&S);
			}
			push(trungto[i], &S);
		}
	}
	while (!emptyStack(S)){
		pushChar(top(S), hauto);
		pop(&S);
	}
}

void inThaplucphan(int n){
	char Hex[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	Stack S;
	makenullStack(&S);
	while (n != 0){
		push(Hex[n % 16], &S);
		n /= 16;
	}
	while (!emptyStack(S)){
		printf("%c", top(S));
		pop(&S);
	}
}
