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
    int data = 10;
    int data2 = 20;
    int data3 = 30;

    int test = 69;
    void (*print)(void*, bool) = PrintInt;

    LinkedList* list = CreateLinkedList();
    InsertNodeAtBeginning(list, &data);
    InsertNodeAtBeginning(list, &data2);
    InsertNodeAtEnd(list, &data3);
    InsertNodeAtEnd(list, &data3);
    InsertNodeAtEnd(list, &data3);
    PrintList(list, print);
    printf("\n");
    InsertNodeAfterIndex(list,&test,2);
    DeleteNodeAtPosition(list, 3);
    PrintList(list, print);





    fflush(stdout);
    DestroyLinkedList(list);
    return 0;
}