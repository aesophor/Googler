class Numbers
{
    private int[] data;

    public Numbers(int[] data)
    {
        this.data = data;
    }
    
    public Numbers sort()
    {
        boolean swapped = true;
        
        while(swapped)
        {
            swapped = false;
            for(int i=0; i<data.length-1; i++)
            {
                if(data[i] > data[i+1])
                {
                    swap(data, i, i+1);
                    swapped = true;
                }
            }
        }
        return this;
    }

    public Numbers revSort()
    {
        boolean swapped = true;
        
        while(swapped)
        {
            swapped = false;
            for(int i=0; i<data.length-1; i++)
            {
                if(data[i] < data[i+1])
                {
                    swap(data, i, i+1);
                    swapped = true;
                }
            }
        }
        return this;
    }

    private static void swap(int[] data, int a, int b)
    {
        int temp = data[a];
        data[a] = data[b];
        data[b] = temp;
    }

    public String toString()
    {
        String output = ""; 

        for(int i=0; i<data.length; i++)
        {
            output = output + data[i];
        }

        return output;
    }
}


public class Quiz
{
    public static void main(String[] args)
    {
        Numbers n = new Numbers(new int[] {1,2,3});
        System.out.println(n.sort());
        System.out.println(n.revSort());
    }
}
