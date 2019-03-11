import java.util.Scanner;

class ReverseCalc
{
    private Scanner sc;
    private int operand1;
    private int operand2;

    public ReverseCalc()
    {
        sc = new Scanner(System.in);
    }

    public void inputExpression()
    {
        System.out.println("Please enter your expression (a+b):");
        String exp = sc.next();

        String[] parts = exp.split("[+]");
        operand1 = Integer.parseInt(parts[0]);
        operand2 = Integer.parseInt(parts[1]);
    }

    public int calcResult()
    {
        return getReversed(operand1) + getReversed(operand2);
    }

    private int getReversed(int operand)
    {
        int reversed = 0;

        do
        {
            reversed = reversed*10 + operand%10;
            operand /= 10;
        } while(operand != 0);

        return reversed;
    }
}

public class Exam
{
    public static void main(String[] args)
    {
        ReverseCalc rc = new ReverseCalc();
        rc.inputExpression();
        System.out.println(rc.calcResult());
    }
}
