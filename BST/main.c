#include <stdio.h>
#include <stdlib.h>

#include "MyTree.h"

int main() {
	
	NodePtr MyTree = NULL;

    Product prod1 = { "lansiao", 100, {5, 5, 1111}, 1 };
    Product prod2 = { "balbacua", 2.5, {2, 8, 2222}, 1 };
    Product prod3 = { "paklay", 2.9, {5, 5, 5555}, 1 };
    Product prod4 = { "buwad", 3.0, {15, 7, 2023}, 10 };
    Product prod5 = { "hipon", 1.5, {20, 10, 2024}, 5 };
    Product prod6 = { "chocolanay", 4.2, {30, 12, 2024}, 7 };
    Product prod7 = { "MONGOS", 2.1, {25, 11, 2027}, 12 };

	add(&MyTree, prod3);
    add(&MyTree, prod4);
    add(&MyTree, prod5);
    add(&MyTree, prod6);
    add(&MyTree, prod1);
    add(&MyTree, prod2);
    add(&MyTree, prod7);

    inorder(&MyTree);
    printf("\n");
    printf("\n");

    preorder(&MyTree);
    printf("\n");
    printf("\n");

    postorder(&MyTree);
    printf("\n");
    printf("\n");

    BFS(&MyTree);
    printf("\n");
    printf("\n");

    delete(&MyTree, prod3);

    inorder(&MyTree);
    printf("\n");
    printf("\n");

    BFS(&MyTree);
    printf("\n");
    printf("\n");

    return 0;
}
