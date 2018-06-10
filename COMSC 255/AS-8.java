//as8
//Richard Xie
//cs255

package as8;

public class Sibling extends Object
{
private String name;
    private int age;
    private int weight;
    public Sibling(String n, int a, int w)
    {
    	super();
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

package as8;

public class SiblingExt extends Sibling
{
    private int height;
    public SiblingExt (String n, int a, int w, int h)
    {
    	super(n, a, w);
    	height = h;
    }
    
	public int getHeight() 
	{
		return height;
	}
}



package as8;

import javax.swing.JOptionPane;

public class TestSibling 
{
	public static void main(String[] args) 
	{
		// input siblingext data and create siblings
		String name, in, out;
		int age, weight, height;
		name = JOptionPane.showInputDialog("Enter name:");
		in = JOptionPane.showInputDialog("Enter age:");
		age = Integer.parseInt(in);
		in = JOptionPane.showInputDialog("Enter weight:");
		weight = Integer.parseInt(in);
		in = JOptionPane.showInputDialog("Enter height:");
		height = Integer.parseInt(in);
		SiblingExt sibe1 = new SiblingExt(name, age, weight, height);
		
		name = JOptionPane.showInputDialog("Enter name:");
		in = JOptionPane.showInputDialog("Enter age:");
		age = Integer.parseInt(in);
		in = JOptionPane.showInputDialog("Enter weight:");
		weight = Integer.parseInt(in);
		in = JOptionPane.showInputDialog("Enter height:");
		height = Integer.parseInt(in);
		SiblingExt sibe2 = new SiblingExt(name, age, weight, height);
		
		name = JOptionPane.showInputDialog("Enter name:");
		in = JOptionPane.showInputDialog("Enter age:");
		age = Integer.parseInt(in);
		in = JOptionPane.showInputDialog("Enter weight:");
		weight = Integer.parseInt(in);
		in = JOptionPane.showInputDialog("Enter height:");
		height = Integer.parseInt(in);
		SiblingExt sibe3 = new SiblingExt(name, age, weight, height);
		
		SiblingExt youngest, lightest, tallest;
		// find the youngest
		if (sibe1.getAge() < sibe2.getAge() && sibe1.getAge() < sibe3.getAge())
        {
        	youngest = sibe1;
		}
        else if (sibe2.getAge() < sibe1.getAge() && sibe2.getAge() < sibe3.getAge())
        {
        	youngest = sibe2;
		}
        else
        {
        	youngest = sibe3;
        }
        
        // find the lightest
        if (sibe1.getWeight() < sibe2.getWeight() && sibe1.getWeight() < sibe3.getWeight())
        {
        	lightest = sibe1;
        }
        else if (sibe2.getWeight() < sibe1.getWeight() && sibe2.getWeight() < sibe3.getWeight())
        {
        	lightest = sibe2;
     	}
        else
        {
        	lightest = sibe3;
        }
        
        // find the tallest
        if (sibe1.getHeight() > sibe2.getHeight() && sibe1.getHeight() > sibe3.getHeight())
        {
        	tallest = sibe1;
        }
        else if (sibe2.getHeight() > sibe1.getHeight() && sibe2.getHeight() > sibe3.getHeight())
        {
        	tallest = sibe2;
     	}
        else
        {
        	tallest = sibe3;
        }
        
        //build output
      	out = "";
      	out += "The lightest sibling: " + lightest.getName() +" "+ lightest.getAge()+" "+lightest.getWeight()+" "+ lightest.getHeight() + "\n";
      	out += "The youngest sibling: " + youngest.getName()+" "+ youngest.getAge()+" "+youngest.getWeight()+" "+ youngest.getHeight() + "\n";
      	out += "The tallest sibling: " + tallest.getName()+" "+ tallest.getAge()+" "+tallest.getWeight()+" "+ tallest.getHeight() + "\n";
      	JOptionPane.showMessageDialog(null, out);
	}
}
