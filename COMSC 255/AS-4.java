//as4
//Richard Xie
//cs255

package as4;

public class Sibling 
{
	private String name;
	private int age;
	private int weight;
	
	public Sibling (String n, int a, int w)
	{
		name = n;
		age = a;
		weight = w;
	}

	public String getName() 
	{
		return name;
	}

	public int getAge() 
	{
		return age;
	}

	public int getWeight() 
	{
		return weight;
	}
}

package as4;

import javax.swing.JOptionPane;

public class TestSibling 
{

	public static void main(String[] args) 
	{
        String name, in, out;
	  int age, weight;
	  name = JOptionPane.showInputDialog("Enter first sibling's name");
	  in = JOptionPane.showInputDialog("Enter first sibling's age");
        age = Integer.parseInt(in);
        in = JOptionPane.showInputDialog("Enter first sibling's weight");
        weight = Integer.parseInt(in);
        Sibling sib1 = new Sibling (name, age, weight);
        
        name = JOptionPane.showInputDialog("Enter second sibling's name");
	  in = JOptionPane.showInputDialog("Enter second sibling's age");
        age = Integer.parseInt(in);
        in = JOptionPane.showInputDialog("Enter second sibling's weight");
        weight = Integer.parseInt(in);
        Sibling sib2 = new Sibling (name, age, weight);
        
        name = JOptionPane.showInputDialog("Enter third sibling's name");
	  in = JOptionPane.showInputDialog("Enter third sibling's age");
        age = Integer.parseInt(in);
        in = JOptionPane.showInputDialog("Enter third sibling's weight");
        weight = Integer.parseInt(in);
        Sibling sib3 = new Sibling (name, age, weight);
        
        // determine lightest
        Sibling lightest, youngest;
        if (sib1.getWeight() <= sib2.getWeight() && sib1.getWeight() <= sib3.getWeight())
        {
        	lightest = sib1;
        }
        
        else if (sib2.getWeight() <= sib1.getWeight() && sib2.getWeight() <= sib3.getWeight())
        {
        	lightest = sib2;
        }
        
        else
        {
        	lightest = sib3;
        }
        
        // determine youngest
        if (sib1.getAge() <= sib2.getAge() && sib1.getAge() <= sib3.getAge())
        {
        	youngest = sib1;
        }
        
        else if (sib2.getAge() <= sib1.getAge() && sib2.getAge() <= sib3.getAge())
        {
        	youngest = sib2;
        }
        
        else
        {
        	youngest = sib3;
        }
        
        // build output
        out = "The lightest sibling: " + lightest.getName() + " " + lightest.getAge() + " " + lightest.getWeight() + "\n";
        out = out + "The youngest sibling: " + youngest.getName() + " " + youngest.getAge() + " " + youngest.getWeight() + "\n";
        JOptionPane.showMessageDialog(null, out);
	}
}
