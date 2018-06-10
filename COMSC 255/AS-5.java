//as5
//Richard Xie
//cs255

package as5;

import java.util.Arrays;

import javax.swing.JOptionPane;

public class Statistics 
{
	private double[] data;
	private double[] sdata;
	
    public Statistics (double[] d)
    {
    	data = d.clone();
    	sdata = d.clone();
    	Arrays.sort(sdata);
    	//int len = data.length;
    	//JOptionPane.showMessageDialog(null, len);
    }
    
    public double findMin()
    {
    	return sdata[0];
    }
    
    public double findMax()
    {
    	return sdata[sdata.length - 1];
    }
}
package as5;

import javax.swing.JOptionPane;

public class TestStatistics 
{
	public static void main(String[] args) 
	{
		String in, out;
		int dataSize;
		
		// input data
		in = JOptionPane.showInputDialog("Enter data size: ");
		dataSize = Integer.parseInt(in);
		
		// create an array
		double[] x = new double [dataSize];
		
		// fill the array
		for (int i = 0; i < dataSize; i++)
		{
			in = JOptionPane.showInputDialog("Enter data element: ");
			x[i] = Double.parseDouble(in);
		}
		
		Statistics stat = new Statistics(x);
		double min = stat.findMin();
		double max = stat.findMax();
		out = "Min: " + min + "\n";
		out = out + "Max: " + max + "\n";
		JOptionPane.showMessageDialog(null, out);
	}
}
