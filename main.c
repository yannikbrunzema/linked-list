#include <stdio.h>
#include <stdbool.h>
#include "linked-list.h"

// Delegate function to be passed as a pointer
void PrintInt(void* data, const bool isLast)
{
    printf("%d", *(int*)data); // Print the integer
    if (!isLast)
    {
        printf(" -> "); // Print the separator if not the last element
    }
}

int main(void)
{
    Node* head = NULL;
    int data = 10;
    int data2 = 20;
    int data3 = 30;
    int data4 = 40;

    InsertNodeAtBeginning(&head, &data2);
    InsertNodeAtBeginning(&head, &data);
    InsertNodeAtBeginning(&head, &data2);
    InsertNodeAtEnd(&head, &data3);
    InsertNodeAtIndex(&head, &data4, 0);

    void (*print)(void*, bool) = PrintInt;
    PrintList(head, print);
    fflush(stdout);
    DestroyList(&head);
    return 0;
}