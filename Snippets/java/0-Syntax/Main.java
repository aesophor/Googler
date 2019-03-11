public class Main {

    public static void throwException() throws DuplicateSymbolException {
        System.out.println("I'm thorwing an exception, catch it!");
        throw new DuplicateSymbolException();
    }

    public static void main(String[] args) {
        
        Object o = null;
        assert (o != null) : -1;
        
        try {
            throwException();
            return;
        } catch (DuplicateSymbolException e) {
            System.out.println("I'm handling it for you");
        } finally {
            System.out.println("Let's forget this and move on.");
        }
    }
}
