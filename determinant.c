#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *arv[]){
    //scan for the first number int size which indicates the size of matrix and scanf size by size matrix into muti-dimensional array matrix of size by size
    int size;
    scanf("%d", &size);
    double matrix[size][size];
    for(int a = 0; a < size; a++){
        for(int b = 0; b < size; b++){
        scanf("%lf",&matrix[a][b]);
        }	
    }
    //for each row, determine if the inital multipicant is 0 and swap rows or use gaussian mechanics to reduce the matrix
    for(int i = 0; i < size; i++){
         if(matrix[i][i] == 0){
             for(int j = 0;j < size; j++){
                double temp = matrix[i+1][j];
                matrix[i+1][j] = -1 * matrix[i][j];
                matrix[i][j] = temp;
            }
         }
        if(i != 0){
            for(int j = 0; j < i; j++){
                double a = matrix[j][j];
                double b = matrix[i][j];
                if(a != 0){
                    double c = b/a;
                    double matrix_b[size];
                    for(int k = 0;k < size; k++){
                      matrix_b[k] = c * matrix[j][k];
                    }
                    for(int l = 0; l < size; l++){
                        matrix[i][l] = matrix[i][l] - matrix_b[l];
                     }
                }
            }
        }
    }
    double number = 1;
    //mutliply the diagonals
    for(int o = 0; o < size; o++){
        number = number * matrix[o][o];
    }
    //print the determinants
    printf("%f\n",number);
 }