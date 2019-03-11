public class InstanceOf {
    
    public static void main(String[] args) {
        
        int[] array = new int[] {1, 2, 3, 4, 5};
        
        if ( !(array instanceof int[]) ) {
            //array = new int[5];
            ;
        }
        
        for(int e : array) {
            System.out.print(e + " ");
        }
    }
}
