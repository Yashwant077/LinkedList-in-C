#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void createList(struct Node* head)
{
    int size;
    printf("Enter the size of list:");
    scanf("%d",&size);
    struct Node* ptr;
    ptr = (struct Node*)malloc(size*sizeof(struct Node));
    printf("Enter the elements for the list::");
    for(int i=0;i<size;i++)
    {
        ptr = ptr+i;
        scanf("%d",&(ptr->data));
        ptr->next = ptr+(i+1);
    }
    ptr->next = head;
    ptr = ptr->next;
    head = ptr;
    printf("List Created Successfully.\n");
    printf("Elements in the circular Linked List are:: \n");
    do
    {
        printf(" %d ",ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
    printf("\n");
}

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
   
}

void insert_at_end(struct Node* head)
{
    
}

void delete_at_start(struct Node** head)
{
   
}

void delete_after(struct Node* head)
{
   
}

void delete_at_end(struct Node* head)
{
    
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

void printList(struct Node* head)
{
    struct Node* ptr;
    ptr = head;
    if(head == NULL)
    {
        printf("List is Empty!!!");
        return;
    }
    printf("Elements in the Linked List are:: \n");
    do
    {
        printf(" %d ",ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
    printf("\n");
}

int main()
{
    struct Node* head = NULL;
    int ch;
    do
    {
        printf("\nEnter your choice:"
                "\n1. Create List"
                "\n2. Insert at start"
                "\n3. Insert after"
                "\n4. Insert at end"
                "\n5. Delete at start"
                "\n6. Delete after"
                "\n7. Delete at end"
                "\n8. Search an element"
                "\n9. Print List"
                "\n0. Quit\n");
        scanf("%d", &ch);
        
        switch(ch)
        {
            case 1:
                createList(head);
                break;
            case 2:
                insert_at_start(&head);
                break;
            case 3:
                insert_after(head);
                break;
            case 4:
                insert_at_end(head);
                break;
            case 5:
                delete_at_start(&head);
                break;
            case 6:
                delete_after(head);
                break;
            case 7:
                delete_at_end(head);
                break;
            case 8:
                search_element(head);
                break;
            case 9:
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
