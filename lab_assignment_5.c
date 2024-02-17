#include <stdio.h>
#include <stdlib.h>
typedef struct node {
char letter;
struct node* next;
} node;
// Returns number of nodes in the linkedList.
int length(node* head)
{
if (head == NULL) {
    return 0;
}

node* current = head;
int counter = 0;

while (current != NULL) {
    counter++;
    current = current->next;
}

return counter;
}
// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function wil return "abc"
char* toCString(node* head) {
node* current = head;
int node_len = length(head);
int i = 0;
char* cString = (char*)malloc((node_len + 1) * sizeof(char)); 

if (cString == NULL) {
    return NULL;
}   

while (current != NULL && i < node_len) {
    cString[i] = current->letter;
    current = current->next;
    i++;
}

cString[i] = '\0'; 

return cString;
}
// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** pHead, char c) {
node* new_node = malloc(sizeof(struct node));

if (new_node == NULL) {
    return;
}

new_node->letter = c;
new_node->next = NULL;

if (*pHead == NULL) {
    *pHead = new_node;
    return;
}

node* current = *pHead;
while (current->next != NULL) {
    current = current->next;
}
current->next = new_node;
}
// deletes all nodes in the linkedList.
void deleteList(node** pHead)
{
node* current = *pHead;
node* temp;

while (current != NULL) {
    temp = current->next;
    free(current);
    current = temp;
}

*pHead = NULL;
}
int main(void)
{
int i, strLen, numInputs;
node* head = NULL;
char* str;
char c;
FILE* inFile = fopen("input.txt","r");
fscanf(inFile, " %d\n", &numInputs);
while (numInputs-- > 0)
{
fscanf(inFile, " %d\n", &strLen);
for (i = 0; i < strLen; i++)
{
fscanf(inFile," %c", &c);
insertChar(&head, c);
}
str = toCString(head);
printf("String is : %s\n", str);
free(str);
deleteList(&head);
if (head != NULL)
{
printf("deleteList is not correct!");
break;
}
}
fclose(inFile);
}