public class Bomb {
    
    private static int count;

    public static void bomb() {
        
        count++;
        
        bomb();
    }
    
    public static void main(String[] args) {
        try {
            bomb();
        } catch (StackOverflowError e) {
            ;
        } finally {
            System.out.println("Times called: " + count);
        }
    }
}
