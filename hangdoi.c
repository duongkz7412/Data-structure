#include <stdlib.h>
#include<stdio.h>

//cai dac hang doi bang danh sach lien ket
typedef int ElementType;

struct Node
{
    ElementType Element;
    struct Node* Next;
};

typedef struct Node* Position;

typedef struct
{
    Position Front, Rear;
} Queue;

void makenullQueue(Queue* pS)
{
    pS->Front = (Position)malloc(sizeof(struct Node));
    pS->Front->Next = NULL;
    pS->Rear = pS->Front;
}

int emptyQueue(Queue Q)
{
    return Q.Front == Q.Rear;
}

ElementType front(Queue Q)
{
    return Q.Front->Next->Element;
}

void deQueue(Queue* pQ)
{
    pQ->Front = pQ->Front->Next;
}

void enQueue(ElementType x, Queue* pQ)
{
    pQ->Rear->Next = (Position)malloc(sizeof(struct Node));
    pQ->Rear = pQ->Rear->Next;
    pQ->Rear->Element = x;
    pQ->Rear->Next = NULL;
}

int count(Queue Q)
{
    int c = 0;
    Position P = Q.Front;
    while (P != Q.Rear)
    {
        c++;
        P = P->Next;
    }
    return c;
} 

//don vi thoi gian can thiet de hoan thanh n cong viec duoc giao
int main() {
    // danh sach viec can lam;
    Queue tasks;
    // cac buoc thuc hien;
    Queue steps;
    // tong cac buoc phai thuc hien;
    int total_steps = 0;

    makenullQueue(&tasks);
    makenullQueue(&steps);

    int n;
    scanf("%d", &n);
    ElementType x;

    // nhap danh sach viec can lam;
    for (int i = 0; i < n; i++){
        scanf("%d", &x);
        enQueue(x, &tasks);
    }

    // nhap cac buoc thuc hien;
    for (int i = 0; i < n; i++){
        scanf("%d", &x);
        enQueue(x, &steps);
    }

    // lap trong khi hai danh sach khong rong
    while (!(emptyQueue(tasks) && emptyQueue(steps))){
        total_steps++;
        // truong hop thuc hien
        if (front(tasks) == front(steps)){
            deQueue(&tasks);
            deQueue(&steps);
        }
        // truong hop khong thuc hien
        else{
            enQueue(front(tasks), &tasks);
            deQueue(&tasks);
        }
    }
    printf("%d\n", total_steps);
    return 0;
}

//co Q hang doi va thuc hien N thao tac E hoac D
int main()
{
    int n;
    scanf("%d", &n);

    char action;
    int param;

    Queue list;
    makenullQueue(&list);

    // danh sach tham so;
    Queue params;
    makenullQueue(&params);

    // danh sach so luong;
    Queue lengths;
    makenullQueue(&lengths);

    for (int i = 0; i < n; i++)
    {
        getchar();
        scanf("%c", &action);
        switch (action)
        {
        case 'D':
            if (emptyQueue(list))
            {
                enQueue(-1, &params);
                enQueue(0, &lengths);
            }
            else
            {
                enQueue(front(list), &params);
                deQueue(&list);
                enQueue(count(list), &lengths);
            }
            break;
        case 'E':
            scanf("%d", &param);
            enQueue(param, &list);
            enQueue(101, &params);
            enQueue(count(list), &lengths);
            break;
        }
    }
    while (!(emptyQueue(params) && emptyQueue(lengths)))
    {
        if (front(params) == 101)
            printf("%d\n", front(lengths));
        else
            printf("%d %d\n", front(params), front(lengths));
        deQueue(&params);
        deQueue(&lengths);
    }
    return 0;
}

// 
#include <stdlib.h>
#include<stdio.h>

//cai dac hang doi bang danh sach lien ket
typedef int ElementType;

struct Node
{
    ElementType Element;
    struct Node* Next;
};

typedef struct Node* Position;

typedef struct
{
    Position Front, Rear;
} Queue;

void makenullQueue(Queue* pS)
{
    pS->Front = (Position)malloc(sizeof(struct Node));
    pS->Front->Next = NULL;
    pS->Rear = pS->Front;
}

int emptyQueue(Queue Q)
{
    return Q.Front == Q.Rear;
}

ElementType front(Queue Q)
{
    return Q.Front->Next->Element;
}

void deQueue(Queue* pQ)
{
    pQ->Front = pQ->Front->Next;
}

void enQueue(ElementType x, Queue* pQ)
{
    pQ->Rear->Next = (Position)malloc(sizeof(struct Node));
    pQ->Rear = pQ->Rear->Next;
    pQ->Rear->Element = x;
    pQ->Rear->Next = NULL;
}

