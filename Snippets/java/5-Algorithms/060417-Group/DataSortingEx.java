import java.security.SecureRandom;


class Data
{
    private int index;
    private int data;

    // default constructor.
    public Data()
    {
        index = 0;
        data = 0;
    }

    // overloaded constructor.
    public Data(int index, int data)
    {
        this.index = index;
        this.data = data;
    }


    // the getter method for index.
    public int getIndex() { return index; }

    // the getter method for data;
    public int getData() { return data; }

    @Override
    public String toString() { return "[" + Integer.toString(getIndex()) + "]: " + Integer.toString(getData()) + "\n"; }
}


class Group
{
    private SecureRandom random = new SecureRandom();
    private Data[] dataArray;

    // default constructor.
    public Group()
    {
        this(5, 0, 100);
    }

    // overloaded constructor.
    public Group(int size, int min, int max)
    {
        int data;

        dataArray = new Data[size];

        for(int i=0; i<dataArray.length; i++)
        {
            data = min + random.nextInt(max - min + 1);
            dataArray[i] = new Data(i, data);
        }
    }

    @Override
    public String toString()
    {
        String output = "";

        for(Data d : dataArray)
        {
            output += d;
        }

        return output;
    }

    public Group getList() { return this; }

    // the method to list the Group members.
    public Group list() { return this; }

    // the method to swap two members in an array.
    private static void swap(Data[] array, int i, int j)
    {
        Data temp;

        temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    // the method to sort the members using Insertion Sort algorithm.
    public Group sort()
    {
        boolean swapped = true;

        while(swapped)
        {
            swapped = false;

            for(int i=0; i<dataArray.length-1; i++)
            {
                if(dataArray[i].getData() > dataArray[i+1].getData())
                {
                    // swap the numbers if they were put in wrong order.
                    swap(dataArray, i, i+1);

                    // change the flag.
                    swapped = true;
                }
            }
        }

        return this;
    }

    // the method to get the largest member from the group.
    public int getMax()
    {
        int max = 0;

        for(int i=0; i<dataArray.length; i++)
        {
            if(dataArray[i].getData() > max)
            {
                max = dataArray[i].getData();
            }
        }

        return max;
    }

    // the method to get the smallest member from the group.
    public int getMin()
    {
        int min = getMax();

        for(int i=0; i<dataArray.length; i++)
        {
            if(dataArray[i].getData() < min)
            {
                min = dataArray[i].getData();
            }
        }

        return min;
    }
}


public class DataSortingEx
{
    public static void main(String[] args)
    {
        Group g = new Group(10, 0, 100);

        System.out.println(g.list() + "\nMax: " + g.getMax() + "\nMin: " + g.getMin() + "\n");
        System.out.println("the sorted list:\n" + g.getList().sort());
    }
}
