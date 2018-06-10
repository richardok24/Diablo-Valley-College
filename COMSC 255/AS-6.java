//as6
//Richard Xie
//cs255

package as6;

import java.util.Arrays;

public class Statistics 
{
	private double[] data;
	private double[] sdata;
	public static int count = 0;
	
	public Statistics (double[] d)
	{
		Statistics.count++;
		data = d.clone();
		sdata = d.clone();
		Arrays.sort(sdata);
	}
	
	public double[] getOriginalData() 
    { 
        double [] temp = new double[data.length]; 
        System.arraycopy(data,0,temp,0,data.length);
        return temp; 
    } 

	public double[] getSortedData()
	{
	    double [] d = new double[sdata.length];
	    System.arraycopy (sdata,0,d,0,sdata.length);
	    return d;
	}
	
	public static double[] computeSortedData(double[] d)
    {
		Statistics stat = new Statistics(d);
        return stat.getSortedData();
    };

	
	public double findMin()
	{
		return sdata[0];
	}
	
	public static double compMin(double[] d)
	{
		Statistics stat = new Statistics(d);
		double min = stat.findMin();
		return min;
	}
	
	public double findMax()
	{
		return sdata[sdata.length-1];
	}
	
	public static double compMax(double[] d)
	{
		Statistics stat = new Statistics(d);
		double max = stat.findMax();
		return max;
	}
	
	public double findMean()
	{
	    double sum = 0;
		for (int i = 0;i < sdata.length;i++)
		{
			sum = sum + sdata[i];
		}
		double mean = sum / sdata.length;
		return mean;
	}
	
	public static double compMean(double[] d)
	{
		Statistics stat = new Statistics(d);
		double mean = stat.findMean();
		return mean;
	}
	
	public double findMedian ( )
	{
	    //Declare variables
	    int index, indexHi, indexLo;
	    double median;
	    //Determine if the length is odd or even.
	    if ( (sdata.length %2) != 0 )
	    {
	        index = sdata.length / 2;
	        median = sdata [index];
	    }
	    else
	    {
	        indexHi = sdata.length / 2;
	        indexLo = indexHi - 1;
	        median = (sdata[indexLo] + sdata[indexHi] ) / 2;
	    }
	    return median;
	}
	
	public static double compMedian(double[] d)
	{
		Statistics stat = new Statistics(d);
		double median = stat.findMedian();
		return median;
	}
}

package as6;

import java.util.StringTokenizer;

import javax.swing.JOptionPane;

import java.text.*;

public class TestStatistics 
{
	public static void main(String[] args) 
	{
		String in, out;
		// input all data
		in = JOptionPane.showInputDialog("Enter All Data <separated by commas/spaces>:");
		String delim = ",";
		// give them to tokenizer
		StringTokenizer stk = new StringTokenizer(in, delim);
		// get data size from tokenizer
		int size = stk.countTokens();
		// create array
		double[] x = new double[size];
		// fill up the array
		for (int i = 0; i < x.length; i++)
		{
			String token = stk.nextToken().trim();
			x[i] = Double.parseDouble(token);
		}
		in = JOptionPane.showInputDialog("Enter the Number of Places For Decimal Output;");
		int placesCount = Integer.parseInt (in);

		// create statistics object
		Statistics stat = new Statistics(x);
		double [] originalData = stat.getOriginalData(); 
	    double [] sortedData = stat.getSortedData(); 
	    double [] sortedData2 = Statistics.computeSortedData(x);
		double min = stat.findMin();
		double max = stat.findMax();
		double mean = stat.findMean();
		double median = stat.findMedian();
		double min2 = Statistics.compMin(x);
		double max2 = Statistics.compMax(x);
		double mean2 = Statistics.compMean(x);
		double median2 = Statistics.compMedian(x);
		String pattern = ".";
	    for(int i = 0; i < placesCount; i++)
		    pattern = pattern + "0";
		DecimalFormat df = new DecimalFormat(pattern);

		// build output
		out = "Original Data:" + "\n";
		for (int i=0; i<originalData.length; i++)
	    {
	        out = out + originalData[i] + " ";
	    }
		out = out + "\n\nResults Using Instance Methods:" + "\n\n";
		out = out + "Sorted Data:" + "\n";
		for (int i=0; i<sortedData.length; i++)
		{
		    out = out + sortedData[i] + " ";
		}
		out = out + "\n\nComputed Values:" + "\n";
		out = out + "Min: " + df.format(min) + "\n";
		out = out + "Max: " + df.format(max) + "\n";
		out = out + "Mean: " + df.format(mean) + "\n";
		out = out + "Median: " + df.format(median) + "\n";
		out = out + "\nResults Using Static Methods:" + "\n\n";
		out = out + "Sorted Data:" + "\n";
		for (int i=0; i<sortedData.length; i++)
		{
		    out = out + sortedData2[i] + " ";
		}
		out = out + "\n\nComputed Values:" + "\n";
		out = out + "Min: " + df.format(min2) + "\n";
		out = out + "Max: " + df.format(max2) + "\n";
		out = out + "Mean: " + df.format(mean2) + "\n";
		out = out + "Median: " + df.format(median2) + "\n";
		out = out + "\nThe Total Number of Statistics objects created during execution:"+ stat.count;
		// display output
		JOptionPane.showMessageDialog(null, out);
	}
}
