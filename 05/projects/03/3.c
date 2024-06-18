#include <stdio.h>


int main(void)
{
    int n_shares;
    float commission, price, value;

    printf("Enter the number of shares: ");
    scanf ("%d", &n_shares);
    printf("Enter price per share: ");
    scanf ("%f", &price);

    /* Commission of the original broker */
    value = n_shares * price;
    if (value < 2500.00f)
        commission = 30.00f + .017f * value;
    else if (value < 6250.00f)
        commission = 56.00f + .0066f * value;
    else if (value < 20000.00f)
        commission = 76.00f + .0034f * value;
    else if (value < 50000.00f)
        commission = 100.00f + .0022f * value;
    else if (value < 500000.00f)
        commission = 155.00f + .0011f * value;
    else
        commission = 255.00f + .0009f * value;

    if (commission < 39.00f)
        commission = 39.00f;
    printf("Original commission: $%.2f\n", commission);

    /* Commission of the rival broker */
    commission = 33.00f + (n_shares < 2000 ? 0.03f : 0.02f) * n_shares;
    printf("Rival commission: $%.2f\n", commission);

    return 0;
}
