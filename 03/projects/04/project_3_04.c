#include <stdio.h>

int main(void) {
    int area_code, prefix, subscriber;

    printf("Enter phone number [(xxx) xxx-xxxx]: ");
    scanf(" (%d ) %d- %d", &area_code, &prefix, &subscriber);
    printf("You entered %.3d.%3d.%.4d\n", area_code, prefix, subscriber);

    return 0;
}
