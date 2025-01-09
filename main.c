#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "linked-list.h"

// Delegate function to be passed as a pointer
void PrintInt(void* data, const bool isLast)
{
    printf("%d", *(int*)data); // Print the integer
    if (!isLast)
    {
        printf(" -> "); // Print the separator if not the last element
    }
    else
        printf("\n");
}

int main(void)
{
    // Allocate data on the heap
    int* data1 = malloc(sizeof(int));
    int* data2 = malloc(sizeof(int));
    int* data3 = malloc(sizeof(int));
    int* test = malloc(sizeof(int));

    *data1 = 10;
    *data2 = 20;
    *data3 = 30;
    *test = 69;

    // Function pointer for printing
    void (*print)(void*, bool) = PrintInt;

    LinkedList* list = CreateLinkedList();
    InsertNodeAtBeginning(list, data1);
    InsertNodeAtBeginning(list, data2);
    InsertNodeAtEnd(list, data3);
    InsertNodeAtEnd(list, data3);
    InsertNodeAtEnd(list, data3);

    printf("Initial List:\n");
    PrintList(list, print);

    InsertNodeAfterIndex(list, test, 2);

    printf("\nList after insertion:\n");
    PrintList(list, print);

    DeleteNodeAtPosition(list, 3);

    printf("\nList after deletion:\n");
    PrintList(list, print);

    ReverseLinkedList(list);

    printf("\nReversed List:\n");
    PrintList(list, print);

    // Destroy the list and free memory
    DestroyLinkedList(list);
    free(data1);
    free(data2);
    free(data3);
    free(test);

    return 0;
}