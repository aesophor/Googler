public class CloneArray {
    
    public static void main(String[] args) {
        
        int[] arr = new int[] {1, 3, 5};
        int[] newArr = arr.clone();
        
        // Show the content of newArr.
        for (int e : newArr) {
            System.out.print(e + " ");
        }
    }
}
