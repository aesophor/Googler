class Date
{
    private int day;
    private int month;
    private int year;
    
    public Date() {}
    public Date(String dateString)
    {
        String[] parts = dateString.split("[/]");
        day   = Integer.parseInt(parts[0]);
        month = Integer.parseInt(parts[1]);
        year  = Integer.parseInt(parts[2]);
    }

    public int getDay()   { return day; }
    public int getMonth() { return month; }
    public int getYear()  { return year; }

    public boolean isEarlier(Date d)
    {
        if(getYear() < d.getYear())
        {
            if(getMonth() < d.getMonth())
            {
                if(getDay() < d.getDay())
                {
                    return true;
                }
            }
        }
        return false;
    }
    
    public Date getDate()
    {
        return this;
    }

    @Override
    public String toString()
    {
        String output = "";
        output += Integer.toString(day) + "/";
        output += Integer.toString(month) + "/";
        output += Integer.toString(year);
        return output;
    }
}

public class Quiz
{
    public static void main(String[] args)
    {
        Date d1 = new Date("9/21/2012");
        Date d2 = new Date("10/1/2001");
        System.out.println(d1.getDate() + (d1.isEarlier(d2) ? " is earlier than " : " is later than ") + d2.getDate());
    }
}
