import java.util.Scanner;

/* TimeFormatter class.
 * Print current time in custom format.
 */

class Year
{
    private int year;

    public Year()
    {
        this(1960);
    }

    public Year(int year)
    {
        this.year = year;
    }

    public int  getYear() { return year; }
    public void setYear(int year) { this.year = year; }
}

class Month
{
    private int month;

    public Month()
    {
        this(1);
    }

    public Month(int month)
    {
        this.month = month;
    }

    public int  getMonth() { return month; }
    public void setMonth(int month) { this.month = month; }
}

class Date
{
    private int date;

    public Date()
    {
        this(1);
    }

    public Date(int date)
    {
        this.date = date;
    }

    public int  getDate() { return date; }
    public void setDate(int date) { this.date = date; }
}

class Time
{
    private Year year;
    private Month month;
    private Date date;
    private String format;

    public Time(Year year, Month month, Date date)
    {
        this.year  = year;
        this.month = month;
        this.date  = date;

        // the output format is YearMonthDate by default.
        format = "YYMMDD";
    }

    public Time setFormat(String format)
    {
        this.format = format;
        return this;
    }

    @Override
    public String toString()
    {
        switch(format)
        {
            case "YYMMDD":
                return Integer.toString(year.getYear()) + "/" + Integer.toString(month.getMonth()) + "/" + Integer.toString(date.getDate());
            case "MMDDYY":
                return Integer.toString(month.getMonth()) + "/" + Integer.toString(date.getDate()) + "/" + Integer.toString(year.getYear());
            case "DDMMYY":
                return Integer.toString(date.getDate()) + "/" + Integer.toString(month.getMonth()) + "/" + Integer.toString(year.getYear());
            default:
                return "";
        }
    }
}


interface Format
{
    Time format(Time t);
}

class YearMonthDate implements Format
{
    public Time format(Time t)
    {
        return t.setFormat("YYMMDD");
    }
}

class MonthDateYear implements Format
{
    public Time format(Time t)
    {
        return t.setFormat("MMDDYY");
    }
}

class DateMonthYear implements Format
{
    public Time format(Time t)
    {
        return t.setFormat("DDMMYY");
    }
}

class Formatter
{
    private Time t;
    public  Format formatAct;

    // default constructor.
    public Formatter() {}

    // overloaded constructor.
    public Formatter(Time t, Format formatAct)
    {
        this.t = t;
        this.formatAct = formatAct;
    }

    public Time format()
    {
        return formatAct.format(t);
    }

    public Time getTime() { return t; }
}


public class TimeFormatter
{
    public static void main(String[] args)
    {
        Formatter f;

        f = new Formatter(new Time(new Year(1983), new Month(3), new Date(5)), new YearMonthDate());
        System.out.println("[*] Output in YYMMDD: " + f.format());

        f = new Formatter(new Time(new Year(1983), new Month(3), new Date(5)), new MonthDateYear());
        System.out.println("[*] Output in MMDDYY: " + f.format());

        f = new Formatter(new Time(new Year(1983), new Month(3), new Date(5)), new DateMonthYear());
        System.out.println("[*] Output in DDMMYY: " + f.format());
    }
}
