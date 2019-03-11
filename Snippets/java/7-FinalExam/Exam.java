import java.security.SecureRandom;

// TODO: revise the code with object array.

class Node
{
    public int content;
    public Node next;

    // default constructor.
    public Node()
    {
        this(0);
    }

    // overloaded constructor.
    public Node(int content)
    {
        this.content = content;
    }
}

class Bag
{
    protected SecureRandom random = new SecureRandom(); // static
    protected Node first; // head // the first node of the bag.
    protected int quantity; // size or numbers
    protected int min;
    protected int max;

    // default constructor.
    public Bag()
    {
        this(20, 0, 20);
    }

    // overloaded constructor.
    public Bag(int quantity, int min, int max)
    {
        first = null;

        this.quantity = quantity;
        this.min = min;
        this.max = max;

        // generate content automatically.
        generateNum();
    }


    // the method to add a node to the bag.
    protected void addNode(int content) // addNode(Node ...)
    {
        Node oldfirst = first;
        first = new Node(content);
        first.next = oldfirst;
    }

    // the method to generate numbers.
    public void generateNum()
    {
        int temp;

        for(int i=0; i<quantity; i++)
        {
            temp = min + random.nextInt(max - min + 1);
            addNode(temp);
        }
    }

    // the method to show the content.
    public void show()
    {
        Node ptr = first;

        while(ptr != null)
        {
            System.out.print(" " + ptr.content + "  ");
            ptr = ptr.next;
        }

        System.out.println();
    }

    // the method to get the frequency of a specific number.
    protected int getFreq(int target)
    {
        Node ptr = first;
        int freq = 0;

        while(ptr != null)
        {
            if(ptr.content == target)
            {
                freq += 1;
            }
            ptr = ptr.next;
        }

        return freq;
    }

    // the method to show the frequency stat.
    public String freq()
    {
        String optContent = "";
        String optFreq = "";
        String temp = "";
        Node ptr = first;
        Node tmp;
        int current = min;

        // first, we will show all the contents of the bag.
        while(current <= max)
        {
            temp = "" + current + "\t";
            optContent += temp;

            temp = "[" + getFreq(current) + "]\t";
            optFreq += temp;

            if(ptr.next != null)
            {
                ptr = ptr.next;
            }

            current += 1;
        }
        current = min;
        optContent += "\n";

        return optContent + optFreq;
    }

    public Bag sort()
    {
        Node ptr = first;
        boolean swapped = true;

        while(swapped)
        {
            swapped = false;
            while(ptr.next != null)
            {
                if(ptr.content > ptr.next.content)
                {
                    // swap data of the two nodes.
                    int temp = ptr.content;
                    ptr.content = ptr.next.content;
                    ptr.next.content = temp;

                    // change the flag.
                    swapped = true;
                }
                ptr = ptr.next;
            }
            ptr = first;
        }

        return this;
    }

    @Override
    public String toString()
    {
        Node ptr = first;
        String opt = "";
        String temp = "";

        while(ptr != null)
        {
            temp = ptr.content + "\t";
            opt += temp;
            ptr = ptr.next;
        }

        opt += "\n";
        return opt;
    }
}


class NumberSet extends Bag
{
    public NumberSet(int quantity, int min, int max)
    {
        super(quantity, min, max);
    }

    // the method to generate numbers.
    public void generateNum()
    {
        int temp;

        for(int i=0; i<quantity; i++)
        {
            temp = min + random.nextInt(max - min + 1);

            // check duplicate.
            if(getFreq(temp) == 0)
            {
                addNode(temp);
            }
            else
            {
                i -= 1;
            }
        }
    }
}


public class Exam
{
    public static void main(String[] args)
    {
        Bag b = new Bag(20, 0, 20);
        b.show(); // print the content of the bag.
        System.out.println("Freq:\n" + b.freq()); // print the frequency of occurrence.
        System.out.println("Sorted: " + b.sort());

        System.out.println("\n");

        Bag b1 = new NumberSet(20, 0, 30);
        b1.show(); // print the content of the bag.
        System.out.println("Freq:\n" + b1.freq()); // print the frequency of occurrence.
        System.out.println("Sorted: " + b1.sort());
    }
}
