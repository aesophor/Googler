class Apple
{
    @Override
    public String toString()
    {
        return "apple";
    }
}

public class Diner
{
    public Apple peel(Apple apple)
    {
        System.out.println("Apple is peeled.");
        return apple;
    }

    public void eat(Apple apple)
    {
        System.out.println(apple + " eaten. It is delicious!");
    }

    public static void main(String[] args)
    {
        Diner diner1 = new Diner();
        diner1.eat(diner1.peel(new Apple()));
    }
}
