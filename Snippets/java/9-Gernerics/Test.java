import marcolib.ds.Bag;

public class Test
{
    public static void main(String[] args)
    {
        Bag<String> b = new Bag<String>();
        
        b.add("Ander");
        b.add("Hsu");
        b.add("is");
        b.add("a");
        b.add("Stick");
        
        /*
        for(Integer i = b.next(); i != null; i = b.next())
        {
            System.out.println("The item in bag: " + i);
        }
        */
        
        System.out.println(b);
        System.out.println("Remove item: " + b.remove() + " from bag.");
        System.out.println(b);
    }
}
