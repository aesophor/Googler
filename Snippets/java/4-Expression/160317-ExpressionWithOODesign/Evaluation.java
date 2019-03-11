import java.util.Scanner;

abstract class Expression
{
	protected Stack  operators;    // the stack for storing operators. (used in conversion.)
	protected Stack  operands;     // the stack for storing operands. (used in calculation.)

	protected String expression;   // the content of the expression.
	protected String convertedExp; // the expression after being converted.

	protected Double result;       // the result of evaluation.

	abstract protected PostfixExpression toPostfix();
}

class InfixExpression extends Expression
{
	private String lastPopped; // the last operator popped from the stack.

	// default constructor.
	public InfixExpression()
	{
		operators = new Stack();
		operands  = new Stack();
	}

	// overloaded constructor.
	public InfixExpression(String expression)
	{
		this();
		this.expression = expression;
	}


	// the method to clear the content of convertedExp.
	private void clearConvertedExp() { convertedExp = ""; }

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
				convertedExp += lastPopped;
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
	public PostfixExpression toPostfix()
	{
		// clear convertedExp string before converting.
		clearConvertedExp();

		// step 1: scan all operands and operators from the infix expression.
		for(int i=0; i<expression.length(); i++)
		{
			char current = expression.charAt(i);
			// if an operator is scanned:
			//     a. "(" and ")"        --> see below.
			//     b. "*", "/", "+", "-" --> keep comparing its priority with
			//                               the priority of the topmost item
			//                               in the stack.
			//
			// if an operand is scanned:
			// append it to the convertedExp string directly.

			if(current == '(')
			{
				// if a '(' is scanned, push it to the stack.
				operators.push("(");
			}
			else if(current == ')')
			{
				// if a ')' is scanned, keep popping operators from the stack
				// and append them to the convertedExp string until '(' is popped.
				while(true)
				{
					lastPopped = operators.pop();

					if(lastPopped.equals("(")) { break; }
					else { convertedExp += lastPopped; }
				}
			}
			else if(current == '*' || current == '/' || current == '+' || current == '-')
			{
				comparePriority(Character.toString(current));
			}
			else
			{
				// if an operand is scanned, append it to the convertedExp string directly.
				convertedExp += expression.charAt(i);
			}
		}

		// step 2: if the operators stack is not empty,
		// pop them out and append to the convertedExp string.
		while(!operators.isEmpty())
		{
			convertedExp += operators.pop();
		}

		// return a new instance of postfix expression.
		return new PostfixExpression(convertedExp);
	}
}

class PostfixExpression extends Expression
{
	// default constructor.
	public PostfixExpression()
	{
		operators = new Stack();
		operands  = new Stack();
	}

	// overloaded constructor.
	public PostfixExpression(String expression)
	{
		this();
		this.expression = expression;
	}


	@Override
	public String toString() { return "[*] The result is: " + getResult() + "\n"; }

	// the method to get the value of result.
	private Double getResult() { return result; }

	// toPostfix() is an abstract method so we need to override the abstract method here.
	public PostfixExpression toPostfix() { return this; }

	// the method to calculate postfix expression.
	public PostfixExpression evaluate()
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
		for(int i=0; i<expression.length(); i++)
		{
			switch(expression.charAt(i))
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
					result = (1.0/Double.parseDouble(operands.pop())) * Double.parseDouble(operands.pop());
					operands.push(String.valueOf(result));
					break;
				default:
					operands.push(Character.toString(expression.charAt(i)));
					break;
			}
		}

		return this;
	}
}


public class Evaluation
{
	public static void main(String[] argv)
	{
		Scanner sc = new Scanner(System.in);
		Expression exp;
		String userInput;

		System.out.println("Welcome to Simple Calculator");
		System.out.println("===================================================================");
		System.out.println("Convert any infix expression into postfix and calculate its result.");
		System.out.println("Supported operators: ( ) + - * /");
		System.out.println("Created by Marco.");
		System.out.println("Written in Java.\n");

		while(true)
		{
			// receive an infix expression from the user.
			System.out.print("Infix> ");
			userInput = sc.next();

			// create a new instance for the infix expression.
			exp = new InfixExpression(userInput);

			// convert the infix expression into postfix and evaluate it.
			System.out.println(exp.toPostfix().evaluate());

			// dereference the exp object. (for garbage collecting)
			exp = null;
		}
	}
}
