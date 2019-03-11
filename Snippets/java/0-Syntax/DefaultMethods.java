interface A {

    public void f();

    // public void g();   --> C is not abstract and does not override abstract method g() in A.
    // public default void g();   --> missing method body.
    public default void g() {
        System.out.println("A default method must include an implementation!");
    }

}


class C implements A {

    public void f() {
        ;
    }

}
