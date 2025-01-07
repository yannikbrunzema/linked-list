#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linked-list.h"

Node* CreateNode(void *data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void PrintList(const Node* head, void (*print)(void*, bool))
{
    while (head != NULL)
    {
        if (head->next == NULL)
            print(head->data, true);
        else
            print(head->data, false);
        head = head->next;
    }
}

void InsertNodeAtBeginning(Node **head, void* data)
{
    Node* newHead = CreateNode(data);
    newHead->next = (*head);
    *head = newHead;
}

void InsertNodeAtEnd(Node **head, void* data)
{
    Node* node = CreateNode(data);

    // If the list is empty, make the new node the head
    if (*head == NULL)
    {
        *head = node;
        return;
    }

    Node* temp = *head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = node;
}

void InsertNodeAtIndex(Node **head, void* data, const int index)
{
    Node* node = CreateNode(data);

    if (index == 0)
    {
        node->next = *head;
        *head = node;
        return;
    }

    Node* temp = *head;
    int currentIndex = 0;

    // Find the node at position specified by the index
    while (temp && currentIndex < index)
    {
        currentIndex++;
        temp = temp->next;
    }

    // If an incorrect index is supplied bail here
    if (temp == NULL)
    {
        free(node);
        return;
    }

    node->next = temp->next;
    temp->next = node;
}

void DeleteNodeAtIndex(Node **head, const int index)
{
    if (index == 0)
    {
        Node* old = *head;
        (*head) = (*head)->next;
        free(old);
    }

    Node* temp = *head;
    int currentIndex = 0;

    // This gets us to the node right before the one we want to delete
    while (temp && currentIndex < index-1)
    {
        temp = temp->next;
        currentIndex++;
    }

    if (temp == NULL)
        return;

    Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}

void Reverse(Node **head)
{
    Node* current = *head;
    Node* prev = NULL;
    while (current != NULL)
    {
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

void DestroyList(Node **head)
{
    if (!head)
        return;

    while (*head)
    {
        Node *temp = (*head)->next;
        free(*head);
        *head = temp;
    }
    *head = NULL;
}

