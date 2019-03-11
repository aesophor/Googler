interface StackInterface
{
    boolean isEmpty();
    boolean push(String d);
    String  pop();
}


class Stack implements StackInterface
{
    private String[] stack;
    private int      top;


    // default constructor.
    public Stack()
    {
        // create a stack with the size of 30.
        this(30);
    }

    // overrided constructor.
    public Stack(int size)
    {
        // create a stack with user specified size.
        stack = new String[size];
        top = -1;
    }

    // overrided constructor.
    // the following constructor will create a stack with user-defined type.
    public Stack(String stackType)
    {
        switch(stackType)
        {
            case "int":

        }
    }


    // the method to add an item to the top of the stack.
    public boolean push(String d)
    {
        if (top >= stack.length)
        {
            return false;
        }

        else
        {
            stack[++top] = d;
            return true;
        }
    }

    // the method to retrieve an item from the top of the stack.
    public String pop() { return isEmpty() ? "" : stack[top--]; }

    // the method to check if the stack is empty.
    public boolean isEmpty() { return top == -1 ? true : false; }
}
