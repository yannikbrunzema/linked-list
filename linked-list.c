#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked-list.h"

static Node* CreateNode(void *data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void PrintList(const LinkedList* list, void (*print)(void*, bool))
{
    Node* head = list->head;
    while (head != NULL)
    {
        if (head->next == NULL)
            print(head->data, true);
        else
            print(head->data, false);
        head = head->next;
    }
}

LinkedList* CreateLinkedList()
{
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

void InsertNodeAtBeginning(LinkedList *list, void* data)
{
    Node* newNode = CreateNode(data);

    if (list->head == NULL)
    {
        list->head = newNode;
        list->tail = newNode;
        return;
    }

    newNode->next = list->head;
    list->head = newNode;
}

void InsertNodeAtEnd(LinkedList *list, void* data)
{
    Node* node = CreateNode(data);

    if (list->tail == NULL)
    {
        list->head = node;
        list->tail = node;
        return;
    }

    list->tail->next = node;
    list->tail = node;
}

void InsertNodeAfterIndex(LinkedList *list, void* data, int index)
{
    if (!list)
        return;

    if (index == 0)
    {
        InsertNodeAtBeginning(list, data);
        return;
    }

    int currentIndex = 0;
    Node* nodeToInsert = CreateNode(data);
    Node* currNode = list->head;

    while (currNode && currentIndex < index)
    {
        currNode = currNode->next;
        currentIndex++;
    }

    // If the supplied index is bad
    if (currNode == NULL)
    {
        free(nodeToInsert);
        return;
    }

    Node* nextNode = currNode->next;
    currNode->next = nodeToInsert;
    nodeToInsert->next = nextNode;
}

void DeleteNodeAtPosition(LinkedList *list, int index)
{
    if (!list)
        return;
    if (index == 0)
    {
        Node* secondNode = list->head->next;
        free(list->head);
        list->head = secondNode;
        return;
    }

    int currentIndex = 0;
    Node* currNode = list->head;

    // Goto the node before the one we want to delete
    while (currNode && currentIndex < index-1)
    {
        currNode = currNode->next;
        currentIndex++;
    }

    if (currNode == NULL)
        return;

    Node* nextAfterDeleted = currNode->next->next;
    free(currNode->next);
    currNode->next = nextAfterDeleted;
}

void DestroyLinkedList(LinkedList *list)
{
    if (!list)
        return;

    Node* node = list->head;
    while (node != NULL)
    {
        Node *temp = (node)->next;
        free(node);
        node = temp;
    }

    list->head = NULL;
    list->tail = NULL;

    free(list);
}

void ReverseLinkedList(LinkedList *list)
{
    if (!list)
        return;

    Node* current = list->head;
    Node* previous = NULL;

    while (current != NULL)
    {
        
    }
}

