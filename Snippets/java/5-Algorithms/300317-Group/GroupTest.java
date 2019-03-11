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
    public String toString() { return "[" + Integer.toString(getIndex()) + "]: " + Integer.toString(getData) + "\n"; }
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

        dataArray = new int[size];

        for(int i=0; i<dataArray.length; i++)
        {
            data = min + random.nextInt(max - min + 1);
            dataArray[i] = new Data(i, data);
        }
    }

    // the method to list the Group members.
    public String list()
    {
        String output = "";

        for(Data d : dataArray)
        {
            output += d;
        }

        return output;
    }

    // the method to get the largest member from the group.
    public int getMax()
    {
        int max = 0;

        for(int i=0; i<dataArray.length; i++)
        {
            if(dataArray[i].getData > max)
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
            if(dataArray[i].getData < min)
            {
                min = dataArray[i].getData();
            }
        }

        return min;
    }

}


public class GroupTest
{
    public static void main(String[] args)
    {
        Group g = new Group(10, 0, 100);

        System.out.println(g.list() + "\nMax: " + g.getMax() + "\nMin: " + g.getMin());
    }
}
