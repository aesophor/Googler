#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int data;
    struct node* next;
} node_t;

typedef struct stack
{
    node_t* top; 
} stack_t;


// the method to push data to the stack.
void push(stack_t* self, int d)
{
    node_t* new_node;
    new_node = (node_t*)malloc(sizeof(node_t));

    new_node->data = d;
    new_node->next = self->top;

    self->top = new_node;
}

// the method to pop data from the stack.
// <NOTE>: the data is packaged in the node_t
node_t* pop(stack_t* self)
{
    if(self->top != NULL)
    {
        node_t* out;
        out = (node_t*)malloc(sizeof(node_t));
        out->data = self->top->data;

        self->top = self->top->next;
        return out;
    }

    // we cannot just return something like -1 :)
    // that's irrational!
    return NULL;
}

// the method to get the index of a specific data.
int search(stack_t* self, int d)
{
    node_t* ptr = self->top;
    int index = 0;

    while(ptr != NULL)
    {
        if(ptr->data == d)
        {
            return index;
        }

        ptr = ptr->next;
        index++;
    }

    return -1;
}

void print(stack_t* self)
{
    node_t* ptr = self->top;

    while(ptr != NULL)
    {
        if(ptr == self->top)
        {
            printf("%d*\n", ptr->data);
        }
        else
        {
            printf("%d\n", ptr->data);
        }
        ptr = ptr->next;
    }

    printf("\n");
}

void print_help()
{
    printf("<1> Push <2> Pop <3> Search\n");
}


int main(int argc, char** args)
{
    printf("Stack Implementation in C\n");
    printf("-------------------------\n");
    printf("Author: @marcobook\n");
    printf("Creation Date: 18/10/17\n\n");
    print_help();

    stack_t* stack = (stack_t*)malloc(sizeof(stack_t));

    do
    {
        int u_choice;
        int val;

        if(u_choice != 0xa)
        {
            printf(">> ");
        }
        u_choice = getchar();

        switch(u_choice)
        {
            case 0x31:
                printf("Pushing data to the stack. Value: ");
                scanf("%d", &val);
                push(stack, val);
                break;
            case 0x32:
                printf("Popping data from the stack: ");
                node_t* out = pop(stack);
                if(out != NULL)
                {
                    printf("%d\n", out->data);
                }
                break;
            case 0x33:
                printf("Searching for a node. Value: ");
                scanf("%d", &val);
                if(search(stack, val) != -1)
                {
                    printf("The node is at index: %d\n", search(stack, val));
                }
                else
                {
                    printf("The node does not exist.\n");
                }
            default:
                continue;
        }

        print(stack);
    } while(1);

    return 0;
}
