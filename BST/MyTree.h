#ifndef TREE_LL
#define TREE_LL

#include <stdbool.h>

typedef struct{
	int day,month,year;
}Date;

typedef struct{
	char prodName[20];
	float prodPrice;
	Date expDate;
	int prodQty;
}Product;

typedef struct node{
	Product item;
	struct node* left, *right;
}NodeType,*NodePtr;

Product add(NodePtr* tree,Product newItem);
void delete(NodePtr* tree,Product newItem);
void BFS(NodePtr* tree);
void inorder(NodePtr* tree);
void preorder(NodePtr* tree);
void postorder(NodePtr* tree);
bool isEmpty(NodePtr tree);

#endif
