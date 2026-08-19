#include <stdio.h>
#include <string.h>

struct ESTAB
{
    char symbol[20];
    int address;
};

int main()
{
    struct ESTAB table[100];
    int n, i;
    char sym[20];
    int value;
    char op;
    int found = 0;

    printf("Enter number of symbols in ESTAB: ");
    scanf("%d", &n);

    printf("\nEnter ESTAB entries:\n");

    for (i = 0; i < n; i++)
    {
        printf("Enter symbol and address: ");
        scanf("%19s%d", table[i].symbol, &table[i].address);
    }

    printf("\nEnter current address value: ");
    scanf("%d", &value);

    printf("Enter operation (+ or -): ");
    scanf(" %c", &op);

    printf("Enter symbol name: ");
    scanf("%19s", sym);

    for (i = 0; i < n; i++)
    {
        if (strcmp(sym, table[i].symbol) == 0)
        {
            found = 1;

            if (op == '+')
            {
                value = value + table[i].address;
            }
            else if (op == '-')
            {
                value = value - table[i].address;
            }
            else
            {
                printf("\nInvalid operation!\n");
                return 1;
            }

            break;
        }
    }

    if (found)
    {
        printf("\nModified Address = %d\n", value);
    }
    else
    {
        printf("\nSymbol not found in ESTAB.\n");
    }

    return 0;
}