int count(Queue Q)
{
    int c = 0;
    Position P = Q.Front;
    while (P != Q.Rear)
    {
        c++;
        P = P->Next;
    }
    return c;
} 

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "AStack.c"
#include "CAQueue.c"

int isAb(char c)
{
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int main()
{
    char chuoi[255];
    fgets(chuoi, 100, stdin);
    fflush(stdin);
    int length = strlen(chuoi);
    chuoi[length - 1] = '\0';
    length--;

    Stack S;
    makenullStack(&S);
    Queue Q;
    makenullQueue(&Q);

    for (int i = 0; i < length; i++)
    {
        if (!isAb(chuoi[i]))
            continue;
        push(tolower(chuoi[i]), &S);
        enQueue(tolower(chuoi[i]), &Q);
    }

    while (!(emptyQueue(Q) && emptyStack(S)))
    {
        if (front(Q) != top(S))
        {
            printf("\"%s\" doc xuoi khac doc nguoc", chuoi);
            return 0;
        }
        pop(&S);
        deQueue(&Q);
    }
    printf("\"%s\" doc xuoi va doc nguoc nhu nhau", chuoi);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PQueue.c"

int main()
{
    char pass[1000];
    char key[100];
    char hash[100];

    fgets(pass, 1000, stdin);
    fflush(stdin);
    pass[strlen(pass) - 1] = '\0';
    int passLength = strlen(pass);

    scanf("%s", key);
    getchar();
    int keyLength = strlen(key);

    Queue keys;
    makenullQueue(&keys);

    for (int i = 0; i < keyLength; i++)
        enQueue((int)key[i] - 48, &keys);

    for (int i = 0; i < passLength; i++)
    {
        hash[i] = pass[i] + front(keys);
        hash[i + 1] = '\0';
        enQueue(front(keys), &keys);
        deQueue(&keys);
    }
    printf("%s\n", hash);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PQueue.c"

// Giai ma

int main()
{
    char hashPass[1000];
    char key[100];
    char pass[100];

    fgets(hashPass, 1000, stdin);
    fflush(stdin);
    hashPass[strlen(hashPass) - 1] = '\0';
    int passLength = strlen(hashPass);

    scanf("%s", key);
    getchar();
    int keyLength = strlen(key);

    Queue keys;
    makenullQueue(&keys);

    for (int i = 0; i < keyLength; i++)
        enQueue((int)key[i] - 48, &keys);

    for (int i = 0; i < passLength; i++)
    {
        pass[i] = hashPass[i] - front(keys);
        pass[i + 1] = '\0';
        enQueue(front(keys), &keys);
        deQueue(&keys);
    }
    printf("%s\n", pass);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include "PIQueue.c"

int input()
{
    int x;
    scanf("%d", &x);
    return x;
}

// Dua du lieu khach hang vao hang doi
void lineUp(int dTime, int client, Queue* line)
{
    makenullQueue(line);
    for (int i = 0; i < client; i++)
        enQueue(dTime * (i + 1), line);
}

// lam moi time tai quay
void reset(int A[], int n)
{
    for (int i = 0; i < n; i++)
        A[i] = 0;
}

int main()
{
    int client = input();
    int maxCashier = input();
    int tranferTime = input();
    int dTime = input();
    int waitTime = input();

    Queue line;
    int cashiers[maxCashier];

    int totalTime;

    for (int cashierOpen = 1; cashierOpen <= maxCashier; cashierOpen++)
    {
        // Lam moi du lieu
        totalTime = 0;
        lineUp(dTime, client, &line);
        reset(cashiers, cashierOpen);

        while (!emptyQueue(line))
        {
            for (int cashierIdx = 0; cashierIdx < cashierOpen; cashierIdx++)
            {
                if (emptyQueue(line))
                    continue;
                if (front(line) > cashiers[cashierIdx])
                    cashiers[cashierIdx] = front(line);
                totalTime += cashiers[cashierIdx] - front(line) + tranferTime;
                cashiers[cashierIdx] += tranferTime;
                deQueue(&line);
            }
        }
        printf(
            "So quay: %d; Thoi gian cho trung binh: %.1f\n",
            cashierOpen,
            (float)(totalTime / client));
        if (totalTime / client <= waitTime)
        {
            printf("=> Sieu thi se mo %d quay\n", cashierOpen);
            return 0;
        }
    }

    printf(
        "Voi %d quay hien co, khach phai cho it nhat %.1f giay moi duoc phuc vu.\n",
        maxCashier,
        (float)(totalTime / client));

    return 0;
}