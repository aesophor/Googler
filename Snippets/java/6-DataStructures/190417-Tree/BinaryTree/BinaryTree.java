import java.util.Scanner;

class Node
{
    int  index;
    int  data;
    Node left;
    Node right;
    Node parent; // remove this.

    // default constructor.
    public Node()
    {
        left   = null;
        right  = null;
        parent = null;
    }

    // overloaded constructor.
    public Node(int index, int data)
    {
        this();
        this.index = index;
        this.data  = data;
    }

    public Node getNode() { return this; }
}

class Tree
{
    private Scanner sc = new Scanner(System.in);
    private Node root;
    private int  index;

    // default constructor.
    public Tree()
    {
        index = 0;
        root = null;
    }


    public int getIndex() { return index; }

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

    // the method to create a node.
    public Node createNode(int data)
    {
        index += 1;
        return new Node(index-1, data);
    }

    // the method to add a new node to the tree.
    public void addNode(Node target, Node newnode)
    {
        // first, we check if the tree is empty.
        // if so, we set the newnode as the root node.
        if(isEmpty())
        {
            root = newnode;
            return;
        }

        // if the target node we are adding the newnode to is null,
        // set the target node as the root node.
        if(target == null)
        {
            target = root;
        }

        System.out.print("[+] Create the new node at which side of " + target.data + "? (L/R): ");
        char userInput = sc.next().charAt(0); //trim

        if(userInput == 'L' || userInput == 'l')
        {
            if(target.left == null)
            {
                target.left = newnode;
                newnode.parent = target;
                return;
            }

            else
            {
                // if the node is already occupied, call this method again.
                addNode(target.left, newnode);
            }
        }

        else if(userInput == 'R' || userInput == 'r')
        {
            if(target.right == null)
            {
                target.right = newnode;
                newnode.parent = target;
                return;
            }

            else
            {
                // if the node is already occupied, call this method again.
                addNode(target.right, newnode);
            }
        }

        else
        {
            System.out.println("[-] Invalid value. Retry.");
        }
    }


    // the method to search for a specific node using index.
    public Node searchNode(int index, Node node)
    {
        if(node != null)
        {
            // return the target node if found.
            if(node.index == index)
            {
                return node;
            }

            // keep searching for the specific node.
            Node resultLeft  = searchNode(index, node.left);
            Node resultRight = searchNode(index, node.right);

            if(resultLeft != null)
            {
                return resultLeft;
            }

            else if(resultRight != null)
            {
                return resultRight;
            }
        }

        return null;
    }

    // the method to delete a specific node.
    // find the target node and dereference it.
    public void deleteNode(int index)
    {
        // set root node to null if index is 0.
        // make sure we didn't miss "this".
        if(index == 0)
        {
            root = null;
            this.index = 0;
        }

        else
        {
            Node ptr = searchNode(index, root);

            if(ptr.parent.left.index == index)
            {
                ptr.parent.left = null;

            }

            else
            {
                ptr.parent.right = null;
            }
        }
    }

    public void printTree()
    {
        traverse(root);
    }

    private void traverse(Node node)
    {
        if(node != null)
        {
            traverse(node.left);
            System.out.print("[" + node.index + ":" + node.data  + "] ");
            traverse(node.right);
        }
    }
}


public class BinaryTree
{
    public static void printUsage()
    {
        System.out.println("Usage:\t<1>add <2>delete");
        System.out.println("\t<9>usage <10>exit");
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        Tree t = new Tree();

        String userInput;
        int    userParam;

        System.out.println("Welcome to Simple Binary Tree Program");
        System.out.println("================================================");
        System.out.println("A simple program to manage your own binary tree.\n");
        System.out.println("Created by Marco");
        System.out.println("Written in Java\n");
        printUsage();

        while(true)
        {
            System.out.println();
            t.printTree();
            System.out.print("\n[Options]> ");
            userInput = sc.next();

            switch(userInput)
            {
                case "1":
                    System.out.printf("[+] Adding a node to the tree. Value: ");
                    userParam = sc.nextInt();
                    t.addNode(t.getRoot(), t.createNode(userParam));
                    System.out.printf("[+] Added a new node with value %d to the tree.\n", userParam);
                    break;

                case "2":
                    System.out.printf("[-] Deleting a node from the tree. Index: ");
                    userParam = sc.nextInt();
                    t.deleteNode(userParam);
                    System.out.printf("[+] Deleted the node with index %d (and its children) from the tree.\n", userParam);
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
