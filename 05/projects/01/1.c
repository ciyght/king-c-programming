#include <stdio.h>

int main(void)
{
    int number, sign, ndigits;

    printf("Enter a number: ");
    scanf("%d", &number);
    
    sign = 1;
    if (number < 0) {
        number *= -1;
        sign = -1;
    }

    if (number <= 9)
        ndigits = 1;
    else if (number <= 99)
        ndigits = 2;
    else if (number <= 999)
        ndigits = 3;
    else
        ndigits = 4;

    number *= sign;
        
    printf("The number %d has %d digits\n", number, ndigits);
    return 0;
}
