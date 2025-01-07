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

