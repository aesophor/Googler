class P {
    public P f() {
        System.out.println("Sorry, failed.");
        return this;
    }
}

class C extends P {
    //public void f() {  // error. f() in C cannot override f() in P.
    public P f() {
        System.out.println("Successfully overrided f() in P.");
        return ((P) this);
    }
}


public class OverridingSuper {
    public static void main(String[] args) {
        new C().f();
    }
}
