//as12
//Richard Xie
//cs255
package calc;

import javax.swing.JFrame;

public class Main 
{
	public static void main(String[] args) 
	{
		JFrameExt f = new JFrameExt();
		f.setSize(600,300);
		f.setVisible(true);
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
}

package calc;

import java.awt.Color;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class JFrameExt extends JFrame implements ActionListener
{
	JPanel jpMain = new JPanel();
	JPanel jp1 = new JPanel();
	JPanel jp2 = new JPanel();
	JPanel jp3 = new JPanel();
	JPanel jp4 = new JPanel();
	
	JLabel jlbNum1 = new JLabel("Num1");
	JTextField jtfNum1 = new JTextField(10);
	JLabel jlbNum2 = new JLabel("Num2");
	JTextField jtfNum2 = new JTextField(10);
	JLabel jlbRes = new JLabel("Res ");
	JTextField jtfRes = new JTextField(10);
	
	JButton jbtAdd = new JButton("Add");
	JButton jbtSub = new JButton("Sub");
	JButton jbtMult = new JButton("Mult");
	JButton jbtDiv = new JButton("Div");
	JButton jbtClear = new JButton("Clear");
	
	public JFrameExt()
	{
		this.setContentPane(jpMain);
		jpMain.setBackground(Color.yellow);
		GridLayout gl = new GridLayout(4,1);
		jpMain.setLayout(gl);
		jpMain.add(jp1);
		jpMain.add(jp2);
		jpMain.add(jp3);
		jpMain.add(jp4);
		jp1.setBackground(Color.red);
		jp2.setBackground(Color.green);
		jp3.setBackground(Color.cyan);
		jp4.setBackground(Color.magenta);
		jp1.add(jlbNum1);
		jp1.add(jtfNum1);
		jp2.add(jlbNum2);
		jp2.add(jtfNum2);
		jp3.add(jlbRes);
		jp3.add(jtfRes);
		jp4.add(jbtAdd);
		jp4.add(jbtSub);
		jp4.add(jbtMult);
		jp4.add(jbtDiv);
		jp4.add(jbtClear);
		
		// register with buttons
		jbtAdd.addActionListener(this);
		jbtSub.addActionListener(this);
		jbtMult.addActionListener(this);
		jbtDiv.addActionListener(this);
		jbtClear.addActionListener(this);
	}
	
	@Override
	public void actionPerformed(ActionEvent ev) 
	{
		String snum1 = jtfNum1.getText().trim();
		String snum2 = jtfNum2.getText().trim();
		double num1 = Double.parseDouble(snum1);
		double num2 = Double.parseDouble(snum2);
		double res = 0;
		
		if (ev.getSource() == jbtClear)
		{
			jtfNum1.setText("");
			jtfNum2.setText("");
			jtfRes.setText("");
			return;
		}
		
		else if (ev.getSource() == jbtAdd)
		{
			res = num1 + num2;
			jtfRes.setText("" + res);
		}
		
		else if (ev.getSource() == jbtSub)
		{
			res = num1 - num2;
			jtfRes.setText("" + res);
		}
		
		else if (ev.getSource() == jbtMult)
		{
			res = num1 * num2;
			jtfRes.setText("" + res);
		}
		
		else if (ev.getSource() == jbtDiv)
		{
			res = num1 / num2;
			jtfRes.setText("" + res);
		}
	}
}
