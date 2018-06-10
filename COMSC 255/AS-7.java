//as7
//Richard Xie
//cs255

package as7;

public class Student 
{
	private int id;
	private String name;
	private int[] scores;
	
	public Student (int id, String n, int[] s)
	{
		this.id = id;
		name = n;
		scores = s.clone();
	}
	
	public String findGrade()
	{
		String grade = null;
		double sum = 0;
		for (int i = 0; i < scores.length; i++)
		{
			sum = sum + scores[i];
		}
		double avg = sum / scores.length;
		if (avg >= 90.0)
		{
			grade = "A";
		}
		else if (avg >= 80.0)
		{
			grade = "B";
		}
		else if (avg >= 70.0)
		{
			grade = "C";
		}
		else if (avg >= 60.0)
		{
			grade = "D";
		}
		else
		{
			grade = "F";
		}
		return grade;
	}

	public int getId() 
	{
		return id;
	}

	public String getName() 
	{
		return name;
	}
}

package as7;

import java.util.StringTokenizer;

import javax.swing.JOptionPane;

public class TestStudent
{
	public static void main(String[] args) 
	{
		String in, out, name = null;
		int id = 0, examCount;
		int[] examScores = null;
		in = JOptionPane.showInputDialog("Enter student count:");
		int stCount = Integer.parseInt(in);
		
		// create student array of references
		Student[] ste = new Student[stCount];
		
		// populate the array of references
		for (int i = 0; i < ste.length; i++)
		{
			in = JOptionPane.showInputDialog("Enter student data:");
			StringTokenizer stk = new StringTokenizer(in, ",");
			
			// input id, name, scores, grade type
			in = stk.nextToken().trim();
			id = Integer.parseInt(in);
			name = stk.nextToken().trim();
			in = stk.nextToken().trim();
			examCount = Integer.parseInt(in);
			examScores = new int[examCount];
			for (int j = 0; j < examScores.length; j++)
			{
				in = stk.nextToken().trim();
				examScores[j] = Integer.parseInt(in);
			}
			ste[i] = new Student(id, name, examScores);
		}
		
		// build output
		String outA = "", outB = "", outC = "", outD = "", outF = "", outCR = "", outNCR = "", outAll = "";
		for (int i = 0; i < ste.length; i++)
		{
			String grade = ste[i].findGrade();
			if (grade.equalsIgnoreCase("A"))
			{
				outA = outA + ste[i].getId() + " " +  ste[i].getName() + " " + "(" + grade + ")\n";
			}
			else if (grade.equalsIgnoreCase("B"))
			{
				outB = outB + ste[i].getId() + " " +  ste[i].getName() + " " + "(" + grade + ")\n";
			}
			else if (grade.equalsIgnoreCase("C"))
			{
				outC = outC + ste[i].getId() + " " +  ste[i].getName() + " " + "(" + grade + ")\n";
			}
			else if (grade.equalsIgnoreCase("D"))
			{
				outD = outD + ste[i].getId() + " " +  ste[i].getName() + " " + "(" + grade + ")\n";
			}
			else
			{
				outF = outF + ste[i].getId() + " " +  ste[i].getName() + " " + "(" + grade + ")\n";
			}
		}
		outAll = outA + outB + outC + outD + outF + outCR +outNCR;
		JOptionPane.showMessageDialog(null, outAll);
	}
}
