/* binary_tree.c
 * Binary Tree Implementation.
 * Author: @marcobook
 * Creation Date: 191017
 */
#include "bt.h"

typedef struct bstree
{
    btree_t super;
} bstree_t;


void trvse_bst_mknode(bstree_t* self, node_t* ptr, node_t* target)
{
    if(self->super.root == NULL)
    {
        self->super.root = target;
        self->super.current = target;
    }
    else
    {
        if(target->data < ptr->data)
        {
            if(ptr->l_child == NULL)
            {
                ptr->l_child = target;
            }
            else
            {
                trvse_bst_mknode(self, ptr->l_child, target);
            }
        }
        else if(target->data > ptr->data)
        {
            if(ptr->r_child == NULL)
            {
                ptr->r_child = target;
            }
            else
            {
                trvse_bst_mknode(self, ptr->r_child, target);
            }
        }
    }
}

void bst_mknode(bstree_t* self, int d)
{
    node_t* new_node = (node_t*)malloc(sizeof(node_t));
    new_node->data = d;

    trvse_bst_mknode(self, self->super.root, new_node);
}

void print_help()
{
    printf("<1> Add <2> Del <3> Update\n");
    printf("<4> Down(Left) <5> Up(Parent) <6> Down(Right)\n");
    printf("<7> Clear <8> Exit\n");
}


int main(int argc, char** args)
{
    printf("Binary Search Tree Implementation in C\n");
    printf("--------------------------------------\n");
    printf("Author: @marcobook\n");
    printf("Creation Date: 20/10/17\n\n");
    print_help();

    bstree_t* bstree = (bstree_t*)malloc(sizeof(bstree_t));

    do
    {
        int u_choice = 0;
        int val = 0;
        
        printf(">> ");
        while((u_choice=getchar()) == 0xa);

        switch(u_choice)
        {
            case 0x31:
                printf("Adding node to the Binary Tree. Value: ");
                scanf("%d", &val);
                bst_mknode(bstree, val);
                break;
            case 0x32:
                printf("Removing node (including childs) from the Binary Tree: %d\n",
                        rmnode((btree_t*)bstree, bstree->super.current)->data);
                break;
            case 0x33:
                printf("Updating current node. Value: ");
                scanf("%d", &val);
                update_node((btree_t*)bstree, val);
                break;
            case 0x34:
                btseek((btree_t*)bstree, to_l_child);
                break;
            case 0x35:
                btseek((btree_t*)bstree, to_parent);
                break;
            case 0x36:
                btseek((btree_t*)bstree, to_r_child);
                break;
            case 0x37:
                rmnode((btree_t*)bstree, bstree->super.root);
                break;
            case 0x38:
                return 0;
            default:
                continue;
        }

        print((btree_t*)bstree);
    } while(1);

    return 0;
}
