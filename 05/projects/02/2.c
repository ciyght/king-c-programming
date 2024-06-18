#include <stdio.h>


int main(void)
{
    int hour, minute;

    printf("Enter a 24-hour time: ");
    scanf("%d :%d", &hour, &minute);

    if (hour < 12) {
        printf("Equivalent 12-hour time: %02d:%02d AM\n",
            hour == 0 ? 12 : hour, minute);
    } else {
        printf("Equivalent 12-hour time: %02d:%02d PM\n",
            hour == 12 ? 12 : hour - 12, minute);
    }

    return 0;
}
