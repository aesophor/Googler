class S {
    //private void f() {
    public final void f() {
        System.out.println("Calling s.f()");
    }
}

class C extends S {
    public void f() {
        System.out.println("Calling c.f()");
    }
}
