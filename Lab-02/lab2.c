//. Implement a two pass macro processor.
/*Input.txt
MACRO
INCR &ARG
LDA &ARG
ADD =1
STA &ARG
MEND
START
INCR NUM
HLT
NUM DC 5
END
Source code:-
*/


#include <stdio.h>
#include <string.h>
struct Macro {
char name[20];
char body[20][100];
int lines;
};
int main() {
FILE *fp;
char line[100], word1[20], word2[20];
struct Macro m;
m.lines = 0;
/* PASS 1 : Store Macro Definition */

fp = fopen("input.txt", "r");
while (fgets(line, sizeof(line), fp)) {
sscanf(line, "%s %s", word1, word2);
if (strcmp(word1, "MACRO") == 0) {
fgets(line, sizeof(line), fp);
sscanf(line, "%s %s", m.name, word2);
while (fgets(line, sizeof(line), fp)) {
if (strncmp(line, "MEND", 4) == 0)
break;
strcpy(m.body[m.lines], line);
m.lines++;
}
}
}
fclose(fp);
/* PASS 2 : Expand Macro */
fp = fopen("input.txt", "r");
printf("Expanded Program:\n\n");
while (fgets(line, sizeof(line), fp)) {
sscanf(line, "%s %s", word1, word2);
if (strcmp(word1, "MACRO") == 0) {
while (fgets(line, sizeof(line), fp)) {
if (strncmp(line, "MEND", 4) == 0)
break;
}
}
else if (strcmp(word1, m.name) == 0) {
for (int i = 0; i < m.lines; i++)
printf("%s", m.body[i]);
}
else {
printf("%s", line);
}
}
fclose(fp);
return 0;
}