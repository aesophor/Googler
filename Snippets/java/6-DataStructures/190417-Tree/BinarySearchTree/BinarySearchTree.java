import java.util.Scanner;

class Node
{
    public Node left;
    public Node right;
    public int  data;

    // default constructor.
    public Node()
    {
        left  = null;
        right = null;
    }

    // overloaded constructor.
    public Node(int data)
    {
        this();
        this.data = data;
    }
}

class Tree
{
    private Scanner sc = new Scanner(System.in);
    private Node root;

    // default constructor.
    public Tree()
    {
        root = null;
    }


    // the method to check whether the tree is empty.
    public boolean isEmpty()
    {
        return root == null ? true : false;
    }

    // the method to get the root node.
    public Node getRoot()
    {
        return root;
    }

    // the method to insert a new node to the tree.
    public void insertNode(int data)
    {
        insertNode(root, new Node(data));
    }

    // the method to insert a new node to the tree.
    private void insertNode(Node target, Node newnode)
    {
        /* first, we check if the tree is empty.
         * if so, we set the newnode as the root node.
         */
        if(isEmpty())
        {
            root = newnode;
            return;
        }

        /* if the target node we are adding the newnode to is null,
         * set the target node as the root node.
         */
        if(target == null)
        {
            target = root;
        }

        // compare the value of the target node and the newnode.
        if(newnode.data < target.data)
        {
            if(target.left == null)
            {
                target.left = newnode;
                return;
            }

            else
            {
                // if the node is already occupied, call this method again.
                insertNode(target.left, newnode);
            }
        }

        else if(newnode.data > target.data)
        {
            if(target.right == null)
            {
                target.right = newnode;
                return;
            }

            else
            {
                // if the node is already occupied, call this method again.
                insertNode(target.right, newnode);
            }
        }
    }

    // the method to search and delete a node by data.
    public void removeNode(int d)
    {
        Node parent;
        Node ptr;
        Node child;
        boolean isFound = false;

        // find the target node to delete and its parent node.
        parent = ptr = root;

        while(ptr!=null && !isFound)
        {
            // break loop if the target node is found.
            if(ptr.data == d)
            {
                isFound = true;
            }

            else
            {
                // reserve the parent node.
                parent = ptr;

                if(ptr.data > d)
                {
                    ptr = ptr.left;
                }

                else
                {
                    ptr = ptr.right;
                }
            }
        }

        // target node not found
        if(ptr == null)
        {
            return;
        }

        // situation 1: deleting a leaf node.
        if(ptr.left==null && ptr.right==null)
        {
            if(ptr == root)
            {
                root = null;
            }

            else if(parent.left == ptr)
            {
                parent.left = null;
            }

            else
            {
                parent.right = null;
            }

            return;
        }

        // situation 2: no left child.
        if(ptr.left == null)
        {
            // make sure it's not the root node.
            if(parent != ptr)
            {
                if(parent.left == ptr)
                {
                    parent.left = ptr.right;
                }

                else
                {
                    parent.right = ptr.right;
                }
            }

            else
            {
                root = root.right;
            }

            return;
        }

        // situation 3: no right child.
        if(ptr.right == null)
        {
            // make sure it's not the root node.
            if(parent != ptr)
            {
                if(parent.right == ptr)
                {
                    parent.right = ptr.left;
                }

                else
                {
                    parent.left = ptr.left;
                }
            }

            else
            {
                root = root.left;
            }

            return;
        }

        // situation 4: both left and right children exist.
        parent = ptr;
        child = ptr.left;

        while(child.right != null)
        {
            parent = child;
            child = child.right;
        }

        ptr.data = child.data;

        if(parent.left == child)
        {
            parent.left = null;
        }

        else
        {
            parent.right = child.left;
        }

        return;
    }

    public void printPreOrder(Node node)
    {
        if(node != null)
        {
            System.out.print("[" + node.data + "] ");
            printPreOrder(node.left);
            printPreOrder(node.right);
        }
    }

    public void printInOrder(Node node)
    {
        if(node != null)
        {
            printInOrder(node.left);
            System.out.print("[" + node.data + "] ");
            printInOrder(node.right);
        }
    }

    public void printPostOrder(Node node)
    {
        if(node != null)
        {
            printPostOrder(node.left);
            printPostOrder(node.right);
            System.out.print("[" + node.data + "] ");
        }
    }
}


public class BinarySearchTree
{
    public static void printUsage()
    {
        System.out.println("Usage:\t<1>insert <2>remove");
        System.out.println("\t<9>usage <10>exit");
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        Tree t = new Tree();

        String userInput;
        int    userParam;

        System.out.println("Welcome to Binary Search Tree Program");
        System.out.println("======================================================");
        System.out.println("Manage your own binary searh tree.\n");
        System.out.println("Note: Duplicate values are not allowed to be inserted.");
        System.out.println("Created by Marco");
        System.out.println("Written in Java\n");
        printUsage();

        while(true)
        {
            System.out.println();
            t.printInOrder(t.getRoot());
            System.out.print("\n[Options]> ");
            userInput = sc.next();

            switch(userInput)
            {
                case "1":
                    System.out.printf("[+] Inserting a node to the BST. Value: ");
                    userParam = sc.nextInt();
                    t.insertNode(userParam);
                    System.out.printf("[+] Inserted a new node with value %d to the tree.\n", userParam);
                    break;

                case "2":
                    System.out.printf("[-] Removing a node from the BST. Value: ");
                    userParam = sc.nextInt();
                    t.removeNode(userParam);
                    System.out.printf("[-] Removed the node with value %d from the tree.\n", userParam);
                    break;

                case "9":
                    printUsage();
                    break;

                case "10":
                    System.exit(0);

                default:
                    System.out.printf("[!] The specified options does not exist.\n");
                    break;
            }
        }
    }
}
