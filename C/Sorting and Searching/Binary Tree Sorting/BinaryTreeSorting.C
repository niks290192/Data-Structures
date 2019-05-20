/*Binary Tree Sorting*/

#include <stdio.h>

struct btreenode {
    struct btreenode *leftChild;
    int data;
    struct btreenode *rightChild;
};

void insert { struct btreenode **, int };
void inorder { struct btreenode * };

int main() {
    struct btreenode *bt;
    int arr[10] = { 11, 2, 9, 13, 57, 25, 17, 1, 90, 3 };
    int i;

    bt = NULL;

    printf("Binary Tree Sort.\n\n");

    printf("Array: \n");
    for(i=0; i<=9; i++) {
        printf("%d\t", arr[i]);
    }

    
}