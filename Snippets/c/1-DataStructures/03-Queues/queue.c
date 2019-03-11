#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} node_t;

typedef struct queue
{
    node_t* front;
    node_t* rear;
} queue_t;


/* Queue:
 *           ---------------------
 *  rear --> | 5 | 4 | 3 | 2 | 1 | --> front
 *           ---------------------
 */

void enqueue(queue_t* self, int d)
{
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = d;

    if(self->front == NULL)
    {    
        self->front = new_node;
        self->rear = new_node;
    }
    else
    {
        new_node->next = self->rear; 
        self->rear = new_node;
    }

}

node_t* dequeue(queue_t* self)
{
    if(self->front == self->rear)
    {
        node_t* out = self->front;
        self->front = NULL;
        self->rear = NULL;
        return out;
    }
    if(self->rear != NULL)
    {
        node_t* ptr = self->rear;
        node_t* out;

        while(ptr->next != self->front)
        {
            ptr = ptr->next;
        }
        out = ptr->next;
        ptr->next = NULL;
        self->front = ptr;
        
        return out;
    }

    return NULL;
}

void print(queue_t* self)
{
    if(self->rear != NULL)
    {
        node_t* ptr = self->rear;

        while(ptr != NULL)
        {
            printf("[%d] ", ptr->data);
            ptr = ptr->next;
        }

        printf("\n");
    }
}

void print_help()
{
    printf("<1> Enqueue <2> Dequeue\n");
}


int main(int argc, char** args)
{
    printf("Queue Implementation in C\n");
    printf("-------------------------\n");
    printf("Author: @marcobook\n");
    printf("Creation Date: 19/10/17\n\n");
    print_help();

    queue_t* queue = (queue_t*)malloc(sizeof(queue_t));

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
                printf("Enqueuing data to the Queue. Value: ");
                scanf("%d", &val);
                enqueue(queue, val);
                break;
            case 0x32:
                printf("Dequeuing data from the Queue: ");
                node_t* out = dequeue(queue);
                if(out != NULL)
                {
                    printf("%d", out->data);
                }
                printf("\n");
                break;
            default:
                continue;
        }

        print(queue);
    } while(1);

    return 0;
}
