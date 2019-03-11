import testpkg.A;

class B extends A {
    public B(String named) {
        super(named);
    }

    @Override
    public String getName() {
        return "B: " + name;
    }

    public String examine(A a) {      // name has protected access in A
    // public String examine(B b) {
        return "B sees: " + a.name;
    }
}

