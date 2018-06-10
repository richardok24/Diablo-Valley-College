//as10
//Richard Xie
//cs255

package as10;

public class Day
{
	private int day;
    protected int month;
    
    public Day (int d, int m)
    {   
    	day = d;
    	month = m;
    }
    
    public int getDay()
    {
    	return day;     
    }
    
    public int getMonth()
    {
    	return month;   
    }
    
    public int getDayNum()
    {
    	int dayNum=0;  
        for(int i = 1; i < month; i++)
        {
        	if(i == 4 || i == 6 || i == 9 || i == 11)
        		dayNum = dayNum + 30;
            else if (i==2)
                dayNum = dayNum + 28;
            else
                dayNum = dayNum + 31;
        }
        dayNum = dayNum + day;
        return dayNum;
    }
}

package as10;

import javax.swing.*;

public class TestDay
{
	public static void main(String[] args)
	{
		String in, out;
        int day, month;
        in = JOptionPane.showInputDialog("Enter day");
        day = Integer.parseInt(in);
        in = JOptionPane.showInputDialog("Enter month");
        month = Integer.parseInt(in);
        Day date = new Day (day, month);
        out = "Day Number for " + date.getMonth() + "/" + date.getDay() + " is " + date.getDayNum();     
        JOptionPane.showMessageDialog(null,out);
	}
}
