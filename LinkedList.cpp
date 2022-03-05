#include <iostream>

using namespace std;

struct node
{
    int info;
    struct node *next;
    struct node *prev;
};

void printList(node *n)
{
    while (n != NULL)
    {
        cout << n->info << " ";
        n = n->next;
    }
    cout << endl;
}

void createList(node **head)
{
    node *first = new node();
    node *mid = new node();
    node *last = new node();

    first->info = 30;
    first->prev = NULL;
    first->next = mid;
    mid->info = 40;
    mid->next = last;
    mid->prev = first;
    last->info = 50;
    last->next = NULL;
    last->prev = mid;

    (*head) = first;
    printList(first);
}

void insertFirst(node **head, int temp)
{
    node *newNode = new node();
    newNode->info = temp;
    newNode->next = (*head);
    newNode->prev = NULL;
    (*head) = newNode;
}

void insertAfter(node **head, node *prevNode, int temp)
{
    node *first = *head;
    if (prevNode == NULL)
    {
        insertFirst(&first, temp);
        return;
    }
    node *newNode = new node();
    newNode->info = temp;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    newNode->prev = prevNode;
}

void insertLast(node **head, int temp)
{
    node *newNode = new node();
    node *last = *head;
    newNode->info = temp;
    newNode->next = NULL;
    while (last->next != NULL)
        last = last->next;
    last->next = newNode;
    newNode->prev = last;
}

void insertBefore(node **head, node *nextNode, int temp)
{
    node *current = *head;
    while (current->info != nextNode->info)
        current = current->next;
    node *newNode = new node();
    newNode->info = temp;
    newNode->next = nextNode;
    newNode->prev = nextNode->prev;
    nextNode->prev->next = newNode;
    nextNode->prev = newNode;
}

void deleteFirst(node **head)
{
    node *temp = *head;
    (*head) = temp->next;
    temp->next = NULL;
    (*head)->prev = NULL;
}

void deleteLast(node **head)
{
    node *temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->prev->next = NULL;
    temp->prev = NULL;
}

void deleteAfter(node *prevNode)
{
    node *temp = prevNode->next;
    prevNode->next = prevNode->next->next;
    prevNode->next->prev = prevNode;
    temp->next = NULL;
    temp->prev = NULL;
}

void deleteBefore(node *nextNode)
{
    node *temp = nextNode->prev;
    nextNode->prev = nextNode->prev->prev;
    nextNode->prev->next = nextNode;
    temp->next = NULL;
    temp->prev = NULL;
}

void searchNode(node **head, int id)
{
    int currentID = 1;
    node *temp = *head;
    while (temp->next != 0 && currentID != id)
    {
        temp = temp->next;
        currentID++;
    }
    cout << temp->info << " is Found at " << currentID;
}

int main()
{
    node *head = NULL;
    createList(&head);
    cout << "Insertion : ";
    insertFirst(&head, 20);
    insertAfter(&head, head->next->next, 45);
    insertBefore(&head, head->next->next, 35);
    insertLast(&head, 60);
    printList(head);
    cout << "Deletion  : ";
    deleteFirst(&head);
    deleteLast(&head);
    deleteAfter(head->next);
    printList(head);
    searchNode(&head, 3);
}