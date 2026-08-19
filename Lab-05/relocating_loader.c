#include <stdio.h>

int main()
{
    int originalStart;
    int loadingAddress;
    int relocationFactor;
    int numberOfAddresses;
    int address;
    int relocatedAddress;
    int i;

    printf("Enter original starting address: ");
    scanf("%d", &originalStart);

    printf("Enter loading address: ");
    scanf("%d", &loadingAddress);

    relocationFactor = loadingAddress - originalStart;

    printf("\nRelocation Factor = %d\n", relocationFactor);

    printf("\nEnter number of relocatable addresses: ");
    scanf("%d", &numberOfAddresses);

    printf("\nEnter the addresses:\n");

    for (i = 0; i < numberOfAddresses; i++)
    {
        scanf("%d", &address);

        relocatedAddress = address + relocationFactor;

        printf("Original Address = %d", address);
        printf(" --> Relocated Address = %d\n", relocatedAddress);
    }

    return 0;
}
