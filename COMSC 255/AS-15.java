//as15
//Richard Xie
//cs255

package as15;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;


public class JFrameExt extends JFrame implements ActionListener
{
	private JPanelExt jpe = new JPanelExt();
	private JPanel jp = new JPanel();
	private JPanel jpMain = new JPanel();
	private JButton jbtHappy = new JButton("Happy");
	private JButton jbtSad = new JButton("Sad");
	private JButton jbtPicture = new JButton("Picture");
	
	public JFrameExt()
	{
		jp.setBackground(Color.magenta);
		jpe.setBackground(Color.yellow);
		this.setContentPane(jpMain);
		BorderLayout bl = new BorderLayout();
		jpMain.setLayout(bl);
		jpMain.add(jpe, BorderLayout.CENTER);
		jpMain.add(jp, BorderLayout.SOUTH);
		jp.add(jbtHappy);
		jp.add(jbtSad);
		jp.add(jbtPicture);
		// register with button
		jbtHappy.addActionListener(this);
		jbtSad.addActionListener(this);
		jbtPicture.addActionListener(this);
	}

	@Override
	public void actionPerformed(ActionEvent e)
	{
		if (e.getSource() == jbtHappy)
		{
			jpe.setPicType("Happy");
		}
		
		else if (e.getSource() == jbtSad)
		{
			jpe.setPicType("Sad");
		}
		
		else if (e.getSource() == jbtPicture)
		{
			jpe.setPicType("Picture");
		}
	}
}

package as15;

import java.awt.Color;
import java.awt.Image;
import java.awt.Graphics;
import javax.swing.ImageIcon;
import javax.swing.JPanel;

public class JPanelExt extends JPanel
{
	private String picType = "Happy";
	
	public JPanelExt()
	{
		
	}
	
	@Override
	public void paintComponent(Graphics g)
	{
		super.paintComponent(g);
		if(picType.equalsIgnoreCase("happy"))
		{
			g.drawOval(0,0,100,100);
		    g.fillOval(25,25,10,10);
		    g.fillOval(65,25,10,10);
		    g.drawArc(25,25,50,50,0,-180);
		}
		
		else if(picType.equalsIgnoreCase("sad"))
		{
			g.drawOval(0,0,100,100);
		    g.fillOval(25,25,10,10);
		    g.fillOval(65,25,10,10);
		    g.drawArc(25,50,50,50,0,180);
		}
		
		else if(picType.equalsIgnoreCase("picture"))
		{
			ImageIcon imageIcon = new ImageIcon ("gif.gif");
	        Image image = imageIcon.getImage( ); 
			g.drawImage (image,0,0,this); //where g is a Graphics object
		}
	}
	
	public void setPicType (String picType)
	{
		this.picType = picType;
		repaint();
	}
}

package as15;

public class Main
{
	public static void main(String[] args)
	{
		JFrameExt f = new JFrameExt();
		f.setSize(800,800);
		f.setVisible(true);
	}
}
