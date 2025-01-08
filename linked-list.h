
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node
{
    void* data;
    struct Node* next;
} Node;

typedef struct LinkedList
{
    Node* head;
    Node* tail;
} LinkedList;

// Creates a new linked list
LinkedList* CreateLinkedList();

// Destroys the linked list
void DestroyLinkedList(LinkedList* list);

// Inserts a node at the beginning of the list
void InsertNodeAtBeginning(LinkedList* list, void* data);

// Inserts a node at the end of the list
void InsertNodeAtEnd(LinkedList* list, void* data);

// Inserts a node at a specified index in the list
void InsertNodeAfterIndex(LinkedList *list, void* data, int index);

// Deletes a node at a specified index in the list
void DeleteNodeAtPosition(LinkedList *list, int index);

// Prints the linked list
void PrintList(const LinkedList* list, void (*print)(void*, bool));

// Reverses the linked list
void Reverse(LinkedList* list);

#endif //LINKED_LIST_H
