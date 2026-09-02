#include <stdio.h>
#include <string.h>
#include <ctype.h>

/* NFA for Identifier */
int isIdentifier(char *str)
{
    int state = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];

        if (state == 0)
        {
            if (isalpha(ch) || ch == '_')
                state = 1;
            else
                return 0;
        }
        else if (state == 1)
        {
            if (isalnum(ch) || ch == '_')
                state = 1;
            else
                return 0;
        }
    }

    return state == 1;
}


/* NFA for Constants */
int isConstant(char *str)
{
    int state = 0;

    for (int i = 0; str[i] != '\0'; i++)
    {
        char ch = str[i];

        switch (state)
        {
            case 0:
                if (isdigit(ch))
                    state = 1;
                else
                    return 0;
                break;

            case 1:
                if (isdigit(ch))
                    state = 1;
                else if (ch == '.')
                    state = 2;
                else
                    return 0;
                break;

            case 2:
                if (isdigit(ch))
                    state = 3;
                else
                    return 0;
                break;

            case 3:
                if (isdigit(ch))
                    state = 3;
                else
                    return 0;
                break;
        }
    }

    return state == 1 || state == 3;
}


/* NFA for Operators */
int isOperator(char *str)
{
    int state = 0;

    /* Single-character operators */
    if (strlen(str) == 1)
    {
        if (str[0] == '+' ||
            str[0] == '-' ||
            str[0] == '*' ||
            str[0] == '/' ||
            str[0] == '=' ||
            str[0] == '<' ||
            str[0] == '>')
        {
            return 1;
        }
    }

    /* Two-character operators */
    if (strlen(str) == 2)
    {
        if ((str[0] == '=' && str[1] == '=') ||
            (str[0] == '<' && str[1] == '=') ||
            (str[0] == '>' && str[1] == '=') ||
            (str[0] == '!' && str[1] == '='))
        {
            return 1;
        }
    }

    return 0;
}


int main()
{
    char input[100];

    printf("====================================\n");
    printf(" Mini Language NFA Recognizer\n");
    printf("====================================\n");

    printf("\nEnter a token: ");
    scanf("%99s", input);

    if (isIdentifier(input))
    {
        printf("\n%s -> IDENTIFIER\n", input);
    }
    else if (isConstant(input))
    {
        printf("\n%s -> CONSTANT\n", input);
    }
    else if (isOperator(input))
    {
        printf("\n%s -> OPERATOR\n", input);
    }
    else
    {
        printf("\n%s -> INVALID TOKEN\n", input);
    }

    return 0;
}
