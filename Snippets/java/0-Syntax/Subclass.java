class Superclass {
 
    private void doSomething() {
        System.out.println("from Superclass");
    }
}

public class Subclass extends Superclass {

    private void doSomething() {
        System.out.println("from Subclass");
    }

    public static void main (String[] args){
        Superclass obj = new Subclass();
        obj.doSomething(); //prints "from Superclass"
    }

}
