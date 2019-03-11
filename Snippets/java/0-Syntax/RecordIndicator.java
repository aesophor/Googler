enum Indicator {

    HEADER("H"),
    TEXT("T"),
    END("E");

    private final String text;

    /**
     * @param text
     */
    private Indicator(final String text) {
        this.text = text;
    }

    /* (non-Javadoc)
     * @see java.lang.Enum#toString()
     */
    @Override
    public String toString() {
        return text;
    }

    public static void f() {
        System.out.println("Called enum f().");
    }
}


public class RecordIndicator {

    public static void main(String[] args) {
        Indicator.f();
        System.out.println(Indicator.HEADER);
    }
}
