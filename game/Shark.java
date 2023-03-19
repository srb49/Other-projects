package G23;

import java.awt.Image;
import java.awt.Rectangle;
import java.util.Random;

import javax.swing.ImageIcon;

public class Shark {
	
	int x,y;
	Image img;
	boolean a;
	public Shark(int x,int y)
	{
		this.x=x;
		this.y=y;
		img=new ImageIcon(getClass().getResource("/still/sh1.png")).getImage();
		a=true;
	}
	
	public int getX()
	{
		return x;
	}
	
	public int getY()
	{
		return y;
	}
	public Image getImage()
	{
		return img;
	}
	public boolean visible()
	{
		return a;
	}
	public void move(int rf)
	{
		if(a==true)
			if(rf>=1)
			{
				x=x-8;
			}
			else
				x=x-2;
	}
	public Rectangle area()
	{
		return new Rectangle(this.getX(),this.getY(),450,227);
	}
	public void print()
	{
		System.out.println(x+","+y);
	}
	public void generate(int yy)
	{
		
		int maxY=yy-200;
		Random rand=new Random();
		
		y=rand.nextInt(maxY-50)+50;
		
	}
}
