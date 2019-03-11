public class StringFormat {
    
    public static void main(String[] args) {
        int a = 5;
        int b = 7;
        
        String output = String.format("TextRecord%d%d", a, b);
        System.out.println(output);
    }
}
