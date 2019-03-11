class A
{
    static int varA = 5;
    int varB = 10;
}


class B extends A {}

class C extends B {}


public class InheritenceAndStaticVar
{
    public static void main(String[] args)
    {
        A obj1 = new A();
        B obj2 = new B();
        C obj3 = new C();

        System.out.println(obj2.varA);
        System.out.println(obj2.varB);
        System.out.println(obj3.varA);

        obj2.varA = 80;
        obj2.varB = 90;
        obj3.varA = 666;

        System.out.println(obj2.varA);
        System.out.println(obj2.varB);
        System.out.println(obj3.varA);
    }
}

// A, B, C override?
