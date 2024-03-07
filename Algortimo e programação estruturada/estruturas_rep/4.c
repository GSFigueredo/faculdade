#include <stdio.h>
#include <math.h>

int main()
{

    int c;

    for(c = 0; c<16; c+=3) {
        if(c > 0) {
            printf("\n%d", c);
        }
    }

    return 0;
}