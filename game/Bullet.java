package G23;

import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.Rectangle;

import javax.swing.ImageIcon;

public class Bullet {

	int x,y,l;
	Image bullet;
	boolean v;
	
	public Bullet(int x,int y,int limit)
	{
		this.x=x;
		this.y=y;
		bullet=new ImageIcon(getClass().getResource("/still/b2.png")).getImage();
		v=true;
		this.l=limit;
	}
	
	public void move()
	{
		
			if(x<=l)
			{	
				x=x+5;
				
			}
			else
				v=false;
	
		
	}
	public void draw(Graphics2D g) {
		g.drawImage(this.getImage(),this.getX(),this.getY(),null);
		
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
             return bullet;
     }

	public boolean getVisible() {
		// TODO Auto-generated method stub
		return v;
	}
	public Rectangle area()
	{
		return new Rectangle(x,y,20,20);
	}
    
}
