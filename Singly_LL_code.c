#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void insert_at_start(struct Node** head)
{
    int d;
    printf("Enter the element you want to insert at start::");
    scanf("%d",&d);
    struct Node *new = (struct Node*)malloc(sizeof(struct Node));
    new->data = d;
    new->next = (*head);
    (*head) = new;
}

void insert_after(struct Node* head)
{
    int num,d;
    printf("After which data you want to write::");
    scanf("%d",&num);
    while(head->data != num)
    {
        if(head->data == num)
            break;
        head = head->next;
    }
    if(head->next==NULL && head->data != num)
    {
        printf("Sorry!Your Choosen number is not in the list.\n");
    }
    else
    {
        printf("Enter the element you want to insert::");
        scanf("%d",&d);
        struct Node *new = (struct Node*)malloc(sizeof(struct Node));
        new->data = d;
        new->next = head->next;
        head->next = new;
    }
}

void insert_at_end(struct Node* head)
{
    int d;
    while(head->next != NULL)
    {
        head = head->next;
    }
    printf("Enter the element you want to insert at end::");
    scanf("%d",&d);
    struct Node *new = (struct Node*)malloc(sizeof(struct Node));
    new->data = d;
    new->next = NULL;
    head->next = new;
}

void delete_at_start(struct Node** head)
{
    if(*head == NULL)
    {
        printf("List is already Empty!!!\n");
        return;
    }
    printf("\nStarting Node is deleting...");
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp = (*head);
    (*head) = temp->next;
    free(temp);
    printf("\nStarting Node is deleted Successfully!!!\n");
}

void delete_after(struct Node* head)
{
    if(head->next == NULL)
    {
        printf("List is already Empty!!!\n");
        return;
    }
    int num,d;
    struct Node* prev;
    printf("After which data you want to Delete data::");
    scanf("%d",&num);
    while(head->data != num)
    {
        prev = head;
        head = head->next;
    }
    if(head->next==NULL)
    {
        printf("Sorry!Your Choosen number is not in the list.\n");
        return;
    }
    else
    {
        printf("\nNode is deleting...");
        struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
        temp = head->next;
        head->next = temp->next;
        free(temp);
        printf("\nNode is deleted Successfully!!!\n");
    }
}

void delete_at_end(struct Node* head)
{
    if(head->next == NULL)
    {
        printf("List is already Empty!!!\n");
        return;
    }
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    *temp = *head;
    struct Node *prev;
    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    printf("\nLast Node is deleting...");
    prev->next = temp->next;
    //prev->next = NULL;
    free(temp);
    printf("\nLast Node is deleted Successfully!!!\n");
}

void search_element(struct Node* head)
{
    int ele, index=0;
    printf("Enter the element you want to search::");
    scanf("%d",&ele);
    while(head->next != NULL)
    {
        index+=1;
        if(head->data == ele)
        {
            printf("Element found at position %d.\n",index);
            break;
        }
        head = head->next;
    }
    if(head->next == NULL && head->data != ele)
    {
        printf("Oops! Element not found in the list.\n");
    }
}

void printList(struct Node* ptr)
{
    if(ptr == NULL)
    {
        printf("List is Empty!!!");
        return;
    }
    printf("Elements in the Linked List are:: \n");
    while(ptr != NULL)
    {
        printf(" %d ",ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

int main()
{
    struct Node* head = NULL;
    int ch;
    do
    {
        printf("\nEnter your choice:"
                "\n1. Insert at start"
                "\n2. Insert after"
                "\n3. Insert at end"
                "\n4. Delete at start"
                "\n5. Delete after"
                "\n6. Delete at end"
                "\n7. Search an element"
                "\n8. Print List"
                "\n0. Quit\n");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1:
                insert_at_start(&head);
                break;
            case 2:
                insert_after(head);
                break;
            case 3:
                insert_at_end(head);
                break;
            case 4:
                delete_at_start(&head);
                break;
            case 5:
                delete_after(head);
                break;
            case 6:
                delete_at_end(head);
                break;
            case 7:
                search_element(head);
                break;
            case 8:
                printList(head);
                break;
            case 0:
                exit(1);
                break;
            default:
                printf("Please Enter a valid choice!");
                break;
        }
    }while(ch!=0);
    
    return 0;
}
