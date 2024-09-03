#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
    int data;
    struct node *next;
}node;


node* prependIntoLL(node *, int);
node *createNode(int);
void printList(node *);
int main(char argc, char *argv[])
{
    node *list = NULL;
    // prepends the elements to the list
    for (int i = 1; i <argc; i++){
       list=prependIntoLL(list, atoi(argv[i]));
    }
    printList(list);
    return 0;
}
node *createNode(int val)
{
    node *n = malloc(sizeof(node));
    n->data = val;
    n->next = NULL;
    return n;
}
node* prependIntoLL(node *head, int element)
{
    node *newNode = createNode(element);
    // pre-pending the element to the head
    newNode->next = head;
    head = newNode;
    return head;
}
void printList(node *head)
{
    node *tr = head;
    while (tr != NULL)
    {
        printf("%i",tr->data);
        tr = tr->next;
    }
}