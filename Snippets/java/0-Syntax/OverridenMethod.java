class P {
    int i = 1;
    int f() { return i; }
    static char g() { return 'P'; }
}

class C extends P {
    int i = 2;
    int f() { return -i; }
    static char g() { return 'C'; }
}


public class OverridenMethod {
    public static void main(String[] args) {
        C c = new C();

    }
}
