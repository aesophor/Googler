class Base
{
    int root = 3;
    int current = 8;

    public Base() {}
}

class Derived extends Base
{
    public Derived() {}
}

public class test
{
    public static void main(String[] args)
    {
        Base b = new Base();
        Derived d = new Derived();

        d.root = 2;
        System.out.println(b.root + " " + d.root);
    }
}
