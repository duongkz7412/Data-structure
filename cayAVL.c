#include <stdio.h>
#include <stdlib.h>
typedef int KeyType;
struct Node
{
    KeyType Key;
    int Height;
    struct Node* Left, * Right;
};

typedef struct Node* AVLTree;

void printLeaves(AVLTree root){
    if (root == NULL)
        return;

    if (root->Left == NULL && root->Right == NULL)
        printf("%d ", root->Key);

    printLeaves(root->Left);
    printLeaves(root->Right);
}

AVLTree search(KeyType key, AVLTree root){
    if (root == NULL)
        return NULL;
    if (root->Key == key)
        return root;
    if (root->Key > key)
        return search(key, root->Left);
    return search(key, root->Right);
}

#define true 1
#define false 0

int isAVL(AVLTree root){
    if (root == NULL)
        return true;
    int balance = getBalance(root);
    if (balance < -1 || balance > 1)
        return false;

    return isAVL(root->Left) && isAVL(root->Right);
}

int getHeight(AVLTree root){
    return root == NULL ? -1 : root->Height;
}

int getBalance(AVLTree node){
    if (node == NULL)
        return 0;
    return getHeight(node->Left) - getHeight(node->Right);
}

void printLRN(AVLTree root){
    if (root == NULL)
        return;

    printLRN(root->Left);
    printLRN(root->Right);
    printf("(%d - %d); ", root->Key, getHeight(root));
}

void printNLR(AVLTree root){
    if (root == NULL)
        return;
    printf("(%d - %d); ", root->Key, getHeight(root));
    printNLR(root->Left);
    printNLR(root->Right);
}

void printHeight(int height, AVLTree root){
    if (root == NULL)
        return;
    printHeight(height, root->Left);
    if (getHeight(root) == height)
        printf("%d ", root->Key);
    printHeight(height, root->Right);
}

AVLTree setAllHeight(AVLTree root){
    if (root == NULL)
        return NULL;
    root->Left = setAllHeight(root->Left);
    root->Right = setAllHeight(root->Right);
    root->Height = 1 + max(getHeight(root->Left), getHeight(root->Right));
    return root;
}

AVLTree leftRotate(AVLTree root){
    AVLTree rightChild = root->Right;
    AVLTree leftRightChild = rightChild->Left;
    rightChild->Left = root;
    root->Right = leftRightChild;

    return setAllHeight(rightChild);
}

AVLTree rightRotate(AVLTree root){
    if (root == NULL)
        return NULL;
    AVLTree leftChild = root->Left;
    AVLTree rightLeftChild = leftChild->Right;
    leftChild->Right = root;
    root->Left = rightLeftChild;

    return setAllHeight(leftChild);
}

AVLTree leftrightRotate(AVLTree node){
    node->Left = leftRotate(node->Left);
    return rightRotate(node);
}

AVLTree rightleftRotate(AVLTree node){
    node->Right = rightRotate(node->Right);
    return leftRotate(node);
}

AVLTree insertNode(KeyType key, AVLTree root){
    if (root == NULL){
        AVLTree tree = (AVLTree)malloc(sizeof(struct Node));
        tree->Key = key;
        tree->Height = 0;
        tree->Left = NULL;
        tree->Right = NULL;

        return tree;
    }
    if (root->Key == key)
        return root;
    if (key < root->Key)
        root->Left = insertNode(key, root->Left);
    else
        root->Right = insertNode(key, root->Right);
    if (getBalance(root) > 1){
        if (getBalance(root->Left) > 0){
            return setAllHeight(rightRotate(root));
        }
        return setAllHeight(leftrightRotate(root));
    }
    if (getBalance(root) < -1){
        if (getBalance(root->Right) < 0){
            return setAllHeight(leftRotate(root));
        }
        return setAllHeight(rightleftRotate(root));
    }
    return setAllHeight(root);
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}
struct Node* minValueNode(struct Node* node){
    struct Node* current = node;
    while (current->Left != NULL)
        current = current->Left;

    return current;
}
struct Node* deleteNode(struct Node* root, int Key)
{
    // STEP 1: PERFORM STANDARD BST DELETE

    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the
    // root's key, then it lies in left subtree
    if (Key < root->Key)
        root->Left = deleteNode(root->Left, Key);

    // If the key to be deleted is greater than the
    // root's key, then it lies in right subtree
    else if (Key > root->Key)
        root->Right = deleteNode(root->Right, Key);

    // if key is same as root's key, then This is
    // the node to be deleted
    else
    {
        // node with only one child or no child
        if ((root->Left == NULL) || (root->Right == NULL))
        {
            struct Node* temp = root->Left ? root->Left :
                root->Right;

            // No child case
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else // One child case
                *root = *temp; // Copy the contents of
                               // the non-empty child
            free(temp);
        }
        else
        {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            struct Node* temp = minValueNode(root->Right);

            // Copy the inorder successor's data to this node
            root->Key = temp->Key;

            // Delete the inorder successor
            root->Right = deleteNode(root->Right, temp->Key);
        }
    }
    // If the tree had only one node then return
    if (root == NULL)
        return root;

    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE
    root->Height = 1 + max(Height(root->Left),Height(root->Right));

    // STEP 3: GET THE BALANCE FACTOR OF THIS NODE (to
    // check whether this node became unbalanced)
    int balance = getBalance(root);

    // If this node becomes unbalanced, then there are 4 cases

    // Left Left Case
    if (balance > 1 && getBalance(root->Left) >= 0)
        return rightRotate(root);

    // Left Right Case
    if (balance > 1 && getBalance(root->Left) < 0)
    {
        root->Left = leftRotate(root->Left);
        return rightRotate(root);
    }

    // Right Right Case
    if (balance < -1 && getBalance(root->Right) <= 0)
        return leftRotate(root);

    // Right Left Case
    if (balance < -1 && getBalance(root->Right) > 0)
    {
        root->Right = rightRotate(root->Right);
        return leftRotate(root);
    }
    return root;
}
