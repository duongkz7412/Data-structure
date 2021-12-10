#include <stdio.h>
#include <stdlib.h>

typedef char DataType;
struct Node {
    DataType     Data;
    struct Node* Left, * Right;
};
typedef struct Node* Tree;

void makenullTree(Tree* pT){
    (*pT)=NULL; 
}

int emptyTree(Tree T) {
    return T == NULL;
}

Tree leftChild(Tree n) {
    if (n != NULL) return n->Left;
    else return NULL;
}

Tree rightChild(Tree n) {
    if (n != NULL) return n->Right; 
    else return NULL;
}

int isLeaf(Tree n) {
    if (!emptyTree(n))
        return(n->Left == NULL) && (n->Right == NULL);
    else return 0;
}

int getLeaves(Tree T){
    if (T == NULL)
        return 0;
    if (T->Left == NULL && T->Left == NULL)
        return 1;
    return getLeaves(T->Left) + getLeaves(T->Right);
}

// duyệt tiền tự
void preOrder(Tree T){
    if (T == NULL)
        return;
    printf("%d ", T->Data);
    preOrder(T->Left);
    preOrder(T->Right);
}

// duyệt trung tự
void inOrder(Tree T){
    if (T == NULL)
        return;
    inOrder(T->Left);
    printf("%d ", T->Data);
    inOrder(T->Right);
}

// duyệt hậu tự
void postOrder(Tree T){
    if (T == NULL)
        return;
    postOrder(T->Left);
    postOrder(T->Right);
    printf("%d ", T->Data);
} 

Tree createTree(int x, Tree l, Tree r) {
    Tree T = (Tree)malloc(sizeof(struct Node));
    T->Data = x;
    T->Left = l;
    T->Right = r;
    return T;
}

//tìm chỉ mục của một ký tự x trong chuỗi biểu thức trung tự in bắt đầu từ vị trí start đến vị trí end
int findIndex(DataType x, char in[], int star, int end) {
    int i = star;
    while (i <= end) {
        if (x == in[i])
            return i;
        else
            i++;
    }
    return i;
}
//dựng một cây nhị phân từ các biểu thức duyệt tiền tự và trung tự.
int CURRENT_INDEX = 0;
Tree createTree(char* pre, char* in, int start, int end) {
    if (start > end)
        return NULL;
    Tree T = (Tree)malloc(sizeof(struct Node));
    if (start == end) {
        T->Data = pre[CURRENT_INDEX];
        T->Left = NULL;
        T->Right = NULL;
        CURRENT_INDEX++;
        return T;
    }
    T->Data = pre[CURRENT_INDEX];
    int i = findIndex(pre[CURRENT_INDEX], in, start, end);
    CURRENT_INDEX++;
    T->Left = createTree(pre, in, start, i - 1);
    T->Right = createTree(pre, in, i + 1, end);
    return T;
}

int findMax(Tree T) {
    if (T == NULL)
        return 0;
    if (isLeaf(T))
        return T->Data;
    int maxLeft = findMax(T->Left);
    int maxRight = findMax(T->Right);
    return maxLeft > maxRight ? maxLeft : maxRight;
}

Tree findElement(DataType x, Tree T) {
    if (T == NULL || T->Data == x)
        return T;
    Tree lef = findElement(x, T->Left);
    Tree rig = findElement(x, T->Right);
    if (lef == NULL)
        return rig;
    return lef;
}

// tính bán kính của một cây nhị phân
int getHeight(Tree T) {
    if (T == NULL || (T->Left == NULL && T->Right == NULL))
        return 0;
    int lh = getHeight(T->Left);
    int rh = getHeight(T->Right);
    return 1 + (lh > rh ? lh : rh);
}
void getDiameter(Tree T, int* r) {
    if (T == NULL)
        return;
    *r = getHeight(T->Left) + getHeight(T->Right) + 3;
}

//đếm số nút có đủ hai con
int getFullNodes(Tree T) {
    if (T == NULL || isLeaf(T))
        return 0;
    if (T->Left != NULL && T->Right != NULL)
        return 1 + getFullNodes(T->Left) + getFullNodes(T->Right);
    return getFullNodes(T->Left) + getFullNodes(T->Right);
}

//chuyển đổi một cây nhị phân sang cây phản chiếu của nó
Tree convertTree(Tree T) {
    if (T == NULL)
        return NULL;
    Tree tree = (Tree)malloc(sizeof(struct Node));
    tree->Data = T->Data;
    tree->Left = convertTree(T->Right);
    tree->Right = convertTree(T->Left);
    return tree;
}

//in nội dung của một mảng path có độ dài len & hiển thị tất cả các đường đi (từ nút gốc đến nút lá) và có độ dài đường đi thỏa điều kiện cho trước
void printArray(int path[], int len) {
    int i;
    for (i = 0;->D i < len; i++)
        printf("%d", path[i]);
    printf("\n");
}
void printAllPaths(Tree T, int path[], int len, int pathlen) {
    if (T == NULL || len > pathlen + 1)
        return;
    path[len] = T->Data;
    len++;
    if (len == pathlen + 1 && isLeaf(T))
        printArray(path, len);
    printAllPaths(T->Left, path, len, pathlen);
    printAllPaths(T->Right, path, len, pathlen);
}

//kiểm tra xem hai cây có là phản chiếu của nhau hay không
int isMirrors(Tree T1, Tree T2) {
    if (T1 == NULL) {
        if (T2 == NULL)
            return 1;
        else return 0;
    }
    if (T2 == NULL)
        return 0;
    if (T1->Data != T2->Data)
        return 0;
    return isMirrors(T1->Left, T2->Right) && isMirrors(T1->Right, T2->Left);
}