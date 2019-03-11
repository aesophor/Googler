import java.util.Scanner;
import java.util.regex.*;

class TurtleGraphics
{
	private int[][] mapArray;
	private int[]   position;
	private int     penState;  // penState: 0 is down, 1 is up.
	private int     direction; // direction: 1 is up, 2 is down, 3 is left, 4 is right.


	// default constructor.
	public TurtleGraphics()
	{
		// initialize the mapArray with default values.
		// and set penState to up by default.
		mapArray  = new int[20][20];
		position  = new int[2];

		position[0] = 0;
		position[1] = 0;
		updateMap();

		penState  = 1;
		direction = 4;
	}

	// overrided constructor.
	public TurtleGraphics(int height, int width)
	{
		// initialize the mapArray with custom values.
		// and set penState to up by default.
		mapArray  = new int[height][width];
		position  = new int[2];

		position[0] = 0;
		position[1] = 0;
		updateMap();

		penState  = 1;
		direction = 4;
	}


	// the method to display the map. (see how the turtle has moved)
	public void displayMap()
	{
		// iterate through the array.
		// if an 0 is read, display a blank. otherwise, display an asterisk.
		for(int[] mapArrayRow: mapArray)
		{
			for(int mapArrayCol: mapArrayRow)
			{
				if(mapArrayCol == 0) { System.out.print("[ ]"); }
				else 				 { System.out.print("[*]"); }
			}

			System.out.println();
		}

		System.out.println();
	}

	// the method to update the position of the Turtle (write to mapArray).
	private void updateMap()
	{
		if(getPenState() == 0)
		{
			mapArray[position[0]][position[1]] = 1;
		}
	}

	// the getter and setter for penState.
	public void setPenState(int penState) { this.penState = penState; }
	public int  getPenState() 		      { return penState; }

	// the methods to move and turn the turtle.
	public void moveForward(int dist)
	{
		if(direction == 1)
		{
			position[0] -= dist;
			updateMap();
		}

		else if(direction == 2)
		{
			position[0] += dist;
			updateMap();
		}

		else if(direction == 3)
		{
			position[1] -= dist;
			updateMap();
		}

		else
		{
			position[1] += dist;
			updateMap();
		}
	}

	public void turnLeft()
	{
		if(direction == 1)      { direction = 3; }
		else if(direction == 2) { direction = 4; }
		else if(direction == 3) { direction = 2; }
		else 					{ direction = 1; }
	}

	public void turnRight()
	{
		if(direction == 1)      { direction = 4; }
		else if(direction == 2) { direction = 3; }
		else if(direction == 3) { direction = 1; }
		else 					{ direction = 2; }
	}
}

public class Turtle
{
	public static void main(String[] argv)
	{
		TurtleGraphics tg1 = new TurtleGraphics();
		Scanner sc = new Scanner(System.in);

		String userCommand;

		System.out.println("TurtleGraphics Sketchpad");
		System.out.println("===========================================");
		System.out.println("Created by Marco.");
		System.out.println("Written in Java.");

		// enter an infinite loop for receiving user command.
		while(true)
		{
			System.out.print("\nTurtleGraphics > ");
			userCommand = sc.next();

			// parse user command.

			if(userCommand.equals("0"))               { tg1.moveForward(1); System.out.println("[*] You moved forward by 1 grid.");}
			else if(userCommand.equals("1"))          { tg1.setPenState(1); System.out.println("[*] Pen is up."); }
			else if(userCommand.equals("2"))          { tg1.setPenState(0); System.out.println("[*] Pen is down.");}
			else if(userCommand.equals("3"))          { tg1.turnRight(); System.out.println("[*] Turned Right."); }
			else if(userCommand.equals("4"))          { tg1.turnLeft(); System.out.println("[*] Turned Left."); }
			else if(userCommand.matches("^5,\\d+"))   { tg1.moveForward(Integer.parseInt(userCommand.split(",")[1])); }
			else if(userCommand.equals("6"))          { tg1.displayMap(); }
			else if(userCommand.equals("9"))          { System.exit(0); }
			else				   	                  { System.out.println("[-] Command not found."); }
		}

	}
}
