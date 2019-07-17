
#include <stdio.h>
#include "c-sum.h"

#define NUM 200

extern void sum_abs_(int *data, int *num, int *asum);

int main(int argc, char **argv)
{
    int data[NUM], num, i;

    num = NUM;
    for (i=0; i < num; i++) {
        data[i] = i - 100 + 1;  /* NOTE: difference in array numbering */  
    }

    printf("sum=%d\n", sum_abs_(*data, *num));
    return 0;
}
