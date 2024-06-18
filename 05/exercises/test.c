#include <stdio.h>

int main(void)
{
    int area_code;

    area_code = 0;
    scanf("%d", &area_code);

    switch (area_code) {
        case 229:
            printf("Albany\n");
            break;
        case 404: case 470: case 678: case 770:
            printf("Atlanta\n");
            break;
        case 478:
            printf("Macon");
            break;
        case 706: case 762:
            printf("Columbus");
            break;
        case 912:
            printf("Savannah");
            break;
        default:
            printf("Area code not recognized\n");
    }

    return 0;
}
