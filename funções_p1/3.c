#include <stdio.h> 
#include <math.h>
#include <string.h> 

int main() {

   /* int mat[10][10];

    for(int l = 1; l < 11; l++) {

        for(int c = 1; c < 11; c++) {
            printf("Digite o valor da linha %d coluna %d: ", l, c);
            scanf("%d", &mat[l][c]);
        }

    }
*/

    int mat[2][2];

    for(int l = 1; l < 3; l++) {

        for(int c = 1; c < 3; c++) {
            printf("Digite o valor da linha %d coluna %d: ", l, c);
            scanf("%d", &mat[l][c]);
        }

    }

    for(int l = 1; l < 3; l++) {
        
        for(int c = 1; c < 3; c++) {
            printf("%d", mat[l][c]);
        }

    }

    return 0;
}