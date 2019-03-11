import java.util.Arrays;

public class ArrayUtil {
    
    public static void main(String[] args) {
        int[] arr = new int[] {11, 3, 25, 87, 19};
        Arrays.sort(arr);
        
        /*
        for (int e : arr) {
            System.out.print(e + " ");
        }
        */
        System.out.println(Arrays.toString(arr));
        
        int[][] products = new int[10][]; // Wut...?
        
        
        int[] newArr = arr.clone();
        System.out.println("Comparing using arr.equals() : " + newArr.equals(arr));
        System.out.println("Comparing using java.util.Arrays.equals() : " + Arrays.equals(arr, newArr));
    }
}
