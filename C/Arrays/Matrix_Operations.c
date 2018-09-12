#include <stdio.h>
#include <stdlib.h>

#define MAX 3

void create(int[3][3]);
void display(int[3][3]);
void matadd(int[3][3],int[3][3],int[3][3]);
void matmul(int[3][3],int[3][3],int[3][3]);
void transpose(int[3][3],int[3][3]);

int main(){
    int mat1[3][3], mat2[3][3], mat3[3][3], mat4[3][3],mat5[3][3];
    system("cls");

    printf("Enter elements for first array:\n\n");
    create(mat1);

    printf("Enter elements for second array:\n\n");
    create(mat2);

    matadd(mat1,mat2,mat3);
    printf("After Addition:\n");
    display(mat3);

    matmul(mat1,mat2,mat4);
    printf("After multipication:\n");
    display(mat4);

    transpose(mat1, mat5);
    printf("Transpose of first matrix:\n");
    display(mat5);

    return 0;
}

// Create matrix mat
void create(int mat[3][3]){
    int i,j;
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++) {
            printf("Enter The element:");
            scanf("%d",&mat[i][j]);
        }
    }
    printf("\n");
}

//Display the contents of matrix
void display(int mat[3][3]) {
    int i,j;
    for(i=0;i<MAX;i++) {
        for(j=0;j<MAX;j++) {
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
}

//Adds Two matrices M1 and M2
void matadda(int m1[3][3], int m2[3][3], int m3[3][3]) {
    int i,j;
    for(i=0;i<MAX;i++) {
        m3[i][j] = m1[i][j] + m2[i][j];
    }
}

//Multiplies Two matrices M1 and M2
void matmul(int m1[3][3], int m2[3][3], int m3[3][3]) {
    int i,j,k;
    for(k=0;k<MAX;k++) {
        for(i=0;i<MAX;i++){
            m3[k][i] = 0;
            for(j=0;j<MAX;j++){
                m3[k][i] += m1[k][j] + m2[j][i];
            }
        }
    }
}

//Obtains transpose of matrix M1

void transpose(int m1[3][3], int m2[3][3]){
    int i,j;
    for(i=0;i<MAX;i++) {
        for(j=0;j<MAX;j++){
            m2[i][j] = m1[j][i];
        }
    }
}