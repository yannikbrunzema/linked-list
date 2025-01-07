
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node
{
    void* data;
    struct Node* next;
} Node;

// Creates a node, and allocates it on the heap
Node* CreateNode(void *data);

// Insert a node at the beginning of the list
void InsertNodeAtBeginning(Node **head, void* data);

// Insert a node at the end of the list
void InsertNodeAtEnd(Node **head, void* data);

// Insert a node at a specified index of the list
void InsertNodeAtIndex(Node **head, void* data, const int index);

// Deletes a specified node from the list
void DeleteNode(Node **head, Node* node);

// Prints the linked list
void PrintList(const Node* head, void (*print)(void*, bool));

// Destroys the list
void DestroyList(Node **head);

#endif //LINKED_LIST_H
