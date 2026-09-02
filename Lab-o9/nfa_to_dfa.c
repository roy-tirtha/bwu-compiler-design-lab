#include <stdio.h>
#include <string.h>

#define MAX_STATES 10
#define MAX_SYMBOLS 5
#define MAX_DFA_STATES 100

int nfa[MAX_STATES][MAX_SYMBOLS][MAX_STATES];
int dfa[MAX_DFA_STATES][MAX_SYMBOLS];

int nfa_states, symbols;
char alphabet[MAX_SYMBOLS];

int dfa_states[MAX_DFA_STATES][MAX_STATES];
int dfa_count = 0;

/* Check whether two sets are equal */
int sameSet(int a[], int b[])
{
    for (int i = 0; i < nfa_states; i++)
    {
        if (a[i] != b[i])
            return 0;
    }
    return 1;
}

/* Find a DFA state containing the given NFA-state set */
int findState(int set[])
{
    for (int i = 0; i < dfa_count; i++)
    {
        if (sameSet(dfa_states[i], set))
            return i;
    }

    return -1;
}

/* Print a DFA state */
void printSet(int set[])
{
    printf("{");

    int first = 1;

    for (int i = 0; i < nfa_states; i++)
    {
        if (set[i])
        {
            if (!first)
                printf(",");

            printf("q%d", i);
            first = 0;
        }
    }

    printf("}");
}

int main()
{
    int transitions;

    printf("Enter number of NFA states: ");
    scanf("%d", &nfa_states);

    printf("Enter number of input symbols: ");
    scanf("%d", &symbols);

    printf("Enter input symbols:\n");

    for (int i = 0; i < symbols; i++)
        scanf(" %c", &alphabet[i]);

    printf("\nEnter number of NFA transitions: ");
    scanf("%d", &transitions);

    printf("\nEnter transitions in the format:\n");
    printf("from_state input_symbol to_state\n");
    printf("Example: 0 a 1\n\n");

    for (int i = 0; i < transitions; i++)
    {
        int from, to;
        char symbol;

        scanf("%d %c %d", &from, &symbol, &to);

        int symbolIndex = -1;

        for (int j = 0; j < symbols; j++)
        {
            if (alphabet[j] == symbol)
            {
                symbolIndex = j;
                break;
            }
        }

        if (symbolIndex != -1)
            nfa[from][symbolIndex][to] = 1;
    }

    /* Initial DFA state = {q0} */
    int startSet[MAX_STATES] = {0};
    startSet[0] = 1;

    memcpy(dfa_states[dfa_count], startSet, sizeof(startSet));
    dfa_count++;

    /* Subset construction */
    for (int current = 0; current < dfa_count; current++)
    {
        for (int symbol = 0; symbol < symbols; symbol++)
        {
            int newSet[MAX_STATES] = {0};

            /* Find all NFA states reachable from current DFA state */
            for (int state = 0; state < nfa_states; state++)
            {
                if (dfa_states[current][state])
                {
                    for (int next = 0; next < nfa_states; next++)
                    {
                        if (nfa[state][symbol][next])
                            newSet[next] = 1;
                    }
                }
            }

            /* Check whether this set already exists */
            int nextDFA = findState(newSet);

            if (nextDFA == -1)
            {
                memcpy(dfa_states[dfa_count], newSet,
                       sizeof(newSet));

                nextDFA = dfa_count;
                dfa_count++;
            }

            dfa[current][symbol] = nextDFA;
        }
    }

    /* Display DFA transition table */
    printf("\n\n========== DFA TRANSITION TABLE ==========\n\n");

    printf("%-15s", "DFA State");

    for (int i = 0; i < symbols; i++)
        printf("%-15c", alphabet[i]);

    printf("\n");

    printf("---------------------------------------------\n");

    for (int i = 0; i < dfa_count; i++)
    {
        printf("D%d = ", i);
        printSet(dfa_states[i]);

        int length = 15 - 4;

        for (int j = 0; j < length; j++)
            printf(" ");

        for (int j = 0; j < symbols; j++)
        {
            printf("D%d", dfa[i][j]);

            int spaces = 15 - 2;

            for (int k = 0; k < spaces; k++)
                printf(" ");
        }

        printf("\n");
    }

    printf("\nTotal DFA states = %d\n", dfa_count);

    return 0;
}


