#include <stdio.h> 
#include <stdlib.h>
typedef int ElementType;
struct Node {
    ElementType Element;
    struct Node* Next;
};
typedef struct Node* Position;
typedef Position List;

Position first(List L) {
    return L;
}

Position endList(List L) {
    Position P;
    P = first(L);
    while (P->Next != NULL)
        P = P->Next;
    return P;
}

int emptyList(List L)
{
    return L->Next == NULL;
}

void insertList(ElementType x, Position P, List* pL) {
    Position T;
    T = (struct Node*)malloc(sizeof(struct Node));
    T->Element = x;
    T->Next = P->Next;
    P->Next = T;
}

void makenullList(List* pL) {
    (*pL) = (struct Node*)malloc(sizeof(struct Node));
    (*pL)->Next = NULL;
}

void readList(List* pL) {
    int i, n;
    ElementType x;
    makenullList(pL);
    scanf("%d", &n);
    for (i = 1; i <= n; i++) {
        scanf("%d", &x);
        insertList(x, endList(*pL), pL);
    }
}

void printList(List L) {
    Position P;
    P = L;
    while (P->Next != NULL) {
        printf("%d ", P->Next->Element);
        P = P->Next;
    }
    printf("\n");
}

void deleteList(Position P, List* pL) {
    Position Temp;
    if (P->Next != NULL) {
        Temp = P->Next;
        P->Next = Temp->Next;
        free(Temp);
    }
}

Position next(Position P, List L) {
    return P->Next;
}

Position previous(Position P, List L) {
    Position Q = L;
    while (Q->Next != P)
        Q = Q->Next;
    return Q;
}

Position locate(ElementType x, List L) {
    Position P;
    P = L;
    while (P->Next != NULL)
        if (P->Next->Element == x) return P;
        else P = P->Next;
    return P;
}

Position myLocate(ElementType x, int i, List L) { //Tim kiem 1 phan tu trong danh sach
    Position P, E;
    P = first(L);
    E = endList(L);
    int count = 0;
    while (P != E && count < i) {
        if (retrieve(P, L) == x)
            count++;
        if (count < i)
            P = next(P, L);
    }
    return P;
}

Position next(Position P, List L) {
    return P->Next;
}
Position previous(Position P, List L) {
    Position Q = L;
    while (Q->Next != P)
        Q = Q->Next;
    return Q;
}

ElementType retrieve(Position P, List L) {
    if (P->Next != NULL)
        return P->Next->Element;
}

float getAvg(List L) {
    float sum = 0;
    int length = 0;
    Position P = L;
    if (P->Next == NULL)
        return -10000;
    while (P->Next != NULL)
    {
        sum += P->Next->Element;
        length++;
        P = P->Next;
    }
    return sum / length;
}

void printOddNumbers(List L)
{
    Position P = L;
    while (P->Next != NULL)
    {
        if (P->Next->Element % 2 != 0)
            printf("%d ", P->Next->Element);
        P = P->Next;
    }
    printf("\n");
}

void prinEvenNumbers(List L)
{
    Position P = L;
    while (P->Next != NULL)
    {
        if (P->Next->Element % 2 == 0)
            printf("%d ", P->Next->Element);
        P = P->Next;
    }
    printf("\n");
}

void normalize(List* pL)
{
    Position P = *pL, Q;
    while (P->Next != NULL)
    {
        Q = P->Next;
        while (Q->Next != NULL)
        {
            if (Q->Next->Element == P->Next->Element)
                deleteList(Q, pL);
            Q = Q->Next;
        }
        P = P->Next;
    }
}

List readSet()
{
    List L;
    makenullList(&L);
    int n;
    ElementType x;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        if (!member(x, L))
            addFirst(x, &L);
    }
    return L;
}

void removeAll(ElementType x, List* pL)
{
    while (locate(x, *pL)->Next != NULL)
        deleteList(locate(x, *pL), pL);
}

