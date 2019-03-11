class C
{
    public int i;

    public C(int i) { this.i = i; }
    public int getI() { return i; }

    @Override
    public String toString() { return Integer.toString(getI()); }
}

class D extends C
{
    public D() { super(); i=10; }
    public int getI() { return super.getI() * 10; }
}

class E extends D
{
    public E() { super(); }
}

class SuperUsage
{
    public static void main(String[] args)
    {
        E e = new E();
        System.out.println(e);
    }
}
