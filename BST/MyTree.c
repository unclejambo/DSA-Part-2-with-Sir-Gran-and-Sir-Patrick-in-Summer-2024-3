#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "MyTree.h"

typedef struct queueNode {
    NodePtr treeNode;
    struct queueNode* next;
} QueueNode, *QueueNodePtr;

typedef struct {
    QueueNodePtr front;
    QueueNodePtr rear;
} Queue;

void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

bool isQueueEmpty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q, NodePtr treeNode) {
    QueueNodePtr newNode = (QueueNodePtr)malloc(sizeof(QueueNode));
    newNode->treeNode = treeNode;
    newNode->next = NULL;
    if (q->rear != NULL) {
        q->rear->next = newNode;
    }
    q->rear = newNode;
    if (q->front == NULL) {
        q->front = newNode;
    }
}

NodePtr dequeue(Queue* q) {
    if (isQueueEmpty(q)) {
        return NULL;
    }
    QueueNodePtr temp = q->front;
    NodePtr treeNode = temp->treeNode;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return treeNode;
}

bool isEmpty(NodePtr tree){
	return tree == NULL;
}

Product createProduct(){
	Product newProduct;

    printf("Enter product name: ");
    scanf("%19s", newProduct.prodName);

    printf("Enter product price: ");
    scanf("%f", &newProduct.prodPrice);

    printf("Enter expiration date (day month year): ");
    scanf("%d %d %d", &newProduct.expDate.day, &newProduct.expDate.month, &newProduct.expDate.year);

    printf("Enter product quantity: ");
    scanf("%d", &newProduct.prodQty);

    return newProduct;
}

Product add(NodePtr* tree,Product newItem){
	
	if (*tree == NULL) {
        NodePtr newTree = (NodePtr)malloc(sizeof(NodeType));
        if (newTree == NULL) {
            printf("Error");
        }
        newTree->item = newItem;
        newTree->left = newTree->right = NULL;
        *tree = newTree;
    } else if (strcmp(newItem.prodName, (*tree)->item.prodName) < 0) {
        add(&(*tree)->left, newItem);
    } else if (strcmp(newItem.prodName, (*tree)->item.prodName) > 0) {
        add(&(*tree)->right, newItem);
    } else {
    }
    return newItem;
}

void delete(NodePtr* tree,Product newItem){
	
	if (*tree == NULL) {
        return;
    }

    if (strcmp(newItem.prodName, (*tree)->item.prodName) < 0) {
        delete(&(*tree)->left, newItem);
    } else if (strcmp(newItem.prodName, (*tree)->item.prodName) > 0) {
        delete(&(*tree)->right, newItem);
    } else {
        
        NodePtr temp;
        if ((*tree)->left == NULL) {
            temp = *tree;
            *tree = (*tree)->right;
            free(temp);
        } else if ((*tree)->right == NULL) {
            temp = *tree;
            *tree = (*tree)->left;
            free(temp);
        } else {
            NodePtr successor = (*tree)->right;
            while (successor->left != NULL) {
                successor = successor->left;
            }
            (*tree)->item = successor->item;
            delete(&(*tree)->right, successor->item);
        }
    }
	
}

void BFS(NodePtr* tree){
	if (*tree == NULL) {
        return;
    }

    Queue q;
    initQueue(&q);
    enqueue(&q, *tree);

    while (!isQueueEmpty(&q)) {
        NodePtr current = dequeue(&q);
        printf("%s ", current->item.prodName);

        if (current->left != NULL) {
            enqueue(&q, current->left);
        }
        if (current->right != NULL) {
            enqueue(&q, current->right);
        }
    }
    printf("\n");
}
 
void inorder(NodePtr* tree){
	
	 if(!isEmpty(*tree)){
        inorder(&(*tree)->left);
        printf("%s ", (*tree)->item.prodName);
        inorder(&(*tree)->right);
    }
}

void preorder(NodePtr* tree){
	
	 if(!isEmpty(*tree)){
        printf("%s ", (*tree)->item.prodName);
        preorder(&(*tree)->left);
        preorder(&(*tree)->right);
    }
}

void postorder(NodePtr* tree){
	
	 if(!isEmpty(*tree)){
        postorder(&(*tree)->left);
        postorder(&(*tree)->right);
        printf("%s ", (*tree)->item.prodName);
    }
}
