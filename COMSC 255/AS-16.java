//as16
//Richard Xie
//cs255

package as16;

import javax.swing.JOptionPane;

public class Main
{
	public static void main(String[] args)
	{
		String in, out = "", msg, name;
		int count = 0, id;
		while(true)
		{
			in = JOptionPane.showInputDialog("Enter student count:");
			try
			{
				count = validateStudentCount(in);
				break;
			}
			catch(InputNotAWholeNumberException e)
			{
				msg = e.getMessage();
				e.printStackTrace();
			}
		}
		for(int i = 0; i < count; i++)
		{
			while(true)
			{	
				in = JOptionPane.showInputDialog("Enter student Id:");
				try
				{
					id = validateId(in);
					break;
				}

				catch (IdNotAWholeNumberException e)
				{
					msg = e.getMessage();
					e.printStackTrace();
				}
				catch (IdOutOfRangeException e)
				{
					msg = e.getMessage();
					e.printStackTrace();
				}
			}
			out = out + Integer.toString(id);
			
			while(true)
			{
				in = JOptionPane.showInputDialog("Enter student first name:");
				try
				{
					name = validateName(in);
					break;
				}
				catch (NotSpecifiedException e)
				{
					msg = e.getMessage();
					e.printStackTrace();
				}
				catch (NotAlphabeticException  e)
				{
					msg = e.getMessage();
					e.printStackTrace();
				}
			}
			out = out + " " + name + "\n";
		}
		JOptionPane.showMessageDialog(null, out);
	}
	
	private static int validateStudentCount(String sCount) throws InputNotAWholeNumberException
	{
		int count;
		try
		{
			count = Integer.parseInt(sCount);
		}
		catch(NumberFormatException ex)
		{
			throw new InputNotAWholeNumberException();
		}
		return count;
	}
	
	static int validateId(String sId) throws IdNotAWholeNumberException, IdOutOfRangeException
	{
		int id;
		try
		{
			id = Integer.parseInt(sId);
		}
		catch(NumberFormatException ex)
		{
			throw new IdNotAWholeNumberException();
		}
		if(id > 0 && id < 1000)
		{
			return id;
		}
		else
		{
			throw new IdOutOfRangeException();
		}
	}
	
	static String validateName(String sName) throws NotSpecifiedException, NotAlphabeticException
	{
		String name;
	    name = sName;
		
	    if (name.equals(""))
	    {
	        throw new NotSpecifiedException ();  
	    }
	    else if(!name.matches("[a-zA-Z]+"))
	    {
	        throw new NotAlphabeticException ();
	    }
	    else
	    {
	        return name;
	    }
	}
}
package as16;

public class IdNotAWholeNumberException extends Exception
{
	public IdNotAWholeNumberException()
	{
		super("Id Not A Whole Number");
	}
}

package as16;

public class IdOutOfRangeException extends Exception
{
	public IdOutOfRangeException()
	{
		super("Id Out of Range");
	}
}

package as16;

public class InputNotAWholeNumberException extends Exception
{
	public InputNotAWholeNumberException()
	{
		super("Input Not A Whole Number");
	}
}

package as16;

public class NotAlphabeticException extends RuntimeException
{
	public NotAlphabeticException ()
	  {
	    super ("Not Alphabetic");
	  }
}
package as16;

public class NotSpecifiedException extends RuntimeException
{
	public NotSpecifiedException ()
	  {
	    super ("Not Specified");
	  }
}
