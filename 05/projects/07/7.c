#include <stdio.h>


int main(void)
{
    int a, b, c, d, min, max;

    printf("Enter four integers: " );
    scanf("%d %d %d %d", &a, &b, &c, &d);

    /* Compare a with b */
    if (a >= b) {
        max = a;
        min = b;
    } else {
        max = b;
        min = a;
    }

    /* Compare with c */
    if (c >= max) {
        max = c;
    } else if (c < min) {
        min = c;
    }

    /* Compare with d */
    if (d >= max) {
        max = d;
    } else if (d < min) {
        min = d;
    }

    printf("Largest: %d\n", max);
    printf("Smallest: %d\n", min);

    return 0;
}
