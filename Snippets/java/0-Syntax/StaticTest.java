class PrintStream {
    public void println(String s) {
        System.out.println(s);
    }
}

final class Sys {
    public static PrintStream out = new PrintStream();
}

public class StaticTest {
    public static void main(String[] args) {
        Sys.out.println("Hi");
    }
}
