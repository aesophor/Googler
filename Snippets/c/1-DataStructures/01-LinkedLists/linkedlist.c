#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int data;
    struct node* next;
} node_t;

typedef struct list
{
    node_t* first;
    node_t* current;
} list_t;

typedef enum direction
{
    left,
    right
} dirct_t;


// the method to add a node to the list.
void add_node(list_t* self, int d)
{
    node_t* new_node;
    new_node = (node_t*)malloc(sizeof(node_t));

    if(self->first == self->current)
    {
        // make sure to allocate some space
        // for the newly created node.
        new_node->data = d;
        new_node->next = self->first;

        self->first = new_node;
        self->current = self->first;
    }
    else
    {
        node_t* ptr = self->first;
        
        while(ptr != self->current)
        {
            ptr = ptr->next;
        }
        
        new_node->data = d;
        new_node->next = ptr->next;
        ptr->next = new_node;
        self->current = new_node;
    }
}

// the method to delete a node from the list.
void del_node(list_t* self)
{
    node_t* ptr = self->current;

    if(self->first != NULL)
    {
        if(ptr == self->first)
        {
            self->first = self->first->next;
            self->current = self->first;
        }
        else if(ptr->next == NULL)
        {
            ptr = self->first;
            
            while(ptr->next->next != NULL)
            {
                ptr = ptr->next;
            }
            
            self->current = ptr;
            ptr->next = NULL;
        }
        else
        {
            ptr = self->first;
            
            while(ptr->next != self->current)
            {
                ptr = ptr->next;
            }
            
            ptr->next = self->current->next;
            self->current = ptr;
        }
    }
}

void update_node(list_t* self, int d)
{
    if(self->first != NULL)
    {
       self->current->data = d;
    }
}

int search_node(list_t* self, int d)
{
    node_t* ptr = self->first;
    // without zero, the value of index wont be cleared!?
    int index = 0;

    while(ptr != NULL)
    {
        if(ptr->data == d)
        {
            return index;
        }
        
        ptr = ptr->next;
        index += 1;
    }

    return -1;
}

// the method to print the linked list.
void print_lst(list_t* self)
{
    node_t* ptr = self->first;

    while(ptr != NULL)
    {
        if(ptr == self->current)
        {
            printf("[*%d] ", ptr->data);
        }
        else
        {
            printf("[%d] ", ptr->data);
        }
        
        ptr = ptr->next;
    }

    printf("\n");
}


void mv_cursor(list_t* self, dirct_t dirct)
{
    if(self->first != NULL)
    {
        if(dirct == left)
        {
            if(self->current != self->first)
            {
                node_t* ptr = self->first;
                
                while(ptr->next != self->current)
                {
                    ptr = ptr->next;
                }
                
                self->current = ptr;
            }
        }
        else if(dirct == right)
        {
            if(self->current->next != NULL)
            {
                self->current = self->current->next;
            }
        }
        else
        {
            printf("Error: undefined dirct in mv_cursor().\n");
        }
    }
}

void print_help()
{
    printf("<1> Add <2> Del <3> Update <4> Search\n");
    printf("<5> Left <6> Right <7> Exit\n");
}


void (*p_add_node)(list_t*, int) = add_node;
void (*p_del_node)(list_t*)      = del_node;
void (*p_upd_node)(list_t*, int) = update_node;
int  (*p_sch_node)(list_t*, int) = search_node;
void (*p_print_lst)(list_t*)     = print_lst;
void (*p_mv_cur)(list_t*, dirct_t) = mv_cursor;


int main(int argc, char** args)
{
    printf("Linked List Implementation in C\n");
    printf("-------------------------------\n");
    printf("Author: @marcobook\n");
    printf("Creation Date: 18/10/17\n\n");
    print_help();

    list_t* list = (list_t*)malloc(sizeof(list_t));

    do
    {
        int u_choice;
        int val;
        dirct_t dirct;

        if(u_choice != 0xa)
        {
            printf(">> ");
        }
        u_choice = getchar();

        switch(u_choice)
        {
            case 0x31:
                printf("Adding a new node. Value: ");
                scanf("%d", &val);
                p_add_node(list, val);
                break;
            case 0x32:
                printf("Deleting selected node.\n");
                p_del_node(list);
                break;
            case 0x33:
                printf("Updating selected node. Value: ");
                scanf("%d", &val);
                p_upd_node(list, val);
                break;
            case 0x34:
                printf("Searching for a node. Value: ");
                scanf("%d", &val);
                if(p_sch_node(list, val) != -1)
                {
                    printf("The node is at index: %d\n", p_sch_node(list, val));
                }
                else
                {
                    printf("The node does not exist.\n");
                }
            case 0x35:
                dirct = left;
                p_mv_cur(list, dirct);
                break;
            case 0x36:
                dirct = right;
                p_mv_cur(list, dirct);
                break;
            case 0x37:
                return 0;
            default:
                continue;
        }
        
        p_print_lst(list);
    } while(1);
    
    return 0;
}
