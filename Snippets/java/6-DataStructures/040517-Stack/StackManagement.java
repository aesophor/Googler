import java.util.Scanner;

class Node
{
	int data;
	Node next;

	public Node(int data)
	{
		this.data = data;
	}
}

interface StackInterface
{
	boolean isStackEmpty();
	boolean push(int d);
	int     pop();
	void    printStack();
}

class Stack implements StackInterface
{
	private Node top;

	// default constructor.
	public Stack()
	{
		top = null;
	}


	// method to check if the stack is empty.
	public boolean isStackEmpty() { return top == null ? true : false; }

	// the method to push data to the stack.
	public boolean push(int d)
	{
		Node newnode;
		newnode      = new Node(d);
		newnode.next = top;
		top          = newnode;

		return true;
	}

	// the method to pop data from the stack.
	public int pop()
	{
		Node ptr;

		if(!isStackEmpty())
		{
			ptr = top;
			top = top.next;
			return ptr.data;
		}

		else
		{
			return -1;
		}
	}

	// the method to print the content of the stack.
	public void printStack()
	{
		Node ptr = top;

		while(ptr != null)
		{
			System.out.print(ptr.data + " ");
			ptr = ptr.next;
		}

		System.out.println();
	}
}


public class StackManagement
{
	public static void printUsage()
	{
		System.out.println("Usage:\t<1>Push <2>Pop");
		System.out.println("\t<9>usage <10>exit");
	}

	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		Stack st   = new Stack();

		String userInput;
        int    userParam;

		System.out.println("Welcome to Stack Manager");
        System.out.println("=========================================");
        System.out.println("A simple program to manage your own stack.\n");
        System.out.println("Created by Marco");
        System.out.println("Written in Java\n");

		printUsage();

		while(true)
		{
			System.out.println();
            st.printStack();
            System.out.printf("\n[Options]> ");
			userInput = sc.next();

			switch(userInput)
			{
				case "1":
					System.out.printf("[+] Pushing data to the stack. Value: ");
					userParam = sc.nextInt();
					st.push(userParam);
					System.out.printf("[+] Pushed data with value %d to the stack.\n", userParam);
					break;

				case "2":
					System.out.printf("[-] Popped an element from the Stack. Value: " + st.pop());
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
