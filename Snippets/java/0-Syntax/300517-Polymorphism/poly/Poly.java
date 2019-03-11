class Person
{
    String name;

    public Person()
    {
        this("John");
    }

    public Person(String n)
    {
        name = n;
    }
}

interface Action
{
    public void act();
}

class Run implements Action
{
    public void act()
    {
        System.out.println("Running!");
    }
}

class Walk implements Action
{
    public void act()
    {
        System.out.println("Walking!");
    }
}

class ActionTaker
{
    Action action;

    public ActionTaker() {}
    public ActionTaker(Action action)
    {
        this.action = action;
    }

    public void act()
    {
        action.act();
    }
}


public class Poly
{
    public static void main(String[] args)
    {
        ActionTaker a;
        
        a = new ActionTaker(new Run());
        a.act();

        a = new ActionTaker(new Walk());
        a.act();
    }
}
