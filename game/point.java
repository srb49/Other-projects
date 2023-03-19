package G23;

import java.awt.Image;
import java.awt.Rectangle;
import java.util.Random;

import javax.swing.ImageIcon;

public class point {
	
	public int x,y,minX,maxX,minY,maxY;
	Image[] img;
	Image img1;
	boolean vis;
	public point(int x1,int y1)
	{
		this.minX=100;
		this.maxX=x1;
		this.minY=50;
		this.maxY=y1;
		Random rand=new Random();
		x=rand.nextInt(maxX-minX)+minX;
		y=rand.nextInt(maxY-minY)+minY;
		vis=true;
		//img1=new ImageIcon(getClass().getResource("/still/p3.gif")).getImage();
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
		return img1;
	}
	public boolean visible()
	{
		return vis;
	}
	public Rectangle area()
	{
		return new Rectangle(x,y,80,80);
	}
	public void move()
	{
		x=x-5;
	}
	public void generate(int xx,int yy)
	{
		maxX=xx-300;
		maxY=yy-100;
		Random rand=new Random();
		x=rand.nextInt(maxX-minX)+minX;
		Random rand1=new Random();
		y=rand1.nextInt(maxY-minY)+minY;
		int i;
		i=rand.nextInt(10-1)+1;
		if(i>=1&&i<=5)
			img1=new ImageIcon(getClass().getResource("/point/p"+i+".png")).getImage();
		else 
			img1=new ImageIcon(getClass().getResource("/point/p"+i+".gif")).getImage();	
	}

}
