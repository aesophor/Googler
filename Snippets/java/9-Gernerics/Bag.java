package marcolib.ds;

public class Bag<T>
{
    private T[] content;
    private int nextCount;
    private int size;
    
    public Bag()
    {
        this(10);
    }
    
    public Bag(int size)
    {
        this.size = size;
        content = (T[]) new Object[this.size];
    }

    // Add an item of type T to the bag.
    public void add(T t)
    {
        if(size == 0) { nextCount = 1; }
        content[nextCount] = t;
        nextCount++;
        size++;
    }

    // Get next item from the bag.
    public T next()
    {
        return content[nextCount--];
    }

    // Remove current item from the bag.
    public T remove()
    {
        if(size > 0)
        {
            T ret = content[--nextCount];
            content[nextCount] = null;
            return ret;
        }
        else
        {
            return null;
        }
    }

    @Override
    public String toString()
    {
        String ret = "";
        ret += "==> Content: ";
        for(int i=0; content[i] != null; i++)
        {
            ret += "[" + content[i] + "] ";
        }
        return ret;
    }
}
