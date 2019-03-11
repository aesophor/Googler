import java.security.SecureRandom;
import java.util.Scanner;
import java.lang.Math.*;

class Question
{
	private SecureRandom random = new SecureRandom();
	private Scanner sc          = new Scanner(System.in);

	private int num1;
	private int num2;
	private int userInput;

	private int currentLevel;
	private int commentIndex;
	private int timesTried;
	private int success;
    private int minimum;
	private int maximum;


	// the constructor of class "Question".
	public Question()
	{
		// currently blank.
	}

	// 10 questions each round.
	void createRound()
	{
		setLevel();

		while(timesTried < 10)
		{
			createQuestion();
		}

		// print user result after 10 rounds.
		if(calculateScore() >= 75)
		{
			System.out.println("Congratulations, you are ready to go to the next level!\n");
		}

		else
		{
			System.out.println("Please ask your teacher for extra help.\n");
		}

		// reset user data before the next round begin.
		resetScore();
	}

	// the method to generate a question.
	void createQuestion()
	{
		num1 = minimum + random.nextInt(maximum - minimum + 1);
		num2 = minimum + random.nextInt(maximum - minimum + 1);

		// only correct answer will break loop.
		while(timesTried < 10)
		{
			System.out.print("How much is " + num1 + " times " + num2 + "? >> ");
			userInput = sc.nextInt();

			// then we pass the three numbers above to function "checkAnswer".
			if(checkAnswer())
			{
				break;
			}

			else
			{
				// randomly choose a comment for incorrect answers.
				commentIndex = 1 + random.nextInt(4);
				switch(commentIndex)
				{
					case 1:
						System.out.println("No. Please try again.");
						break;
					case 2:
						System.out.println("Wrong. Try once more.");
						break;
					case 3:
						System.out.println("Don't give up!");
						break;
					case 4:
						System.out.println("No. Keep trying.");
						break;
					default:
						break;
				}

				timesTried += 1;
			}
		}

		// randomly choose a comment for correct answers.
		commentIndex = 1 + random.nextInt(4);
		switch(commentIndex)
		{
			case 1:
				System.out.println("Very good!");
				break;
			case 2:
				System.out.println("Excellent!");
				break;
			case 3:
				System.out.println("Nice work!");
				break;
			case 4:
				System.out.println("Keep up the good work!");
				break;
			default:
				break;
		}

		timesTried += 1;
		success += 1;
	}

	// the method for checking the answer.
	boolean checkAnswer()
	{
		int result = num1 * num2;

		if(result == userInput)
			return true;
		else
			return false;
	}

	// the method to calculate success rate (in percentage).
	int calculateScore()
	{
		return (success * 100) / timesTried;
	}

	// the method to reset success.
	void resetScore()
	{
		timesTried = 0;
		success    = 0;
	}

	// the method to get difficulty.
	int getLevel()
	{
		return currentLevel;
	}

	// the method to set difficulty.
	void setLevel()
	{
		System.out.print("Please enter difficulty (1 or above): ");
		currentLevel = sc.nextInt();

		// also be sure to set the maximum for random.
		// formula: 10^getLevel() - 1
		minimum = (int)Math.pow(10, getLevel()-1);
		maximum = (int)Math.pow(10, getLevel()) - 1;
	}
}


public class java638_1080630202
{
	public static void main(String[] argv)
	{
		Question questionCAI = new Question();

		// enter the infinite loop of generating rounds.
		while(true)
		{
			questionCAI.createRound();
		}
	}
}
