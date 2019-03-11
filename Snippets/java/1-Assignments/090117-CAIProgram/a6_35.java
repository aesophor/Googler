import java.security.SecureRandom;
import java.util.Scanner;

class Question
{
	private SecureRandom random = new SecureRandom();
	private Scanner sc          = new Scanner(System.in);

	private int num1;
	private int num2;
	private int userInput;

	// a blank constructor.
	public Question()
	{
		// blank.
	}

	// the method to generate a question.
	void createQuestion()
	{
		num1 = 1 + random.nextInt(9);
		num2 = 1 + random.nextInt(9);

		// only correct answer will break loop.
		while(true)
		{
			System.out.print("How much is " + num1 + " times " + num2 + "? >> ");
			userInput = sc.nextInt();

			// then we pass the three numbers above to function "checkAnswer".
			if(checkAnswer()==0)
				break;
			else
				System.out.println("No. Please try again.");
		}

		System.out.println("Very good!");
	}

	// the method for answer checking.
	int checkAnswer()
	{
		int result = num1 * num2;

		if(result == userInput)
			return 0;
		else
			return -1;
	}
}

public class a6_35
{
	public static void main(String[] argv)
	{
		Question questionCAI = new Question();

		// enter the infinite loop of generating questions.
		while(true)
		{
			questionCAI.createQuestion();
		}
	}
}
