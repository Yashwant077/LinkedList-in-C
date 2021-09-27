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

void traversal(struct Node* ptr)
{
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
                "\n4. Traverse"
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
                traversal(head);
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
