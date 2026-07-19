#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *next;
};

// Top pointer
struct Node *top = NULL;

// Push operation
void push(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("Stack Overflow!\n");
        return;
    }

    newNode->data = value;
    newNode->next = top;
    top = newNode;

    printf("%d pushed into stack.\n", value);
}

// Pop operation
void pop()
{
    struct Node *temp;

    if (top == NULL)
    {
        printf("Stack Underflow!\n");
        return;
    }

    temp = top;
    printf("Popped element: %d\n", top->data);

    top = top->next;
    free(temp);
}

// Peek operation
void peek()
{
    if (top == NULL)
    {
        printf("Stack is Empty.\n");
    }
    else
    {
        printf("Top element: %d\n", top->data);
    }
}

// Display operation
void display()
{
    struct Node *temp;

    if (top == NULL)
    {
        printf("Stack is Empty.\n");
        return;
    }

    printf("Stack elements are:\n");

    temp = top;

    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}

// Main function
int main()
{
    int choice, value;

    while (1)
    {
        printf("\n===== STACK USING LINKED LIST =====\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push: ");
            scanf("%d", &value);
            push(value);
            break;

        case 2:
            pop();
            break;

        case 3:
            peek();
            break;

        case 4:
            display();
            break;

        case 5:
            printf("Program terminated.\n");
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}