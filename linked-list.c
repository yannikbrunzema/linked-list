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
    if (!list)
        return;

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
    if (!list)
        return;

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
    if (!list)
        return;

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

    if (currNode == list->tail)
        list->tail = nodeToInsert;

    nodeToInsert->next = nextNode;
}

void DeleteNodeAtPosition(LinkedList *list, int index)
{
    if (!list || !list->head)
        return;

    if (index == 0)
    {
        Node* secondNode = list->head->next;
        free(list->head);
        list->head = secondNode;

        // If this is the only node, update the tail to null
        if (list->head == NULL)
            list->tail = NULL;

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

    // Make sure the node we want to delete actually exists
    if (currNode == NULL || currNode->next == NULL)
        return;

    Node* toDelete = currNode->next;
    currNode->next = toDelete->next;

    if (toDelete == list->tail)
        list->tail = currNode;

    free(toDelete);
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
    list = NULL;
}

void ReverseLinkedList(LinkedList *list)
{
    if (!list || !list->head)
        return;

    Node* current = list->head;
    Node* previous = NULL;
    Node* nextNode = NULL;

    while (current != NULL)
    {
        nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }
    
    list->tail = list->head;
    list->head = previous;
}

