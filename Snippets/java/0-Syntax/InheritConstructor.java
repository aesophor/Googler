class P {
    protected int a;
    protected int b;
    
    public P() {
        a = 1;
        b = 1;
    }

    public P(int a, int b) {
        this.a = a;
        this.b = b;
    }

    public int getA() { return a; }
    public int getB() { return b; }
    public void setA(int a) { this.a = a; }
    public void setB(int b) { this.b = b; }
}


class C extends P {
    private int c;

    public C() {
        //super();
        c = 1;
    }

    public C(int a, int b, int c) {
        super(a, b);
        this.c = c;
    }

    public int getC() { return c; }
    public void setC(int c) { this.c = c; }

    @Override
    public String toString() {
        String output = "";
        output += ("a: " + a + "\n");
        output += ("b: " + b + "\n");
        output += ("c: " + c + "\n");
        return output;
    }
}


public class InheritConstructor {
    public static void main(String[] args) {
        C c = new C();
        System.out.print(c);
    }
}
