import java.security.SecureRandom;

class IntData
{
    private SecureRandom random = new SecureRandom();
    private int data;
    private int[] numTimes;

    public IntData()
    {
        data = generateInt();
        numTimes = new int[10];
    }

    public int generateInt()
    {
        return random.nextInt();
    }

    public void calcNum()
    {
        int quot = data;

        do
        {
            numTimes[quot%10]++;
            quot = quot/10;
        } while(quot != 0);
    }

    public int getData() { return data; }

    public void printResult()
    {
        for(int i=0; i<numTimes.length; i++)
        {
            System.out.println(i + ": " + numTimes[i]);
        }
    }
}

public class Exam
{
    public static void main(String[] args)
    {
        IntData data = new IntData();

        data.generateInt();
        System.out.println(data.getData());

        data.calcNum();
        data.printResult();
    }
}
