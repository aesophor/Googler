interface SomeInterface {
    public static int someVar = 5;
    public void printVar();
}

public class InterfaceConstant implements SomeInterface {
    public void printVar() {
        System.out.println("The value of someVar is " + someVar);
    }
        
    public static void main(String[] args) {
        new InterfaceConstant().printVar();
    }
}
