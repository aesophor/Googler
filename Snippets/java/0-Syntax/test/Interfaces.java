interface A {

    public void f();

}

class C implements A {

    public void f() {
        ;
    }
    // Both extending abstract class B and
    // implementing interface A
    // yields the same error:
    //
    // Interfaces is not abstract and does not override
    // abstract method f() in A/B [java/javac]
    //
}


public class Interfaces {
        
    public static void main(String[] args) {
        C c = new C();
        if (c instanceof A) {
            System.out.println("C is actually a type of A.");
        }
    }

}
