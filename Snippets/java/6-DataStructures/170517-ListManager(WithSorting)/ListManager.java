import java.util.Scanner;

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

    @Override
    public String toString()
    {
        return Integer.toString(data);
    }
}

class List
{
    private Node first;
    private Node current;

    // default constructor.
    public List()
    {
        first   = null;
        current = first;
    }

    // overloaded constructor.
    public List(int[] array)
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

    // the method to get the first node.
    public Node getFirst() { return first; }

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


class DataSet
{
    private List dataList;

    // defulat constructor.
    public DataSet()
    {
        dataList = new List();
    }

    // overloaded constructor. (import existing list)
    public DataSet(List list)
    {
        dataList = list;
    }

    // the getter method of dataList.
    public List getDataList()
    {
        return dataList;
    }

    @Override
    public String toString()
    {
        String output = "Here shows the content of DataSet!";
        return output;
    }
}

interface Sort
{
    DataSet sort(DataSet ds);
}

// the method to sort the list's data using BubbleSort algorithm.
class BubbleSort implements Sort
{
    public DataSet sort(DataSet ds)
    {
        List dataList = ds.getDataList();
        Node ptr = dataList.getFirst();
        System.out.print(ptr);
        boolean swapped = true;

        while(swapped)
        {
            swapped = false;

            while(ptr.next != null)
            {
                if(ptr.data > ptr.next.data)
                {
                    // swap data of the two nodes.
                    int temp = ptr.data;
                    ptr.data = ptr.next.data;
                    ptr.next.data = temp;

                    // change the flag.
                    swapped = true;
                }

                ptr = ptr.next;
            }

            ptr = dataList.getFirst();
        }

        return new DataSet(dataList);
    }
}


// the method to sort the list's data using SelectionSort algorithm.
class SelectionSort implements Sort
{
    public DataSet sort(DataSet ds)
    {
        List dataList = ds.getDataList();
        Node ptr1 = dataList.getFirst();
        Node ptr2 = ptr1.next;

        while(ptr1.next != null)
        {
            Node min = ptr1;

            while(ptr2 != null)
            {
                if(ptr2.data < ptr1.data)
                {
                    min = ptr2;
                }

                ptr2 = ptr2.next;
            }

            int temp = ptr1.data;
            ptr1.data = min.data;
            min.data = temp;

            ptr1 = ptr1.next;
            ptr2 = ptr1.next;
        }

        return new DataSet(dataList);
    }
}

class Sorter
{
    private DataSet ds;
    Sort sortAct;

    // default constructor.
    public Sorter() {}

    // overloaded constructor.
    public Sorter(DataSet d, Sort s)
    {
        ds = d;
        sortAct = s;
    }

    public DataSet sort()
    {
        return sortAct.sort(ds);
    }

    public DataSet getDataSet()
    {
        return ds;
    }
}


public class ListManager
{
    public static void printInfo()
    {
        System.out.println("List Storage and Sorter");
        System.out.println("===========================");
        System.out.println("Store and sort your data.\n");
        System.out.println("Created by Marco");
        System.out.println("Written in Java\n");
    }

    public static void printUsage()
    {
        System.out.println("Usage:\t<1>add <2>delete <3>update <4>search");
        System.out.println("\t<5>forward <6>backward <7>first <8>last");
        System.out.println("\t<9>sort <10>usage <11>exit");
    }

    public static void main(String[] args)
    {
        List list = new List();
        Sorter s;

        printInfo();
        printUsage();

        Scanner sc = new Scanner(System.in);
        String userInput;
        int    userParam;

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
                    System.out.printf("[*] Sorting the list, select your method (1=BubbleSort, 2=SelectionSort): ");
                    userParam = sc.nextInt();
                    if(userParam == 1)
                    {
                        s = new Sorter(new DataSet(list), new BubbleSort());
                    }
                    else if(userParam == 2)
                    {
                        s = new Sorter(new DataSet(list), new SelectionSort());
                    }
                    else
                    {
                        System.out.printf("[!] The sorting method does not exist.\n");
                        break;
                    }
                    list = s.sort().getDataList();
                    break;

                case "10":
                    printUsage();
                    break;

                case "11":
                    System.exit(0);

                default:
                    System.out.printf("[!] The specified options does not exist.\n");
                    break;
            }
        }
    }
}
