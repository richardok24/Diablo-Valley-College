//as3
//Richard Xie
//cs255

package as3;

import javax.swing.JOptionPane;

public class Rectangle 
{
	private double length;
	private double width;
	
	public Rectangle (double l, double w)
	{
		length = l;
		width = w;
	}
	
	public double compArea ()
	{
		double a;
		a = length * width;
		return a;
	}
	
	public double compPerim ()
	{
		double p;
		p = 2 * (length + width);
		return p;
	}
}

package as3;

import javax.swing.JOptionPane;

public class TestRectangle 
{
	public static void main(String[] args) 
	{
		String in, out;
		in = JOptionPane.showInputDialog("Enter length for the first rectangle: ");
		double len1 = Double.parseDouble(in);
		in = JOptionPane.showInputDialog("Enter width for the first rectangle: ");
		double wid1 = Double.parseDouble(in);
		in = JOptionPane.showInputDialog("Enter length for the second rectangle: ");
		double len2 = Double.parseDouble(in);
		in = JOptionPane.showInputDialog("Enter width for the second rectangle: ");
		double wid2 = Double.parseDouble(in);
		Rectangle rec1 = new Rectangle (len1, wid1);
		Rectangle rec2 = new Rectangle (len2, wid2);
		double area1 = rec1.compArea();
		double area2 = rec2.compArea();
		double perim1 = rec1.compPerim();
		double perim2 = rec2.compPerim();
	    
		// Building output
		out = "Values for the first object:\n";
		out = out + "Length: " + len1 + "\n";
		out = out + "Width: " + wid1 + "\n";
	      out = out + "Perimeter: " + perim1 + "\n";
		out = out + "Area: " + area1 + "\n" + "\n";
		out = out + "Values for the second object:\n";
		out = out + "Length: " + len2 + "\n";
		out = out + "Width: " + wid2 + "\n";
	      out = out + "Perimeter: " + perim2 + "\n";
		out = out + "Area: " + area2 + "\n";
		JOptionPane.showMessageDialog(null, out);
	}
}
