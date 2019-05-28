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

    for(i=0; i<=9; i++){
        insert(&bt, arr[i]);
    }

    printf("\n");
    printf("In-Order traversal of binary tree:\n");
    inorder(bt);

    return 0;
}

void insert(struct btreenode **sr, int num) {
    if (*sr == NULL){
        *sr == (struct btreenode *) malloc (sizeof ( struct btreenode));
        ( *sr) -> leftChild = NULL;
        (* sr) -> data = num;
        (*sr) -> rightChild = NULL;
    } else {
        if (num < (*sr) -> data){
            insert(& ((*sr) -> leftChild), num);
        } else {
            insert(&(( *sr) -> rightChild), num);
        }
    }
}

void inorder(struct btreenode *sr){
    if (sr != NULL) {
        inorder(sr -> leftChild);
        printf("%d\t", sr -> data);
        inorder(sr -> rightChild);
    }
}