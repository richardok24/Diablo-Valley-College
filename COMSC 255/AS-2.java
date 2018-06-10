//as2
//Richard Xie
//cs255

package as2;

import javax.swing.JOptionPane;

public class Rectangle 
{
	public static void main(String[] args) 
	{
		String in, out;
		in = JOptionPane.showInputDialog("Length: ");
		double len = Double.parseDouble(in);
		in = JOptionPane.showInputDialog("Width: ");
		double wid = Double.parseDouble(in);
		
		double a = computeArea(len, wid);
		double p = computePerim(len , wid);
		
		// building output
		out = "Length: " + len + "\n";
		out = out + "Width: " + wid + "\n";
		out = out + "Area: " + a + "\n";
		out = out + "Perimeter: " + p + "\n";
		
		// displaying output
		JOptionPane.showMessageDialog(null, out);
	}
	
	public static double computeArea (double len, double wid)
	{
		double area;
		area = len * wid;
		return area;
	}
	
	public static double computePerim (double len, double wid)
	{
		double perim;
		perim = (len + wid) * 2;
		return perim;
	}
}
