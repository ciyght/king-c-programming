#include <stdio.h>


int main(void)
{
    int hh,
        mm,
        min_since_midnight,
        t1 = 480,
        t2 = 583,
        t3 = 679,
        t4 = 767,
        t5 = 480,
        t6 = 945,
        t7 = 1140,
        t8 = 1305;

    printf("Enter a 24-hour time: " );
    scanf("%d :%d", &hh, &mm);
    min_since_midnight = hh * 60 + mm;

    if (min_since_midnight <= t1 + (t2 - t1) / 2)
        printf("Closest departure time is 8:00 a.m., arriving at 10:16 a.m.\n");
    else if (min_since_midnight <= t2 + (t3 - t2) / 2)
        printf("Closest departure time is 9:43 a.m., arriving at 11:52 a.m.\n");
    else if (min_since_midnight <= t3 + (t4 - t3) / 2)
        printf("Closest departure time is 11:19 a.m., arriving at 1:31 p.m.\n");
    else if (min_since_midnight <= t4 + (t5 - t4) / 2)
        printf("Closest departure time is 12:47 a.m., arriving at 3:00 p.m.\n");
    else if (min_since_midnight <= t5 + (t6 - t5) / 2)
        printf("Closest departure time is 2:00 p.m., arriving at 4:08 p.m.\n");
    else if (min_since_midnight <= t6 + (t7 - t6) / 2)
        printf("Closest departure time is 3:45 p.m., arriving at 5:55 p.m.\n");
    else if (min_since_midnight <= t7 + (t8 - t7) / 2)
        printf("Closest departure time is 7:00 p.m., arriving at 9:20 p.m.\n");
    else
        printf("Closest departure time is 9:45 p.m., arriving at 11:08 p.m.\n");

    return 0;
}
