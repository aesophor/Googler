import java.util.Scanner;

// the class of Node.
class Node
{
    int  data; // every single Node contains a data.
    Node next; // the pointer that refers to the next Node.

    // default constructor.
    public Node()
    {
        this.data = 0;    // set data to 0 by default.
        next      = null; // the next pointer refers to null by default.
    }

    // overloaded constructor.
    public Node(int data)
    {
        this.data = data; // set data using the parameter.
        next      = null; // the next pointer refers to null by default.
    }
}

// the abstract class of List.
abstract class List
{
    protected Node first;
    protected Node current;

    abstract void    printList();
    abstract boolean isEmpty();
    abstract int     length();
    abstract int     getNodeIndex(int data);
    abstract Node    getPreviousNode();

    abstract void    add(int data);
    abstract void    delete();
    abstract void    replace(int data);
}

// the actual class of Singly Linked List.
class SinglyLinked extends List
{
    // default constructor.
    public SinglyLinked()
    {
        first   = null;
        current = first;
    }

    // overloaded constructor.
    public SinglyLinked(int[] array)
    {
        this();
        Node newnode;

        for(int element : array)
        {
            newnode      = new Node(element);
            newnode.next = first;
            first        = newnode;
            current      = first;
        }
    }


    // the method to check whether the List is empty.
    public boolean isEmpty() { return first == null ? true : false; }

    // the method to get the length of the List.
    public int length()
    {
        if(isEmpty())
        {
            return 0;
        }

        else
        {
            Node ptr = first;
            int  len = 0;

            while(ptr != null)
            {
                len += 1;
                ptr  = ptr.next;
            }

            return len;
        }
    }

    // the method to print the List.
    public void printList()
    {
        if(isEmpty())
        {
            System.out.printf("[]");
        }

        else
        {
            Node ptr = first;

            while(ptr != null)
            {
                if(ptr == current) { System.out.printf("[*%d]", ptr.data); }
                else               { System.out.printf("[%d]", ptr.data); }

                ptr = ptr.next;
            }
        }

        System.out.printf(" (length = %d)", length());
    }

    // the method to get the index of a specific node.
    public int getNodeIndex(int data)
    {
        Node ptr = first;
        int  index = 0;

        while(ptr.next != null)
        {
            if(ptr.data == data)
            {
                return index;
            }

            ptr = ptr.next;
            index += 1;
        }

        return -1;
    }

    // the method to get the node prior to the current selected node.
    public Node getPreviousNode()
    {
        Node ptr = first;

        while(ptr.next != current)
        {
            ptr = ptr.next;
        }

        return ptr;
    }

    // the method to add a new Node to the list.
    public void add(int data)
    {
        Node newnode = new Node(data);

        // add a node at the beginning of the list.
        if(current == first)
        {
            newnode.next = first;
            first        = newnode;
            current      = newnode;
        }
        // add a node in the middle of the list.
        else
        {
            Node ptr = getPreviousNode();

            ptr.next     = newnode;
            newnode.next = current;
            current      = newnode;
        }
    }

    // the method to delete current selected node from the list.
    public void delete()
    {
        Node ptr;

        // delete the first node from the list.
        if(first == current)
        {
            first = first.next;
        }

        // delete the last node from the list.
        else if(current.next == null)
        {
            ptr = getPreviousNode();
            ptr.next = null;
        }

        // delete a node from the middle of the list.
        else
        {
            ptr = getPreviousNode();
            ptr.next = current.next;
        }

        // reset the current selected node.
        current = first;
    }

    // the method to replace the data of current selected node.
    public void replace(int data)
    {
        current.data = data;
    }

    // the method to move forward.
    public void moveForward()
    {
        if(current.next != null)
        {
            current = current.next;
        }
    }

    // the method to move backward.
    public void moveBackward()
    {
        current = getPreviousNode();
    }

    // the method to select the first node.
    public void moveToFirst()
    {
        current = first;
    }

    // the method to select the last node.
    public void moveToLast()
    {
        Node ptr = first;

        while(ptr.next != null)
        {
            ptr = ptr.next;
        }

        current = ptr;
    }
}


public class ListManagement
{
    public static void printUsage()
    {
        System.out.println("Usage:\t<1>add <2>delete <3>update <4>search");
        System.out.println("\t<5>forward <6>backward <7>first <8>last");
        System.out.println("\t<9>usage <10>exit");
    }

    public static void main(String[] args)
    {
        Scanner      sc   = new Scanner(System.in);
        SinglyLinked list = new SinglyLinked();

        String userInput;
        int    userParam;


        System.out.println("Welcome to Singly Linked List Manager");
        System.out.println("=========================================");
        System.out.println("A simple program to manage your own list.\n");
        System.out.println("Created by Marco");
        System.out.println("Written in Java\n");

        printUsage();

        while(true)
        {
            System.out.println();
            list.printList();
            System.out.printf("\n[Options]> ");
            userInput = sc.next();

            switch(userInput)
            {
                case "1":
                    System.out.printf("[+] Adding a node to the List. Value: ");
                    userParam = sc.nextInt();
                    list.add(userParam);
                    System.out.printf("[+] Added a new node with value %d to the List.\n", userParam);
                    break;

                case "2":
                    System.out.printf("[-] Deleted current selectd node from the List.\n");
                    list.delete();
                    break;

                case "3":
                    System.out.printf("[+] Updating current node. Value: ");
                    userParam = sc.nextInt();
                    list.replace(userParam);
                    System.out.printf("[+] Updated current node with value %d.\n", userParam);
                    break;

                case "4":
                    System.out.printf("[?] Searching a specific node. Value: ");
                    userParam = sc.nextInt();
                    System.out.printf("[?] The node with value %d is at the position %d\n", userParam, list.getNodeIndex(userParam));
                    break;

                case "5":
                    System.out.printf("[*] Moving the current node forward by 1 unit.\n");
                    list.moveForward();
                    break;

                case "6":
                    System.out.printf("[*] Moving the current node backward by 1 unit.\n ");
                    list.moveBackward();
                    break;

                case "7":
                    System.out.printf("[*] Selected the first node.\n ");
                    list.moveToFirst();
                    break;

                case "8":
                    System.out.printf("[*] Selected the last node.\n ");
                    list.moveToLast();
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
