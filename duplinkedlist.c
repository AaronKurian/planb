#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

// Function to insert a node at the end of the linked list
struct Node *insert(struct Node *head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (!head)
        return newNode;

    struct Node *temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;

    return head;
}

// Function to display the linked list
void display(struct Node *head)
{
    struct Node *temp = head;
    while (temp)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to print odd numbers in the linked list
void printOddNumbers(struct Node *head)
{
    struct Node *temp = head;
    printf("Odd numbers: ");
    while (temp)
    {
        if (temp->data % 2 != 0)
            printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to print even numbers in the linked list
void printEvenNumbers(struct Node *head)
{
    struct Node *temp = head;
    printf("Even numbers: ");
    while (temp)
    {
        if (temp->data % 2 == 0)
            printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to print duplicate numbers in the linked list
void printDuplicates(struct Node *head)
{
    struct Node *temp1 = head;
    int found = 0;

    printf("Duplicate numbers: ");
    while (temp1 && temp1->next)
    {
        struct Node *temp2 = temp1->next;
        while (temp2)
        {
            if (temp1->data == temp2->data)
            {
                printf("%d ", temp1->data);
                found = 1;
                break;
            }
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }
    if (!found)
        printf("None");
    printf("\n");
}

// Function to remove duplicate elements from the linked list
struct Node *removeDuplicates(struct Node *head)
{
    struct Node *current = head;
    while (current && current->next)
    {
        struct Node *runner = current;
        while (runner->next)
        {
            if (current->data == runner->next->data)
            {
                struct Node *duplicate = runner->next;
                runner->next = runner->next->next;
                free(duplicate);
            }
            else
            {
                runner = runner->next;
            }
        }
        current = current->next;
    }
    return head;
}

int main()
{
    struct Node *head = NULL;
    int choice, value;

    do
    {
        printf("\nMenu:\n");
        printf("1. Insert a new element\n");
        printf("2. Display the linked list\n");
        printf("3. Print odd numbers\n");
        printf("4. Print even numbers\n");
        printf("5. Print duplicate numbers\n");
        printf("6. Remove duplicates\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            head = insert(head, value);
            break;

        case 2:
            printf("Linked List: ");
            display(head);
            break;

        case 3:
            printOddNumbers(head);
            break;

        case 4:
            printEvenNumbers(head);
            break;

        case 5:
            printDuplicates(head);
            break;

        case 6:
            head = removeDuplicates(head);
            printf("Duplicates removed.\n");
            break;

        case 7:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice! Please enter a valid option.\n");
            break;
        }
    } while (choice != 7);

    return 0;
}
