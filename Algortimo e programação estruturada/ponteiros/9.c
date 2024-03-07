#include <stdio.h> 
#include <math.h> 

int main () {

    int matrix[3][3];

    for(int c = 0; c < 3; c++) {
        for(int c1 = 0; c1 < 3; c1++){
            printf("%d", &matrix[c][c1]);
            printf(" ");
        }

        printf("\n");
    }

    return 0;
}