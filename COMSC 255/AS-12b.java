//as12b
//Richard Xie
//cs255

package as12b;

import javax.swing.JFrame;

public class Main
{
	public static void main(String[] args)
	{
		JFrameExt f = new JFrameExt(20,25,15,30,10);
		f.setSize(600,300);
		f.setVisible(true);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}

package as12b;

import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class JFrameExt extends JFrame implements ActionListener
{
	private JPanel jpMain = new JPanel();
	private JPanel jp1 = new JPanel();
	private JPanel jp2 = new JPanel();
	private JPanel jp3 = new JPanel();
	private JLabel jlbFrom = new JLabel("From");
	private JLabel jlbTo = new JLabel("To");
	private JTextField jtfFrom = new JTextField(10);
	private JTextField jtfTo = new JTextField(10);
	private JButton jbtFtoC = new JButton("FtoC");
	private JButton jbtCtoF = new JButton("CtoF");
	JButton jbtClear = new JButton ("Clear");

	public JFrameExt(double north,double south,double east,double west,double midwest)
	{
		super();
	    this.setTitle("converter");
		jpMain.setBackground(Color.yellow);
		this.setContentPane(jpMain);
		jp1.setBackground(Color.red);
		jp2.setBackground(Color.green);
		jp3.setBackground(Color.magenta);
		GridLayout gl = new GridLayout(3,1);
		jpMain.setLayout(gl);
		jpMain.add(jp1);
		jpMain.add(jp2);
		jpMain.add(jp3);
		jp1.add(jlbFrom);
		jp1.add(jtfFrom);
		jp2.add(jlbTo);
		jp2.add(jtfTo);
		jtfTo.setEditable(false);
		jp3.add(jbtFtoC);
		jp3.add(jbtCtoF);
		jp3.add(jbtClear);

		//register yourself as a listener with button
		jbtFtoC.addActionListener(this);
		jbtCtoF.addActionListener(this);
		jbtClear.addActionListener(this);
	}

	@Override
	public void actionPerformed(ActionEvent e)
	{
		if (e.getSource() == jbtClear)
		{
			String sFrom = jtfFrom.getText().trim();
			jtfFrom.setText("");
			jtfTo.setText(" ");
			return;
	    }
		else if (e.getSource()==jbtFtoC)
		{
			String sFrom = jtfFrom.getText().trim();
			double f = Double.parseDouble(sFrom);
			double c = 5.0/9.0 * (f - 32.0);
			jtfTo.setText(""+c);
	    }
		else if (e.getSource()==jbtCtoF)
		{
			String sFrom = jtfFrom.getText().trim();
			double c = Double.parseDouble(sFrom);
			double f = (9.0/5.0 *c) + 32.0;
			jtfTo.setText(""+f);
		}
	}
}
