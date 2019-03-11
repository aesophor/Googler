final class C {
    public static final double PI;
 
    private C() {
        // Prevent instantiation.
    }

    static {
        PI = 3.14;
    }

}


public class Unextendable {
    public static void main(String[] args) {
        //C c = new C();
        System.out.println(C.PI);
    }
}
