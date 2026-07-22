//Q.1) Implement a symbol table with functions to create, insert, modify, search,
and display.
Code:-
#include <stdio.h>
#include <string.h>
#define MAX 50
struct Symbol {
char name[20]; char type[20]; int value; };
struct Symbol table[MAX];
int count = 0;
// Create Symbol Table
void create() {
count = 0;
printf("Symbol Table Created Successfully!\n"); }
// Insert Symbol
void insert() {
printf("Enter Symbol Name: ");
scanf("%s", table[count].name);
printf("Enter Data Type: ");
scanf("%s", table[count].type);
printf("Enter Value: ");
scanf("%d", &table[count].value);
count++;
printf("Symbol Inserted Successfully!\n"); }
// Search Symbol
void search()
{ char key[20];
int i, found = 0;
printf("Enter Symbol Name to Search: ");
scanf("%s", key);
for(i = 0; i < count; i++) {
if(strcmp(table[i].name, key) == 0)
{
printf("\nSymbol Found!\n");
printf("Name : %s\n", table[i].name);
printf("Type : %s\n", table[i].type);
printf("Value: %d\n", table[i].value);
found = 1;
break; } }
if(!found)
printf("Symbol Not Found!\n"); }
// Modify Symbol
void modify() {
char key[20];
int i, found = 0;
printf("Enter Symbol Name to Modify: ");
scanf("%s", key);
for(i = 0; i < count; i++) {
if(strcmp(table[i].name, key) == 0) {
printf("Enter New Type: ");
scanf("%s", table[i].type);
printf("Enter New Value: ");
scanf("%d", &table[i].value);
printf("Symbol Modified Successfully!\n");
found = 1;
break;
} }
if(!found)
printf("Symbol Not Found!\n"); }
// Display Symbol Table
void display(){
int i;
printf("\n----------------------------------\n");
printf("Name\tType\tValue\n");
printf("----------------------------------\n");
for(i = 0; i < count; i++) {
printf("%s\t%s\t%d\n",
table[i].name,
table[i].type,
table[i].value); } }
int main() {
int choice;
create();
do {
printf("\n===== SYMBOL TABLE MENU =====\n");
printf("1. Insert\n");
printf("2. Search\n");
printf("3. Modify\n");
printf("4. Display\n");
printf("5. Exit\n");
printf("Enter Choice: ");
scanf("%d", &choice);
switch(choice) {
case 1: insert(); break;
case 2: search(); break;
case 3: modify(); break;
case 4: display(); break;
case 5: printf("Exiting...\n"); break;
default: printf("Invalid Choice!\n"); }
} while(choice != 5);
return 0; }