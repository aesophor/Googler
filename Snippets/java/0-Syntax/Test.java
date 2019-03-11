public class Test {
    
    public static void main(String[] args) {
        
        char a = 'A';
        System.out.println(Character.toLowerCase(a));
        
        char c =  0xffff;
        short s = (short) c;
        System.out.println( (int) s );
        
        Integer i1 = new Integer(15);
        System.out.println(++i1);
        
        short i = 5;
        short j = 6;
        System.out.println( Integer.class.isInstance(i+j) );
        
        System.out.println( "The total is: " + (-6%5) );
        System.out.println( "The importance of paranthesis: " + 7/3.0f );
        
        int[] array = new int[] { 1, 2, 3, 4, 5 };
        //int[] array = { 1, 2, 3, 4, 5 }; same as above.
        int idx = 2;
        
        array[idx++] ++;
        //array[idx++] = array[idx++] + 1;
        
        for(int x : array) {
            System.out.print(x + " ");
        }
        
        System.out.println("\nidx: " + idx);
        
        // Equals(==) returns true when both sides are referring to the same object/array.
        String str1 = new String( new char[] {'H','e','l','l','o'} );
        String str2 = new String( new char[] {'H','e','l','z','o'} );
        System.out.println( str1 == str2 ); // Prints false.
        
        for(int l = 0; l < str1.length(); l++) {
            System.out.print(str1.charAt(l));
            if (l < str1.length()-1) System.out.print(", ");
        }
        System.out.println();
        
        double k = 5;
        System.out.println( i == k );
        
        for (int d=0; d<30; d++) {
            System.out.println("==> " + d);
        }
    }
}
