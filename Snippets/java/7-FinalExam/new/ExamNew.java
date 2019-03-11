import java.security.SecureRandom;

class Number
{
    private int data;
    private int freq;

    // default constructor.
    public Number()
    {
        this(0);
    }

    // overloaded constructor.
    public Number(int data)
    {
        this.data = data;
    }

    // the setter and getter method of Data.
    public void setData(int data) { this.data = data; }
    public int getData() { return data; }

    // the setter and getter method of Freq.
    public void incFreq() { freq++; }
    public int getFreq() { return freq; }
}

class Bag
{
    protected Number[] numRange; // the array contains all numbers within the range.
    protected Number[] numArray; // the array that stores the reference to number objects.
    protected int size;
    protected int min;
    protected int max;

    // default constructor.
    public Bag()
    {
        this(20, 0, 20);
    }

    // overloaded constructor.
    public Bag(int size, int min, int max)
    {
        this.size = size;
        this.min  = min;
        this.max  = max;

        genNumRange();
        genNumArray();
    }

    // the method to initialize numRange array.
    private void genNumRange()
    {
        numRange = new Number[max-min+1];
        int content = min;

        while(content <= max)
        {
            numRange[content-this.min] = new Number(content);
            content++;
        }
    }

    // the method to initialize and fill the array.
    protected void genNumArray()
    {
        SecureRandom random = new SecureRandom();
        numArray = new Number[size];
        int content;

        for(int i=0; i<size; i++)
        {
            // generate a number and store the reference we created earlier to numArray.
            content = min + random.nextInt(max - min + 1);
            numArray[i] = numRange[content-min];
            numArray[i].incFreq();
        }
    }

    // the method to show the content.
    public void show()
    {
        for(Number n: numArray)
        {
            System.out.print(" " + n.getData() + "\t");
        }
        System.out.println();
    }

    // the method to show the frequency of each Number.
    public String freq()
    {
        String temp = "";
        String output = "";
        int current = min;

        while(current <= max)
        {
            temp = "[" + current + "]\t";
            output += temp;
            current += 1;
        }

        output += "\n";

        for(Number n: numRange)
        {
            temp = " " + n.getFreq() + "\t";
            output += temp;
        }

        return output;
    }

    // the method to sort all numbers in the array.
    public Bag sort()
    {
        boolean swapped = true;
        Number temp;

        while(swapped)
        {
            swapped = false;

            for(int i=0; i<size-1; i++)
            {
                if(numArray[i].getData() > numArray[i+1].getData())
                {
                    // swap the numbers if they were put in wrong order.
                    temp = numArray[i+1];
                    numArray[i+1] = numArray[i];
                    numArray[i] = temp;

                    // change the flag.
                    swapped = true;
                }
            }
        }
        return this;
    }

    @Override
    public String toString()
    {
        String output = "";
        String temp = "";

        for(Number n: numArray)
        {
            temp = " " + n.getData() + "\t";
            output += temp;
        }
        return output;
    }
}

class NumberSet extends Bag
{
    // default constructor.
    public NumberSet()
    {
        super(20, 0, 25);
    }

    // overloaded constructor.
    public NumberSet(int size, int min, int max)
    {
        super(size, min, max);
    }


    // added duplicate check for numbers in the array.
    protected void genNumArray()
    {
        SecureRandom random = new SecureRandom();
        numArray = new Number[size];
        int content;

        for(int i=0; i<size; i++)
        {
            // generate a number and store the reference we created earlier to numArray.
            content = min + random.nextInt(max - min + 1);

            if(numRange[content-min].getFreq() == 0)
            {
                numArray[i] = numRange[content-min];
                numArray[i].incFreq();
            }
            else
            {
                i--;
            }
        }
    }
}

public class ExamNew
{
    public static void main(String[] args)
    {
        Bag b = new Bag(20, 0, 20);
        b.show(); // print the content of the bag.
        System.out.println("Freq:\n" + b.freq()); // print the frequency of occurrence.
        System.out.println("Sorted: " + b.sort());

        System.out.println("\n");

        Bag b1 = new NumberSet(20, 0, 25);
        b1.show(); // print the content of the bag.
        System.out.println("Freq:\n" + b1.freq()); // print the frequency of occurrence.
        System.out.println("Sorted: " + b1.sort());
    }
}