void readList(List* pL)
{
    makenullList(pL);
    int n;
    Position P = *pL,
        N;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        N = (Position)malloc(sizeof(struct Node));
        scanf("%d", &N->Element);
        P->Next = N;
        P = P->Next;
    }
}

void sort(List* pL)
{
    Position P = *pL,
        N;
    while (P->Next != NULL)
    {
        N = P->Next;
        while (N->Next != NULL)
        {
            if (P->Next->Element > N->Next->Element)
            {
                ElementType Temp = P->Next->Element;
                P->Next->Element = N->Next->Element;
                N->Next->Element = Temp;
            }
            N = N->Next;
        }
        P = P->Next;
    }
}

List unionSet(List L1, List L2)
{
    List L;
    makenullList(&L);
    Position P = L1;
    while (P->Next != NULL)
    {
        if (!member(P->Next->Element, L))
            append(P->Next->Element, &L);
        P = P->Next;
    }
    P = L2;
    while (P->Next != NULL)
    {
        if (!member(P->Next->Element, L))
            append(P->Next->Element, &L);
        P = P->Next;
    }
    return L;
}

List intersection(List L1, List L2)
{
    List L;
    makenullList(&L);
    Position P = L2;
    while (P->Next != NULL)
    {
        if (!member(P->Next->Element, L) && member(P->Next->Element, L1))
            append(P->Next->Element, &L);
        P = P->Next;
    }
    return L;
}

int member(ElementType x, List L)
{
    Position P = L;
    while (P->Next != NULL)
    {
        if (P->Next->Element == x)
            return 1;
        P = P->Next;
    }
    return 0;
}

void erase(ElementType x, List* pL)
{
    if (locate(x, *pL)->Next != NULL)
        deleteList(locate(x, *pL), pL);
}

List difference(List L1, List L2)
{
    List L;
    makenullList(&L);
    Position P = L1;
    while (P->Next != NULL)
    {
        if (!member(P->Next->Element, L) && !member(P->Next->Element, L2))
            append(P->Next->Element, &L);
        P = P->Next;
    }
    return L;
}

void deleteX(ElementType x, List* pL)
{
    Position P = first(*pL);
    while (P != endList(*pL))
    {
        if (retrieve(P, *pL) == x)
            deleteList(P, pL);
        else
            P = next(P, *pL);
    }
} 

void copyEvenNumbers(List L, List* pL){
    makenullList(pL);
    Position P = L;
    while (P->Next != NULL)
    {
        if (P->Next->Element % 2 == 0)
            append(P->Next->Element, pL);
        P = P->Next;
    }
}

void append(ElementType x, List* pL){
    Position P = endList(*pL);
    Position T = (Position)malloc(sizeof(struct Node));
    T->Element = x;
    T->Next = NULL;
    P->Next = T;
}

void addFirst(ElementType x, List* pL)
{
    Position P;
    P = (Position)malloc(sizeof(struct Node));
    P->Element = x;
    P->Next = (*pL)->Next;
    (*pL)->Next = P;
}

int main() {
    List L;
    List L1, L2;
    printf("%.3f", getAvg(L));
    readList(&L);
    printList(L);
    sort(&L);
    copyEvenNumbers(L, &L);
    ElementType x;
    erase(x, &L);
    printOddNumbers(L1);
    copyEvenNumbers(L1, &L2);
    printList(L2);
    ElementType x;
    scanf("%d", &x);
    removeAll(x, &L);
    List L1 = readSet(),
        L2 = readSet();
    printList(L1);
    printList(L2);
    printList(unionSet(L1, L2));
    List L1 = readSet(),
        L2 = readSet();
    printList(L1);
    printList(L2);
    printList(difference(L1, L2));
    L1 = readSet();
    L2 = readSet();
    printList(L1);
    printList(L2);
    printList(intersection(L1, L2));

    return 0;
}