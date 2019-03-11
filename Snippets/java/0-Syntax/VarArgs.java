public class VarArgs {
    
    public static int max(int first, int... rest) { // both distinct styles work fine.
    //public static int max(int first, int ... rest) {
        int max = first;
        for (int n : rest) {
            if (n > max) {
                max = n;
            }
        }
        return max;
    }

}
