//as14
//Richard Xie
//cs255

package as14;

import java.awt.Color;
import java.awt.Graphics;

import javax.swing.JFrame;

public class JFrameExt extends JFrame
{
	private int north;
	private int south;
	private int east;
	private int west;
	private int midWest;
	
	public JFrameExt(int north, int south, int east, int west, int midWest)
	{
		super();
		this.north = north;
		this.south = south;
		this.east = east;
		this.west = west;
		this.midWest = midWest;
	}
	
    @Override
	public void paint(Graphics g)
	{
    	double total = north + south + east + west + midWest;
    	int startAngle = 0;
    	int arcLength = 0;

		g.setColor(Color.red);
		startAngle = 0;
		arcLength = (int)(north / total * 360);
		g.fillArc(50, 50, 400, 400, startAngle, arcLength);
		
		g.setColor(Color.green);
		startAngle = startAngle + arcLength;
		arcLength = (int)(south / total * 360);
		g.fillArc(50, 50, 400, 400, startAngle, arcLength);
		
		g.setColor(Color.blue);
		startAngle = startAngle + arcLength;
		arcLength = (int)(east / total * 360);
		g.fillArc(50, 50, 400, 400, startAngle, arcLength);
		
		g.setColor(Color.magenta);
		startAngle = startAngle + arcLength;
		arcLength = (int)(west / total * 360);
		g.fillArc(50, 50, 400, 400, startAngle, arcLength);
		
		g.setColor(Color.yellow);
		startAngle = startAngle + arcLength;
		arcLength = (int)(midWest / total * 360);
		g.fillArc(50, 50, 400, 400, startAngle, arcLength);
		
		g.setColor(Color.red);
	    g.fillRect(30, 500, 20, 10);
	    g.drawString("North - 20.0", 55, 510);
	    g.setColor(Color.green);
	    g.fillRect(30, 515, 20, 10);
	    g.drawString("South - 25.0", 55, 525);
	    g.setColor(Color.blue);
	    g.fillRect(30, 530, 20, 10);
	    g.drawString("East - 15.0", 55, 540);
	    g.setColor(Color.magenta);
	    g.fillRect(30, 545, 20, 10);
	    g.drawString("West - 30.0", 55, 555);
	    g.setColor(Color.yellow);
	    g.fillRect(30, 560, 20, 10);
	    g.drawString("MidWest - 10.0", 55, 570);
	}
}

package as14;

public class Main
{
	public static void main(String[] args)
	{
		JFrameExt f = new JFrameExt(20, 25, 15, 30, 10);
		f.setSize(800,800);
		f.setVisible(true);
	}
}
