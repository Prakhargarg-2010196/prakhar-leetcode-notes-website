# Implementation

## Pre-requisites

- Do I need a Book to Learn C++?
- What is a Linked List and What is it used for ?
- Structured way of writing C++?

## Answers to the pre-requisites

Answer 1: Yes and no I do need it as a reference but for learning the concept only complete reading of a big book without any implementation would be a waste of time.But I will surely download a book to learn major concepts.

Answer 2: This I learnt from these resources.

- [Google C++ Style Guide for writing better code](https://google.github.io/styleguide/cppguide.html)
- [CS50:Data Structures](https://youtu.be/X8h4dq9Hzq8?list=PLhQjrBD2T380F_inVRXMIHCqLaNUd7bN4&t=2304)
- C++ Tamascia Implementation : read in free time #todo

Disadvantages of arrays

1. As we moved forward with arrays we saw problems in re-sizing of array like for each insertion we needed to copy the entire array into new array or use `realloc` to  
2. They use contigous memory.

## Advantages of Linked List over arrays

1. Can allocate space anywhere in memory
2. Can allocate any amount of memory unless it crosses the main memory bound

## Disadvantage of Linked list over arrays

1. Its easier to search in array over linked list as the middle element can be found easily and hence binary search can be applied.
2. No random access through indexes as they don't exist.

## Pre Requistes

1. Use of malloc and realloc: malloc is used to allocate memory space in heap while realloc is also used to allocate but to a already allocated memory  

2. Know what are pointers:
    a. How are pointers created : using `*` operator like this `data_type* variable_name;`
    b. How are pointers access/dereference : using `*` operator like this `*variable_name;`
    c. How to access data in struct pointer data allocated by `malloc` directly : using `->` on the pointer name like this if

    ```c
    node * n=malloc(sizeof(node));
    n->data ; // is a way to access data variable inside node
     ```

3. How are collection of data types made like an object with various different kind of data ?
    a. As we can see we can use `struct` keyword for creating group of data like for example if we want to create a person with a name and his id

    ```c typedef struct{
            int id;
            string name;
    }person;
    // this can be further modified with our pointer knowledge to be like this as we know strings are nothing but char array
    ```c typedef struct{
            int id;
            char* name[];
    }person;
    ```

    b. Now for a linked list the implementation of a node can be written using struct as follows

    ```c typedef struct node{
            int data;
            node* next;
    }node;
    ```

4. [Know how to input using cmd line in c](https://www.geeksforgeeks.org/command-line-arguments-in-c-cpp/)

```c
int main(int argc, char *argv[]) { /* ... */ }
            or
int main(int argc, char **argv) { /* ... */ }
```

## Code 
```cpp
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
```