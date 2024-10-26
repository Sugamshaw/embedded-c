#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void insertAtBeginning(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

void insertAtEnd(struct Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    struct Node *last = *head_ref;
    new_node->data = new_data;
    new_node->next = NULL;
    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
}

void insertAfter(struct Node *prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        printf("Previous node cannot be NULL.\n");
        return;
    }
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void insertNode(struct Node **head_ref, int new_data, int position)
{
    switch (position)
    {
    case 1:
        insertAtBeginning(head_ref, new_data);
        break;
    case 2:
        insertAtEnd(head_ref, new_data);
        break;
    default:
    {
        struct Node *current = *head_ref;
        while (current != NULL && current->data != position)
        {
            current = current->next;
        }
        if (current != NULL)
        {
            insertAfter(current, new_data);
        }
        else
        {
            printf("Position not found in the list.\n");
        }
    }
    }
}
void deleteNode(struct Node **head_ref, int key)
{
    struct Node *temp = *head_ref;
    struct Node *prev = NULL;

    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;
    prev->next = temp->next;

    free(temp);
}
struct Node *searchNode(struct Node *head, int key)
{
    struct Node *current = head;
    while (current != NULL)
    {
        if (current->data == key)
        {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void reverseList(struct Node **head_ref)
{
    struct Node *prev = NULL;
    struct Node *current = *head_ref;
    struct Node *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
int main()
{
    struct Node *head = NULL;

    insertNode(&head, 10, 1);
    insertNode(&head, 20, 2);
    insertNode(&head, 30, 2);
    insertNode(&head, 15, 20);
    printf("Linked List: ");
    printList(head);
    // reverseList(&head);
    // printf("Linked List after reverse : ");
    // printList(head);
    int length = 0;
    struct Node *current = head;
    while (current != NULL)
    {
        length++;
        current = current->next;
    }
    printf("Length: %d\n", length);
    // while (head != NULL)
    // {
    //     deleteNode(&head, head->data);
    // }

    // printf("Linked List after deletion: ");
    // printList(head);

    // int value = 60;
    // struct Node *found_node = searchNode(head, value);
    // if (found_node != NULL)
    // {
    //     printf("Node with data %d found.\n", value);
    // }
    // else
    // {
    //     printf("Node with data %d not found.\n", value);
    // }

    return 0;
}
