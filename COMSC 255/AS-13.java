//as13
//Richard Xie
//cs255

package as13;

public abstract class Employee 
{
	protected String name;
	protected double salary;
	
	public Employee(String name, double salary)
	{
		super();
		this.name = name;
		this.salary = salary;
	}
	
	public String getName() 
	{
		return name;
	}

	public double getSalary() 
	{
		return salary;
	}

	public abstract double computeBonus();
}

package as13;

import java.text.DecimalFormat;

public class Worker extends Employee
{
	private double pctBonus;

	public Worker(String name, double salary, double pctBonus) 
	{
		super(name, salary);
		this.pctBonus = pctBonus;	
	}
	
	public double getPctBonus() 
	{
		return pctBonus;
	}
	
	@Override
	public double computeBonus()
	{
		double bonus = salary * pctBonus;
		return bonus;
	}
}

package as13;

import java.text.DecimalFormat;

public class Manager extends Employee
{
	private double pctBonus;
	private double travelExpense;

	public Manager(String name, double salary, double pctBonus, double travelExpense) 
	{
		super(name, salary);
		this.pctBonus = pctBonus;
		this.travelExpense = travelExpense;
	}

	public double getPctBonus() 
	{
		return pctBonus;
	}
	
	public double getTravelExpense() 
	{
		return travelExpense;
	}
	
	@Override
	public double computeBonus()
	{
		double bonus = (salary * pctBonus) + 500.00;
		return bonus;
	}
}

package as13;

import java.text.DecimalFormat;

public class Executive extends Employee
{
	private double pctBonus;
	private double travelExpense;
	private int optionsCount;
	
	public Executive(String name, double salary, double pctBonus, double travelExpense, int optionsCount) 
	{
		super(name, salary);
		this.pctBonus = pctBonus;
		this.travelExpense = travelExpense;
		this.optionsCount = optionsCount;
	}

	public double getPctBonus() 
	{
		return pctBonus;
	}

	public double getTravelExpense() 
	{
		return travelExpense;
	}

	public int getOptionsCount() 
	{
		return optionsCount;
	}

	@Override
	public double computeBonus() 
	{
		double bonus = (salary * pctBonus) + 1000.00;
		return bonus;
	}
}

package as13;

import java.util.StringTokenizer;
import javax.swing.JOptionPane;
import java.text.*;

public class TestEmployee
{

	public static void main(String[] args) 
	{
		int n, nw, nm, ne;
		nw = 3; nm = 2;  ne = 1;
        n = nw + nm + ne;
        Employee[] emp = new Employee[n];
        int empIndex = 0;
        String in, delim = ",";
        StringTokenizer stk = null;
        String name;
        double salary, pctBonus, travelExpense;
        int optionsCount;
        
        for (int i = 0; i < nw; i++)
        {
        	in = JOptionPane.showInputDialog(null, "Enter Worker Data");
        	stk = new StringTokenizer(in, delim);
        	name = stk.nextToken().trim();
        	in = stk.nextToken().trim();
        	salary = Double.parseDouble(in);
        	in = stk.nextToken().trim();
        	pctBonus = Double.parseDouble(in);
        	emp[empIndex] = new Worker(name, salary, pctBonus);
        	empIndex++;
        }
        
        for (int i = 0; i < nm; i++)
        {
        	in = JOptionPane.showInputDialog(null, "Enter Manager Data");
        	stk = new StringTokenizer(in, delim);
        	name = stk.nextToken().trim();
        	in = stk.nextToken().trim();
        	salary = Double.parseDouble(in);
        	in = stk.nextToken().trim();
        	pctBonus = Double.parseDouble(in);
        	in = stk.nextToken().trim();
        	travelExpense = Double.parseDouble(in);
        	emp[empIndex] = new Manager(name, salary, pctBonus, travelExpense);
        	empIndex++;
        }
        
        for (int i = 0; i < ne; i++)
        {
        	in = JOptionPane.showInputDialog(null, "Enter Executive Data");
        	stk = new StringTokenizer(in, delim);
        	name = stk.nextToken().trim();
        	in = stk.nextToken().trim();
        	salary = Double.parseDouble(in);
        	in = stk.nextToken().trim();
        	pctBonus = Double.parseDouble(in);
        	in = stk.nextToken().trim();
        	travelExpense = Double.parseDouble(in);
        	in = stk.nextToken().trim();
        	optionsCount = Integer.parseInt(in);
        	emp[empIndex] = new Executive(name, salary, pctBonus, travelExpense, optionsCount);
        	empIndex++;
        }
        
        // polymorphic loop
        double bonus = 0;
        DecimalFormat df = new DecimalFormat (".00");
        df.format(bonus);
        String out = "";
        for (int i = 0; i < emp.length; i++)
        {
        	bonus = emp[i].computeBonus();
        	out = out + "\nName: " + emp[i].getName() + "\n";
        	out = out + "Salary: " + emp[i].getSalary() + "\n";
        	if (emp[i] instanceof Worker)
        	{
        		out = out + "Pct Bonus: " + ((Worker)emp[i]).getPctBonus() + "\n";
        		out = out + "Total Bonus: " + bonus + "\n";
        	}
        	
        	if (emp[i] instanceof Manager)
        	{
        		out = out + "Pct Bonus: " + ((Manager)emp[i]).getPctBonus() + "\n";
        		out = out + "Total Bonus: " + bonus + "\n";
        		out = out + "Travel Expense: " + ((Manager)emp[i]).getTravelExpense() + "\n";
        	}
        	
        	if (emp[i] instanceof Executive)
        	{
        		out = out + "Pct Bonus: " + ((Executive)emp[i]).getPctBonus() + "\n";
        		out = out + "Total Bonus: " + bonus + "\n";
        		out = out + "Travel Expense: " + ((Executive)emp[i]).getTravelExpense() + "\n";
        		out = out + "Options Count: " + ((Executive)emp[i]).getOptionsCount() + "\n";
        	}
        }// end of for loop
        JOptionPane.showMessageDialog(null, out);
	}
}
