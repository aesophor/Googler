import java.util.Scanner;

class Calculator
{
	private Stack  operators;  // the stack for storing operators. (used in conversion.)
	private Stack  operands;   // the stack for storing operands. (used in calculation.)

	private String lastPopped; // the last operator popped from the stack.
	private String postfixExp; // the expression converted to postfix.
	private Double result;     // the result of the calculation.


	// default constructor.
	public Calculator()
	{
		operators = new Stack(); // stack "operators" has the type of String.
		operands  = new Stack(); // stack "operands" has the type of Double.
	}


	// the method to get the value of result.
	public Double getResult() { return result; }

	// the method to get the converted expression.
	public String getPostfixExp() { return postfixExp; }

	// the method to clear the content of postfixExp.
	private void clearPostfixExp() { postfixExp = ""; }

	// the method to get the priority of the operator.
	// the higher the value returned, the higher the priority.
	private int getPriority(String operatorName)
	{
		switch(operatorName)
		{
			case "*":
				return 2;

			case "/":
				return 2;

			case "+":
				return 1;

			case "-":
				return 1;

			case "(":
				return 0;

			case ")":
				return 0;

			default:
				return -1;
		}
	}

	// the method to compare the priority of the operator
	// with the priority of the topmost item in the stack.
	private void comparePriority(String operatorName)
	{
		while(!operators.isEmpty())
		{
			lastPopped = operators.pop();

			if(getPriority(operatorName) <= getPriority(lastPopped))
			{
				postfixExp += lastPopped;
			}

			else
			{
				// make sure to push it back to the stack,
				// if the operator we just popped is not going to be used.
				operators.push(lastPopped);
				break;
			}
		}

		operators.push(operatorName);
	}

	// the method to convert infix expression to postfix.
	public void convertToPostfix(String userInput)
	{
		// clear postfixExp string before converting.
		clearPostfixExp();

		// step 1: scan all operands and operators from the infix expression.
		for(int i=0; i<userInput.length(); i++)
		{
			// if an operator is scanned:
			//     a. "(" and ")"        --> see below.
			//     b. "*", "/", "+", "-" --> keep comparing its priority with
			//                               the priority of the topmost item
			//                               in the stack.
			//
			// if an operand is scanned:
			// append it to the postfixExp string directly.
			switch(userInput.charAt(i))
			{
				case '(':
					// if a '(' is scanned, push it to the stack.
					operators.push("(");
					break;

				case ')':
					// if a ')' is scanned, keep popping operators from the stack
					// and append them to the postfixExp string until '(' is popped.
					while(true)
					{
						lastPopped = operators.pop();

						if(lastPopped.equals("(")) { break; }
						else { postfixExp += lastPopped; }
					}
					break;

				case '*':
					comparePriority("*");
					break;

				case '/':
					comparePriority("/");
					break;

				case '+':
					comparePriority("+");
					break;

				case '-':
					comparePriority("-");
					break;

				default:
					// if an operand is scanned, append it to the postfixExp string directly.
					postfixExp += userInput.charAt(i);
					break;
			}
		}

		// step 2: if the operators stack is not empty,
		// pop them out and append to the postfixExp string.
		while(!operators.isEmpty())
		{
			postfixExp += operators.pop();
		}
	}


	// the method to calculate postfix expression.
	public Double calculatePostfix(String userInput)
	{
		// scan the postfix expression from left to right, char by char.
		//
		// if an operator is scanned:
		// a. pop two operands from the stack.
		// b. evaluate the result of the two operands using this operator.
		// c. push the result value back to the operands stack.
		//
		// if an operand is scanned:
		// push it to the operands stack directly.
		for(int i=0; i<userInput.length(); i++)
		{
			switch(userInput.charAt(i))
			{
				case '+':
					result = Double.parseDouble(operands.pop()) + Double.parseDouble(operands.pop());
					operands.push(String.valueOf(result));
					break;
				case '-':
					result = -Double.parseDouble(operands.pop()) + Double.parseDouble(operands.pop());
					operands.push(String.valueOf(result));
					break;
				case '*':
					result = Double.parseDouble(operands.pop()) * Double.parseDouble(operands.pop());
					operands.push(String.valueOf(result));
					break;
				case '/':
					result = Double.parseDouble(operands.pop()) / Double.parseDouble(operands.pop());
					operands.push(String.valueOf(result));
					break;
				default:
					operands.push(Character.toString(userInput.charAt(i)));
					break;
			}
		}

		return result;
	}
}

public class Evaluation
{
	public static void main(String[] argv)
	{
		Scanner sc     = new Scanner(System.in);
		Calculator cal = new Calculator();

		String userInput;


		System.out.println("Welcome to Simple Calculator");
		System.out.println("===============================================");
		System.out.println("Convert any infix expression into postfix and");
		System.out.println("calculate its result.\n");
		System.out.println("Created by Marco.");
		System.out.println("Written in Java.\n");

		while(true)
		{
			// receive an infix expression from the user.
			System.out.print("Infix> ");
			userInput = sc.next();

			// convert the infix expression into postfix.
			cal.convertToPostfix(userInput);
			System.out.println("[*] The postfix is: " + cal.getPostfixExp());

			// calculate the result.
			cal.calculatePostfix(cal.getPostfixExp());
			System.out.println("[*] The result is: " + cal.getResult());
			System.out.println();
		}
	}
}
