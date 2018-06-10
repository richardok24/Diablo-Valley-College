//as11
//Richard Xie
//cs255
package as11;

public interface Status 
{
	public String getStatus ( );
	public void displayStatus ( );
}

package as11;

import javax.swing.JOptionPane;

public class Rectangle implements Status
{
	private double length;
	private double width;
	
	public Rectangle(double l, double w) 
	{
		length = l;
		width = w;
	}
	
	@Override
	public String getStatus() 
	{
		String status = "Rectangle\n";
		status = status + "Length= " + length + ", Width= " + width + "\n";
		return status;
	}

	@Override
	public void displayStatus() 
	{
		String status = getStatus();
		JOptionPane.showMessageDialog(null, status);
	}
}

package as11;

import javax.swing.JOptionPane;

public class Sibling implements Status
{
	private String name;
	private int age;
	private int weight;
	
	public Sibling(String name, int age, int weight) 
	{
		super();
		this.name = name;
		this.age = age;
		this.weight= weight;
	}
	
	@Override
	public String getStatus() 
	{
		String status = "Sibling\n";
		status = status + "name= " + name + ", age= " + age + ", weight= " + weight + "\n";
		return status;
	}

	@Override
	public void displayStatus() 
	{
		String status = getStatus();
		JOptionPane.showMessageDialog(null, status);
	}
}

package as11;

import javax.swing.JOptionPane;

public class Student implements Status
{
	private int id;
	private String name;
	private int[] scores;
	
	public Student(int id, String name, int[] scores)
	{
		super();
		this.id = id;
		this.name = name;
		this.scores = scores;
	}
	
	@Override
	public String getStatus() 
	{
		String status = "Student\n";
		status = status + "id= " + id + ", name= " + name + ", scores= "; 
		for (int i = 0; i < scores.length; i++)
		{
			status = status + scores[i] + ", ";
		}
		status = status + "\n";
		return status;
	}

	@Override
	public void displayStatus() 
	{
		String status = getStatus();
		JOptionPane.showMessageDialog(null, status);
	}
}

package as11;

import javax.swing.JOptionPane;

public class TestStatus 
{
	public static void main(String[] args) 
	{
		String in, out;
		Status[] stat = new Status[6];
		int statIndex = 0;
		// create three Rectangle objects
		for (int i = 0; i < 3; i++)
		{
			in = JOptionPane.showInputDialog("Enter length: ");
			double length = Double.parseDouble(in);
			in = JOptionPane.showInputDialog("Enter width: ");
			double width = Double.parseDouble(in);
			stat [statIndex] = new Rectangle(length, width);
			statIndex++;
		}
		
		for (int i = 0; i < 2; i++)
		{
			in = JOptionPane.showInputDialog("Enter name: ");
			String name = in;
			in = JOptionPane.showInputDialog("Enter age: ");
			int age = Integer.parseInt(in);
			in = JOptionPane.showInputDialog("Enter weight: ");
			int weight = Integer.parseInt(in);
			stat [statIndex] = new Sibling(name, age, weight);
			statIndex++;
		}
		
		for (int i = 0; i < 1; i++)
		{
			in = JOptionPane.showInputDialog("Enter id: ");
			int id = Integer.parseInt(in);
			in = JOptionPane.showInputDialog("Enter name: ");
			String name = in;
			in = JOptionPane.showInputDialog("Enter score count: ");
			int scoreCount = Integer.parseInt(in);
			int[] scores = new int[scoreCount];
			for (int j = 0; j < scores.length; j++)
			{
				in = JOptionPane.showInputDialog("Enter score: ");
				scores[j] = Integer.parseInt(in);
			}
			stat [statIndex] = new Student(id, name, scores);
			statIndex++;
		}
		
		// polymorphic loop
		for (int i = 0; i < 6; i++)
		{
			stat[i].displayStatus();
		}
		out = "";
		for (int i = 0; i < 6; i++)
		{
			out = out + stat[i].getStatus();
		}
		JOptionPane.showMessageDialog(null, out);
	}
}
