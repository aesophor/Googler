/* binary_tree.c
 * Binary Tree Implementation.
 * Author: @marcobook
 * Creation Date: 191017
 */
#include "bt.h"

void print_help()
{
    printf("<1> Add <2> Del <3> Update\n");
    printf("<4> Down(Left) <5> Up(Parent) <6> Down(Right)\n");
    printf("<7> Clear <8> Exit\n");
}


int main(int argc, char** args)
{
    printf("Binary Tree Implementation in C\n");
    printf("-------------------------------\n");
    printf("Author: @marcobook\n");
    printf("Creation Date: 19/10/17\n\n");
    print_help();

    btree_t* btree;
    btree = (btree_t*)malloc(sizeof(btree_t));

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
                mknode(btree, val);
                break;
            case 0x32:
                printf("Removing node (including childs) from the Binary Tree: %d\n",
                        rmnode(btree, btree->current)->data);
                break;
            case 0x33:
                printf("Updating current node. Value: ");
                scanf("%d", &val);
                update_node(btree, val);
                break;
            case 0x34:
                btseek(btree, to_l_child);
                break;
            case 0x35:
                btseek(btree, to_parent);
                break;
            case 0x36:
                btseek(btree, to_r_child);
                break;
            case 0x37:
                rmnode(btree, btree->root);
                break;
            case 0x38:
                return 0;
            default:
                continue;
        }

        print(btree);
    } while(1);

    return 0;
}
