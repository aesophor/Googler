import java.security.SecureRandom;

class DataSet
{
    private SecureRandom sc;
    private int[] dataArray;

    public DataSet()
    {
        this(5, 0, 100);
    }

    public DataSet(int[] dataArray)
    {
        this.dataArray = dataArray;
    }

    public DataSet(int count, int maxValue, int minValue)
    {
        sc = new SecureRandom();
        dataArray = new int[count];
        
        for(int i=0; i<count; i++)
        {
            dataArray[i] = (sc.nextInt() % (maxValue-minValue+1)) + minValue;
        }
    }

    public DataSet getDataSet() { return this; }
    public int[] getDataArray() { return dataArray; }
    
    @Override
    public String toString()
    {
        String ret = "";
        
        for(int d : dataArray)
        {
            ret += "[" + d + "] ";
        }
        
        return ret;
    }
}


interface Sort
{
    public DataSet sort(DataSet ds);
}

class BubbleSort implements Sort
{
    public DataSet sort(DataSet ds)
    {
        int[] dataArray = ds.getDataArray();
        boolean swapped = false;
        
        do
        {
            swapped = false;

            for(int i=0; i<dataArray.length-1; i++)
            {
                if(dataArray[i+1] < dataArray[i])
                {
                    int temp = dataArray[i+1];
                    dataArray[i+1] = dataArray[i];
                    dataArray[i] = temp;
                    
                    swapped = true;
                }
            }
        } while(swapped);
        
        return new DataSet(dataArray);
    }
}

class SelectionSort implements Sort
{
    public DataSet sort(DataSet ds)
    {
        int[] dataArray = ds.getDataArray();
        
        for(int i=0; i<dataArray.length; i++)
        {
            int minIndex = i;
            for(int j=i; j<dataArray.length; j++)
            {
                if(dataArray[j] < dataArray[minIndex])
                {
                    minIndex = j;
                }
            }
            
            if(minIndex != i)
            {
                int temp = dataArray[i];
                dataArray[i] = dataArray[minIndex];
                dataArray[minIndex] = temp;
            }
        }
        
        return new DataSet(dataArray);
    }
}

class InsertionSort implements Sort
{
    public DataSet sort(DataSet ds)
    {
        int[] dataArray = ds.getDataArray();

        for(int i=1; i<dataArray.length; i++)
        {
            int ptr = i;
            int currentValue = dataArray[ptr];
            
            while(currentValue < dataArray[ptr-1])
            {
                dataArray[ptr] = dataArray[ptr-1];
                ptr--;

                if(ptr == 0) { break; }
            }
            
            dataArray[ptr] = currentValue;
        }
        
        return new DataSet(dataArray);
    }
}


class Sorter
{
    private DataSet ds;
    private Sort sortAct;

    public Sorter(DataSet ds, Sort sortAct)
    {
        this.ds = ds;
        this.sortAct = sortAct;
    }

    public DataSet sort()
    {
        return sortAct.sort(ds);
    }
}


public class SortAlgos
{
    public static void main(String[] args)
    {
        Sorter st;
        
        System.out.println("1. BubbleSort:");
        st = new Sorter(new DataSet(), new BubbleSort());
        System.out.println(st.sort());
        
        System.out.println("2. SelectionSort:");
        st = new Sorter(new DataSet(), new SelectionSort());
        System.out.println(st.sort());
        
        System.out.println("3. InsertionSort:");
        st = new Sorter(new DataSet(), new InsertionSort());
        System.out.println(st.sort());
    }
}
