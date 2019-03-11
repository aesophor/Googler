public class RunnableClass implements Runnable {
    
    public void run() {
        
        System.out.println("wut?");
    }
    
    public static void main(String[] args) {
        
        RunnableClass r = new RunnableClass();
        r.run();
    }
}
