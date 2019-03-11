#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* l_child;
    struct node* r_child;
} node_t;

typedef struct btree
{
    node_t* root;
    node_t* current;
} btree_t;

typedef enum dirct
{
    to_root,
    to_parent,
    to_l_child,
    to_r_child,
} dirct_t;


/* node_t* get_prt_node(btree_t* self, node_t* ptr, node_t* c_target)
 * ------------------------------------------------------------------
 * Returns the parent of a specific node.
 * Note on parameters:
 * - btree_t* self: your tree struct.
 * - node_t* ptr: the node to begin the search with.
 * - node_t* c_target: the child which you want to get its parent.
 */
node_t* get_prt_node(btree_t* self, node_t* ptr, node_t* c_target)
{
    // if asking for the parent node of the root,
    // simply return root node.
    if(self->root == c_target) { return self->root; }

    // find the parent node of a specific node.
    if(ptr->l_child != NULL)   { get_prt_node(self, ptr->l_child, c_target); }
    if((ptr->l_child==c_target) || (ptr->r_child==c_target)) { return ptr; }
    if(ptr->r_child != NULL)   { get_prt_node(self, ptr->r_child, c_target); }
}

/* int prompt_mknode()
 * --------------------------------------
 * Prompt the user to enter in which they
 * want to place the new node at (L/R).
 */
int prompt_mknode()
{
    int ret = 0;
    
    printf("Where would you like to place the new node? (L/R): ");
    while((ret=getchar()) == 0xa);
    
    if(ret == 'L' || ret == 'l' || ret == 'R' || ret == 'r')
    {
        return ret;
    }
    else
    {
        printf("Wrong Option. Retry.\n");
        return prompt_mknode();
    }
}

/* void mknode(btree_t* self)
 * -----------------------------------------
 * Add a new node to a tree.
 * btree_t* self: pointer to a tree object.
 * node_t* ptr: pointer to a node of a tree.
 */
void mknode(btree_t* self, int d)
{
    if(self->root == NULL)
    {
        node_t* new_node = (node_t*)malloc(sizeof(node_t));
        new_node->data = d;

        self->root = new_node;
        self->current = self->root;
    }
    else
    {
        int side = prompt_mknode();

        if(side=='L' || side=='l')
        {
            if(self->current->l_child == NULL)
            {
                // create a new node.
                node_t* new_node = (node_t*)malloc(sizeof(node_t));
                new_node->data = d;
                
                // connect the node we are at with the new node.
                // and reset the current node.
                self->current->l_child = new_node;
                self->current = self->current->l_child;
            }
            else
            {
                // jump to the left child, and run add_node() again.
                self->current = self->current->l_child;
                mknode(self, d);
            }
        }
        else if(side=='R' || side=='r')
        {
            if(self->current->r_child == NULL)
            {
                // create a new node.
                node_t* new_node = (node_t*)malloc(sizeof(node_t));
                new_node->data = d;
                
                // connect the node we are at with the new node.
                // and reset the current node.
                self->current->r_child = new_node;
                self->current = self->current->r_child;
            }
            else
            {
                // jump to the right child, and run add_node() again.
                self->current = self->current->r_child;
                mknode(self, d);
            }
        }
    }
}

/* node_t* rmnode(btree_t* self, node_t* target)
 * ----------------------------------------------
 * Removes a node and its children from the tree.
 */
node_t* rmnode(btree_t* self, node_t* target)
{
    if(target != NULL)
    {
        node_t* cur_tmp = target;

        if(target == self->root)
        {
            self->root = NULL;
            self->current = NULL;
            return cur_tmp;
        }
        else
        {
            target = get_prt_node(self, self->root, target);
            
            // unassociate current node with its parent.
            if(target->l_child == cur_tmp)
            {
                target->l_child = NULL;
            }
            else if(target->r_child == cur_tmp)
            {
                target->r_child = NULL;
            }
            self->current = target;

            return cur_tmp;
        }
    }

    return NULL;
}


/* void update_node(btree* self, int d)
 * ------------------------------------
 * Updates the data of a tree node.
 */
void update_node(btree_t* self, int d)
{
    self->current->data = d;
}


/* btseek(btree_t* self, dirct_t dirct)
 * ------------------------------------
 * Jump to a specific node.
 * The following locations are supported.
 * - root
 * - parent
 * - left child
 * - right child
 */
void btseek(btree_t* self, dirct_t dirct)
{
    switch(dirct)
    {
        case to_root:
            self->current = self->root;
            break;
        case to_parent:
            if(self->current != self->root) { self->current = get_prt_node(self, self->root, self->current); }
            else{ printf("Already at root.\n"); }
            break;
        case to_l_child:
            if(self->current->l_child != NULL) { self->current = self->current->l_child; }
            else { printf("Current node has no left child.\n"); }
            break;
        case to_r_child:
            if(self->current->r_child != NULL) { self->current = self->current->r_child; }
            else { printf("Current node has no right child.\n"); }
            break;
        default:
            printf("Wrong argument in mv_cursor()\n");
            break;
    }
}


/* trvse_print(btree_t* self, node_t* ptr)
 * ---------------------------------------
 * Traverses through the Binary Tree,
 * and print all of its nodes in In-Order.
 */
void trvse_print(btree_t* self, node_t* ptr)
{
    if(ptr->l_child != NULL)
    {
        trvse_print(self, ptr->l_child);
    }

    if(self->current == ptr)
    {
        printf("[*%d] ", ptr->data);
    }
    else
    {
        printf("[%d] ", ptr->data);
    }    
    
    if(ptr->r_child != NULL)
    {
        trvse_print(self, ptr->r_child);
    }
}

/* void print(btree_t* self)
 * ----------------------------------------
 * Wrapper function for trvse_print().
 * Prints all nodes of a tree.
 */
void print(btree_t* self)
{
    if(self->root != NULL)
    {
        trvse_print(self, self->root);
    }
    else
    {
        printf("(Empty)");
    }

    printf("\n\n");
}

