package branchedflow;

import java.util.Scanner;

public class BranchedFlow {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String rawInput = sc.next();
        int userChoice = Integer.parseInt(rawInput);
        boolean b = (userChoice == 3) ? true : false;
        
        switch(b) {
            case true:
                System.out.println("Control flow branch #1");
                break;
                
            case false:
                System.out.println("Control flow branch #2");
                break;
                
            default:
                System.out.println("Other situation.");
                break;
        }
    }
}
