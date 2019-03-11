public class Boxing {
    
    public static void main(String[] args) {
        Integer i = new Integer(31);
        System.out.println( Integer.parseInt(i.toString(), 8) );
        System.out.println( i ); // Auto-unboxing
        System.out.println( i.toString() );
    }
}
