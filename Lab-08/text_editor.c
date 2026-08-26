#include <stdio.h>
#include <string.h>

int main() {
    char text[1000] = "";
    char input[500];
    int choice, position;

    while (1) {
        printf("\n--- Simple Text Editor ---\n");
        printf("1. Insert Character\n");
        printf("2. Delete Character\n");
        printf("3. Insert Word\n");
        printf("4. Delete Word\n");
        printf("5. Insert Sentence\n");
        printf("6. Delete Sentence\n");
        printf("7. Display Text\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            printf("Enter character: ");
            fgets(input, sizeof(input), stdin);

            printf("Enter position: ");
            scanf("%d", &position);
            getchar();

            if (position >= 0 && position <= strlen(text)) {
                memmove(&text[position + 1], &text[position],
                        strlen(text) - position + 1);
                text[position] = input[0];
            }
        }

        else if (choice == 2) {
            printf("Enter position to delete: ");
            scanf("%d", &position);
            getchar();

            if (position >= 0 && position < strlen(text)) {
                memmove(&text[position], &text[position + 1],
                        strlen(text) - position);
            }
        }

        else if (choice == 3) {
            printf("Enter word: ");
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0';

            printf("Enter position: ");
            scanf("%d", &position);
            getchar();

            if (position >= 0 && position <= strlen(text)) {
                memmove(&text[position + strlen(input)],
                         &text[position],
                         strlen(text) - position + 1);
                memcpy(&text[position], input, strlen(input));
            }
        }

        else if (choice == 4) {
            printf("Enter word to delete: ");
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0';

            char *found = strstr(text, input);

            if (found != NULL) {
                memmove(found, found + strlen(input),
                        strlen(found + strlen(input)) + 1);
            }
        }

        else if (choice == 5) {
            printf("Enter sentence: ");
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0';

            strcat(text, input);
        }

        else if (choice == 6) {
            printf("Enter sentence to delete: ");
            fgets(input, sizeof(input), stdin);
            input[strcspn(input, "\n")] = '\0';

            char *found = strstr(text, input);

            if (found != NULL) {
                memmove(found, found + strlen(input),
                        strlen(found + strlen(input)) + 1);
            }
        }

        else if (choice == 7) {
            printf("\nCurrent Text: %s\n", text);
        }

        else if (choice == 8) {
            printf("Exiting...\n");
            break;
        }

        else {
            printf("Invalid choice!\n");
        }
    }

    return 0;
}