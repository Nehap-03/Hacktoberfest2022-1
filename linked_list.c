//LINKEDLIST- all operations
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct node
{
    int data;
    struct node* next;
};


//create a node
struct node* create()
{
    struct node * t;
    t=(struct node *)malloc(sizeof(struct node));
    printf("Enter Element");
    scanf("%d",&t->data);
    t->next=NULL;
    return t;
}

void print(struct node * ptr);
void makelist(struct node** myhead);
void insert_beg(struct node** myhead);
void insert_end();
void insert_atpoint();
void delend();
void delbeg(struct node** myhead);
void del_afternode(struct node** myhead);

int main()
{
    int n,i,x;
    struct node * head=NULL;
    printf("Enter number of elements");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        makelist(&head);
    }
    print(head);
    printf("1.Insert at beginning\t 2.Insert at end\n 3.Insert at middle\t 4.Delete at beginning\n5.Delete at end\t 6.Delete at middle\n");
    printf("Enter which operation to perform: \n");
    scanf("%d",&x);
    switch(x)
    {
        case 1:
            insert_beg(&head);
            break;
        case 2:
            insert_end();
            break;
        case 3:
            insert_atpoint();
            break;
        case 4:
            delbeg(&head);
            break;
        case 5:
            delend();
            break;
        case 6:
            del_afternode(&head);
            break;
        default:
            printf("No operation to perform");
            break;
    }
    print(head);
}

void makelist(struct node** myhead)
{
    struct node * temp;
    struct node * new;
    new=create();
    if(*myhead==NULL)
    {
        *myhead=new;
    }
    else
    {
        temp=*myhead;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=new;
    }

}

//insert at beginning
void insert_beg(struct node** myhead)
{
    struct node* add;
    printf ("For insertion at beginning \n");
    add=create();
    add->next=*myhead;
    *myhead=add;

}

//insert at end
void insert_end()
{
    struct node* add;
    struct node* ptr;
    printf ("For insertion at end \n");
    add=create();
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=add;
}

//insert after a given address
void insert_atpoint()
{
    int n;
    struct node* add;
    struct node* ptr;
    printf("For insertion after a node, enter after which new node is to be added: ");
    scanf("%d",&n);
    add=create();
    while(ptr->data!=n)
    {
        ptr=ptr->next;
        if(ptr->next==NULL)
            printf("Node not found");
    }
    add->next=ptr->next;
    ptr->next=add;
}


//deletion from end
void delend()
{
    struct node * ptr;
    struct node * prev;
    printf("Deleting an element from end : ");
    while (ptr->next!=NULL)
    {
        prev=ptr;
        ptr=ptr->next;
    }
    prev->next=NULL;
    free(ptr);
    
    
}

//deletion from beginning
void delbeg(struct node** myhead)
{
    struct node* ptr;
    struct node* tmp;
    printf("Deleting an element from beginning\n ");
    tmp=*myhead;
    *myhead=tmp->next;
    free(tmp);
}

//deletion after a node
void del_afternode(struct node** myhead)
{
    int n;
    struct node* ptr=*myhead,*prev;
    printf("For deletion in between, Enter which node has to be deleted: ");
    scanf("%d",&n);
    while(ptr->data!=n)
    {
        prev=ptr;
        ptr=ptr->next;
        if(ptr->next==NULL)
            printf("Node not found ");
    }
    prev->next=ptr->next;
    ptr->next=NULL;
    free(ptr);


}


//traverse and print the list
void print(struct node * ptr)
{
    if(ptr==NULL)
        printf("No element in the list \n");
    printf("[");
    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
     printf("]\n");
}
