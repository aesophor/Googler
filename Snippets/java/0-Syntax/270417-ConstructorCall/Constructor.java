class A
{
    // public A() {}
    public A(int i) { System.out.println("constructor A is called."); }
    public void f() {}
}

class B extends A
{
    public B() { System.out.println("constructor B is called."); }
    // public B() { super(0); System.out.println("constructor B is called."); }
}

public class Constructor
{
    public static void main(String[] args)
    {
        B b = new B();
        b.f();
    }
}
