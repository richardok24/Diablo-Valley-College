//as9
//Richard Xie
//cs255

package as9;

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

package as9;

public class StudentExt extends Student 
{
	private String gradeType;

	public StudentExt(int id, String n, int[] s, String gt) 
	{
		super(id, n, s);
		gradeType = gt;
	}

	@Override
	public String findGrade() 
	{
		String grade = super.findGrade();
		if (gradeType.equalsIgnoreCase("Credit"))
		{
			if (grade.equalsIgnoreCase("A")||
				grade.equalsIgnoreCase("B")||
				grade.equalsIgnoreCase("C"))
			{
				grade = "CR";
			}
			else
			{
				grade = "NCR";
			}
		}
		return grade;
	}

	public String getGradeType() 
	{
		return gradeType;
	}
}








package as9;

import java.util.StringTokenizer;

import javax.swing.JOptionPane;

public class TestStudentExt 
{
	public static void main(String[] args) 
	{
		String in, out, name = null, gradeType = null;
		int id = 0, examCount;
		int[] examScores = null;
		in = JOptionPane.showInputDialog("Enter student count:");
		int stCount = Integer.parseInt(in);
		
		// create student array of references
		StudentExt[] ste = new StudentExt[stCount];
		
		// populate the array of references
		for (int i = 0; i < ste.length; i++)
		{
			in = JOptionPane.showInputDialog("Enter student data:");
			StringTokenizer stk = new StringTokenizer(in, ",");
			// input id, name, scores, grade type
			in = stk.nextToken().trim();
			//in = JOptionPane.showInputDialog("Enter id:");
			id = Integer.parseInt(in);
			//name = JOptionPane.showInputDialog("Enter name:");
			name = stk.nextToken().trim();
			//in = JOptionPane.showInputDialog("Enter examCount:");
			in = stk.nextToken().trim();
			examCount = Integer.parseInt(in);
			examScores = new int[examCount];
			for (int j = 0; j < examScores.length; j++)
			{
				//in = JOptionPane.showInputDialog("Enter score:");
				in = stk.nextToken().trim();
				examScores[j] = Integer.parseInt(in);
			}
			//in = JOptionPane.showInputDialog("Enter grade type:");
			gradeType = stk.nextToken().trim();
			ste[i] = new StudentExt(id, name, examScores, gradeType);
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
			else if (grade.equalsIgnoreCase("F"))
			{
				outF = outF + ste[i].getId() + " " +  ste[i].getName() + " " + "(" + grade + ")\n";
			}
			else if (grade.equalsIgnoreCase("CR"))
			{
				outCR = outCR + ste[i].getId() + " " +  ste[i].getName() + " " + "(" + grade + ")\n";
			}
			else
			{
				outNCR = outNCR + ste[i].getId() + " " +  ste[i].getName() + " " + "(" + grade + ")\n";
			}
		}
		outAll = outA + outB + outC + outD + outF + outCR +outNCR;
		JOptionPane.showMessageDialog(null, outAll);
	}
}
